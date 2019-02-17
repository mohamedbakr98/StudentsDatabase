#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include "student.h"
#include <stdio.h>
#include <windows.h>

typedef struct node{
    Student data;
    struct node* next;
}Node;

Node* create(Student data,Node* next);
Node* prepend(Student data,Node* head);
void printList(Node* node);
Node* search(Node* head, int SeatNo);
Node* remove_front(Node* head);
Node* remove_back(Node* head);
Node* deleteNode(Node* head,Node* nd);
void MergeSort(Node** headRef);
Node* SortedMerge(Node* a, Node* b);
void FrontBackSplit(Node* source, Node** frontRef, Node** backRef);
void saveListToFile(Node* head,FILE* database);
#endif // LINKEDLIST_H_INCLUDED
