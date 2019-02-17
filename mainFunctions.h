#ifndef MAINFUNCTIONS_H_INCLUDED
#define MAINFUNCTIONS_H_INCLUDED
#include "student.h"
#include "linkedlist.h"
#include "input.h"
#define SET_STUDENT_NUMBER 0
#define ENTER_STUDENT_DATA 1
#define SEE_STUDENTS_DATA 2
#define MODIFY_STUDENT_DATA 3
#define DELETE_STUDENT 4
#define SEARCH_BY_ROLL_NUMBER 5
#define EXIT 6
#define NUMBER_OF_OPTIONS 7

/// variables:
int exitProgram;
char *optionsForwardArrow[NUMBER_OF_OPTIONS];
char *optionsList[NUMBER_OF_OPTIONS];
int i;
int deleted[NUMBER_OF_OPTIONS];
int deletedIterator;
int arrowY;
int numberOfStudents;
Node* head ;
int alreadyEntered ;

/// functions:
void setOptionArrow();
void frame_one();
void input();
void logic();
int EnterNumberOfStudents();
void EnterStudentsData();
void ShowStudentsData();
void modifyStudentsData();
void deleteStudent();
void searchByRollNumber();
void addToDelete(int d);
void welcome();
void printForwardArrow(int optionNumber);
void printOptions();

#endif // MAINFUNCTIONS_H_INCLUDED
