#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include <stdio.h>
struct student{
    int seatNo;
    int grade;
    char FirstName[20];
    char LastName[20];
};
typedef struct student Student;
void printStudent(Student data);
Student StudentConstructor();
void saveStudent(Student data,FILE *database);
#endif // STUDENT_H_INCLUDED
