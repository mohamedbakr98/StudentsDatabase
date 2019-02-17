#include <conio.h>
#include "mainFunctions.h"
#include "student.h"
#include "linkedlist.h"
#include "input.h"
/*
 * Function:  gotoxy
 * --------------------
 * Moves the cursor to a particular position in the console.
 *
 * Arguments: x and y position you want to move the cursor to.
 *
 */
int exitProgram = 1;
char *optionsForwardArrow[NUMBER_OF_OPTIONS];
char *optionsList[NUMBER_OF_OPTIONS] = {
        "1. Number Of Students.\n",
        "2. Enter students data.\n",
        "3. See students data.\n",
        "4. Modify student data.\n",
        "5. Delete Student.\n",
        "6. Search by roll number.\n",
        "7. Exit\n"
};
int i = 0;
int deleted[NUMBER_OF_OPTIONS] = {0};
int deletedIterator = 0;
int arrowY = 0;
int numberOfStudents = -1;
Node* head = NULL;
int alreadyEntered = 0;
void gotoxy_m(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
/*
 * Function:  setOptionArrow
 * --------------------
 * sets every string in the optionsForwardArrow strings array to null except
 * that matches the index of arrowY sets it to "-->"
 * Arguments: void
 *
 */
void setOptionArrow(){
    int i;
    for(i = 0; i < NUMBER_OF_OPTIONS ;i++){
        optionsForwardArrow[i] = "\0";
    }
    optionsForwardArrow[arrowY] = "-->";
}
/*
 * Function:  printForwardArrow
 * --------------------
 * takes in the option number that you want to print and prints it by setting the color to red printing the values
 *
 * corresponding to the option number in the optionsForwardArrow strings array then it resets the text color back to yellow
 *
 * Arguments: optionNumber
 *
 */
void printForwardArrow(int optionNumber){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
    printf("%s",optionsForwardArrow[optionNumber]);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
}
/*
 * Function:  printOptions
 * --------------------
 * Iterates over the options first passing the number to the printForwardArrow function to print the value corresponding to the number
 *
 * this sets the text color to yellow this prints the option corresponding to the number i in the optionsList array.
 *
 * Arguments: void
 *
 */
void printOptions(){
    int i;
    for(i = 0 ; i < NUMBER_OF_OPTIONS ; i++){
        gotoxy_m(32,9+i);
        printForwardArrow(i);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
        printf("%s",optionsList[i]);
    }
}

void welcome(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
    gotoxy_m(32,12);
    printf("---------->");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
    printf("Welcome press any key to begin");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
    printf("<----------");


}
/*
 * Function:  frame_one
 * --------------------
 * first it clears the screen. then uses the setOptionArrow function to set the arrow to the right position
 *
 * prints the head of the options list then uses the printOptions function
 *
 * Arguments: void
 *
 */
void frame_one(){
    system("cls");
    setOptionArrow();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
    gotoxy_m(32,8);
    printf("Welcome to student records, Choose your option:\n");
    printOptions();
}
/*
 * Function:  input
 * --------------------
 * the _kbhit() function is used from the windows API to detect that the keyboard is hit.
 * this we take the character that been hit by the user and switching it
 *         if it's 'w' the arrowY is
 *               greater than 0 then we decrement it's value
 *               equals zero we set the value of arrow to NUMBER_OF_OPTIONS -1.
 *         if it's 's' the reverse happens.
 *            and after that print the first frame all over again (menu).
 *         if it's ENTER we use the logic function
 *         if it's ESCAPE we return to the first frame (menu).
 *
 */

void input(){
    if(_kbhit()){
        int c1 = getch();
        if(c1 == 224){
            int c2 = getch();
            if(c2 == 72){
            if(arrowY >  0){
                    arrowY--;
            }else{
                arrowY = NUMBER_OF_OPTIONS - 1;
            }
            frame_one();
        }else if(c2 == 80){
            if(arrowY < NUMBER_OF_OPTIONS - 1){
                    arrowY++;
            }else{
                arrowY = 0;
            }
            frame_one();
            }
        }else if(c1 == 13){
            logic();
            fflush(stdin);
        }else if(c1 == 27){
            frame_one();
        }
    }
}

/*
 * Function:  logic
 * --------------------
 * this function switches the arrowY variable to figure out which option was selected .
 *
 * then runs the function corresponding to that choice.
 *
 * after running each we wait until the user hits any key to go back to first frame.
 * Arguments: void
 *
 */
void logic(){
    system("cls");
    switch(arrowY){
    case SET_STUDENT_NUMBER:
       EnterNumberOfStudents();
       frame_one();
        break;
    case ENTER_STUDENT_DATA:
        EnterStudentsData();
        break;
    case SEE_STUDENTS_DATA:
        ShowStudentsData();
        break;
    case MODIFY_STUDENT_DATA:
        modifyStudentsData();
        break;
    case DELETE_STUDENT:
        deleteStudent();
        break;
    case SEARCH_BY_ROLL_NUMBER:
        searchByRollNumber();
        break;
    case EXIT:
//        saveListToFile(head,);
        exitProgram = 0;
        break;
    default:
        break;
    }

}
/*
 * Function:  EnterNumberOfStudents
 * --------------------
 * Uses the function getUnsignedInteger() to get it's input and then it goes into an infinite loop until the user enter a valid number.
 *
 * Arguments: void
 *
 */
int EnterNumberOfStudents(){
    if(alreadyEntered == 0){
        printf("Enter Number Of Students:\n");
        int firstTime = 0;
        while(numberOfStudents == -1){
            if(firstTime){
                system("cls");
                gotoxy_m(32,8);
                printf("Enter Number Of Students:\n");
                gotoxy_m(32,9);
                printf("Wrong input...Please enter an non negative integer\n");
                gotoxy_m(32,10);
            }else{
                system("cls");
                gotoxy_m(32,8);
                printf("Enter Number Of Students:\n");
                gotoxy_m(32,9);
                firstTime = 1;
            }
            numberOfStudents = getUnsignedInteger();
            alreadyEntered = 1;
            fflush(stdin);
        }
    }else{
        printf("You've already entered the number of students press any key to go back");
        getch();
    }
    return numberOfStudents;
}
/*
 * Function:  EnterStudentsData
 * --------------------
 * First checks if
 *          numberOfStudents is greater than zero then
 *               it goes into a loop  NUMBEROFSTUDENTS times and takes each student data
 *               and after that pushes this data to the front of the linked list of student
 *
 *          numberOfStudents is equal to zero then it prompts the user. waits for any keyboard hit and then goes to the first frame again.
 *
 * Arguments: void
 *
 */
void EnterStudentsData(){
    if(numberOfStudents > 0){
        int i;
        system("cls");
        printf("Enter the data one by one:\n");
        for(i = 0 ; i < numberOfStudents ;i++){
            printf("Enter student %d data:\n",i+1);
            Student temp = StudentConstructor();
            head = prepend(temp,head);
        }
        frame_one();
    }else{
        printf("You haven't entered the number of students.");
        getch();
        frame_one();
    }

}
/*
 * Function:  ShowStudentData
 * --------------------
 * Checks if number of students is greater than zero then it sorts the linked list using merge sort
 *
 * after that if prints the linked list using the printList function.
 *
 * Arguments: void
 *
 */
void ShowStudentsData(){
    if(numberOfStudents > 0){
        printf("Showing all students sorted by the seat number:\n");
        MergeSort(&head);
        printList(head);

    }else{
        printf("You haven't entered the students data yet.\n");
    }
    printf("Press any key to go back to the main menu.\n");
    getch();
    frame_one();
}
/*
 * Function:  modifyStudentsData
 * --------------------
 * checks numberOfStudentsData is greater than zero after that  it takes in the seatNumber the user want to search for
 *
 * after that we take that number and search in the linked list using the search function
 *
 * that function return that node if it's NULL then it's note found it prompts that to the user.
 *
 * if node we use the StudentConstructor function to and we change the data at that node with the new data.
 *
 * after that if prints the linked list using the printList function.
 *
 * Arguments: void
 *
 */
void modifyStudentsData(){
    if(numberOfStudents > 0){
        int seatNumber = -1;
        while(seatNumber == -1){
            printf("Enter the seat number of the student:\n");
            seatNumber = getUnsignedInteger();
            if(seatNumber == -1){
                printf("please enter a valid seat number.");
            }
        }
        Node* foundNode = search(head,seatNumber);
        if(foundNode == NULL){
            printf("Not found in the archive.\n");
        }else{
            printf("Re-enter the student data:\n");
            Student temp = StudentConstructor();
            foundNode->data = temp;
        }
    }else{
        printf("There are no students in the archive for you to modify.\n");
    }
    printf("press any key to return to the main menu.\n");
    getch();
    frame_one();

}
void addToDelete(int d){
    if(deletedIterator < NUMBER_OF_OPTIONS){
        deleted[deletedIterator] = d;
        deletedIterator++;
    }else{
        printf("deleted overflow\n");
    }
}
int searchInDeleted(int d){
    int i;
    for(i = 0 ; i < NUMBER_OF_OPTIONS ; i++){
        if(deleted[i] == d){
            return 1;
        }
    }
    return 0;
}
/*
 * Function:  deleteStudent
 * --------------------
 * We take the seatNumber then search for the node that has that seat number and deletes it
 *
 * Arguments: void
 *
 */

void deleteStudent(){
    int seatNumber = -1;
    while(seatNumber == -1)
    {
        printf("Enter the seat number of the student:\n");
        seatNumber = getUnsignedInteger();
        if(seatNumber == -1){
            printf("please enter a valid seat number.");
        }
    }
    Node* findNode = search(head,seatNumber);
     if(findNode == NULL){
        printf("Student not found.\n");
    }else{
        deleteNode(head,findNode);
        addToDelete(seatNumber);
        numberOfStudents--;
    }
    printf("press any key to go back to main menu.\n");
    getch();
    frame_one();
}
/*
 * Function:  searchByRollNumber
 * --------------------
 * takes the seatNumber then searches for the node after that we print the data using the printStudent function
 *
 * Arguments: void
 *
 */
void searchByRollNumber(){
    int seatNumber = -1;
    while(seatNumber == -1){
        printf("Enter the seat number of the student:\n");
        seatNumber = getUnsignedInteger();
        if(seatNumber == -1){
            printf("please enter a valid seat number.\n");
        }
    }
    if(searchInDeleted(seatNumber) == 1){
        printf("Not found.");
    }else{
        Node* foundNode = search(head,seatNumber);
        if(foundNode == NULL){
            printf("Not found.\n");
        }else{
            printStudent(foundNode->data);
        }
    }
    printf("Press any key to go back to main menu.\n");
    getch();
    frame_one();
}
