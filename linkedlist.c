#include "linkedlist.h"
#include "student.h"
#include <stdio.h>
#include <windows.h>

Node* create(Student data,Node* next){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = next;
    return temp;
}
Node* prepend(Student data,Node* head){
    Node* new_node = create(data,head);
    head = new_node;
    return head;
}
Node* search(Node* head, int SeatNo)
{
    Node* current = head;  // Initialize current
    while (current != NULL)
    {
        if (current->data.seatNo == SeatNo)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}
void printList(Node* node)
{
  while(node!=NULL)
  {
   printStudent(node->data);
   node = node->next;
  }
}
/// deleting a node:
Node* remove_front(Node* head)
{
    if(head == NULL)
        return NULL;
    Node *front = head;
    head = head->next;
    front->next = NULL;
    /* is this the last node in the list */
    if(front == head)
        head = NULL;
    free(front);
    return head;
}
Node* remove_back(Node* head)
{
    if(head == NULL)
        return NULL;

    Node *cursor = head;
    Node *back = NULL;
    while(cursor->next != NULL)
    {
        back = cursor;
        cursor = cursor->next;
    }
    if(back != NULL)
        back->next = NULL;

    /* if this is the last node in the list*/
    if(cursor == head)
        head = NULL;

    free(cursor);

    return head;
}
Node* deleteNode(Node* head,Node* nd)
{

    /* if the node is the first node */
    if(nd == head)
    {
        head = remove_front(head);
        return head;
    }

    /* if the node is the last node */
    if(nd->next == NULL)
    {
        head = remove_back(head);
        return head;
    }

    /* if the node is in the middle */
    Node* cursor = head;
    while(cursor != NULL)
    {
        if(cursor->next == nd)
            break;
        cursor = cursor->next;
    }

    if(cursor != NULL)
    {
        Node* tmp = cursor->next;
        cursor->next = tmp->next;
        tmp->next = NULL;
        free(tmp);
    }
    return head;
}
void MergeSort(Node** headRef)
{
    Node* head = *headRef;
    Node* a;
    Node* b;

    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }

    FrontBackSplit(head, &a, &b);

    MergeSort(&a);
    MergeSort(&b);

    *headRef = SortedMerge(a, b);
}
Node* SortedMerge(Node* a, Node* b)
{
    Node* result = NULL;

    if (a == NULL)
        return(b);
    else if (b==NULL)
        return(a);

    if (a->data.seatNo <= b->data.seatNo)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return(result);
}
void FrontBackSplit(Node* source,
		Node** frontRef, Node** backRef)
{
    Node* fast;
    Node* slow;
    if (source==NULL || source->next==NULL)
    {
        /* length < 2 cases */
        *frontRef = source;
        *backRef = NULL;
    }
    else
    {
        slow = source;
        fast = source->next;

        /* Advance 'fast' two nodes, and advance 'slow' one node */
        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }

        /* 'slow' is before the midpoint in the list, so split it in two
        at that point. */
        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
    }
}
void saveListToFile(Node* node,FILE* database)
{
  while(node!=NULL)
  {
   saveStudent(node->data,database);
   node = node->next;
  }
}

