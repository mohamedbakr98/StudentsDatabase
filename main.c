#include <stdio.h>
#include <conio.h>
#include "mainFunctions.h"
#include "student.h"
#include "input.h"
#include "linkedlist.h"
int main()
{
    exitProgram = 1;
    FILE *database = fopen("database.txt","a");
    welcome();
    getch();
    frame_one();
    while(exitProgram){
        input();
    }
    saveListToFile(head,database);
    fclose(database);
    return 0;
}
