#include "student.h"
#include "input.h"
#include <stdio.h>
#include <string.h>
void printStudent(Student data){
    printf("Student Number %d: \n",data.seatNo);
    printf("\tName: %s %s\n",data.FirstName,data.LastName);
    printf("\tGrade: %d\n",data.grade);
}
void saveStudent(Student data,FILE *database){
    fprintf(database,"Student Seat No.: %d\n",data.seatNo);
    fprintf(database,"Student Grade.: %d\n",data.grade);
    fprintf(database,"Student First Name: %s\n",data.FirstName);
    fprintf(database,"Student Last Name.: %s\n",data.LastName);
    fprintf(database,"----\n");
}
Student StudentConstructor(){
    Student temp;
    int grade = -1,seatNo = -1;
    char buffer[100];
    buffer[0] = '\0';
    while(seatNo == -1){

        printf("Enter Student Seat No.: \n");
        seatNo = getUnsignedInteger();
    }
    temp.seatNo = seatNo;
    while(grade == -1){
        printf("Enter Student Grade: \n");
        grade = getUnsignedInteger();
        if(grade > 100){
            grade = -1;
            printf("Enter a grade between 0 to 100\n");
        }
    }
    temp.grade = grade;
    while(buffer[0] == '\0'){
        printf("Enter Student First Name: \n");
        GetName(buffer);
    }
    strcpy(temp.FirstName,buffer);
    buffer[0] = '\0';
    while(buffer[0] == '\0'){
        printf("Enter Student Last Name: \n");
        GetName(buffer);
    }
    strcpy(temp.LastName,buffer);
    return temp;
}
