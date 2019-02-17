/// main functions definitions:
void setOptionArrow(){
    int i;
    for(i = 0; i < NUMBER_OF_OPTIONS ;i++){
        options[i] = "\0";
    }
    options[arrowY] = "-->";
}
void frame_one(){
    system("cls");
    setOptionArrow();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    printf("Welcome to student records, Choose your option:\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
    printf("%s",options[0]);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    printf("1. Number Of Students.\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
    printf("%s",options[1]);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    printf("2. Enter students data.\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
    printf("%s",options[2]);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    printf("3. See students data.\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
    printf("%s",options[3]);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    printf("4. Modify student data.\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
    printf("%s",options[4]);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    printf("5. Delete Student.\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
    printf("%s",options[5]);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    printf("6. Search by roll number.\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
    printf("%s",options[6]);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    printf("7. Exit\n");
}
void input(){
    if(_kbhit()){
        switch(getch()){
        case 'w':
            if(arrowY >  0){
                arrowY--;
            }else{
                arrowY = NUMBER_OF_OPTIONS - 1;
            }
            frame_one();
            break;
        case 's':
            if(arrowY < NUMBER_OF_OPTIONS - 1){
                arrowY++;
            }else{
                arrowY = 0;
            }
            frame_one();
            break;
        case 13:
            logic();
            fflush(stdin);
            break;
        case 27:
            frame_one();
            break;
        }
    }
}
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
        exit(0);
        break;
    default:
        break;
    }

}
int EnterNumberOfStudents(){
    if(alreadyEntered == 0){
        printf("Enter Number Of Students:\n");
        int firstTime = 1;
        while(numberOfStudents == -1){
            if(firstTime){
                firstTime = 0;
            }else{
                printf("Wrong input...Please enter an non negative integer\n");
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
void EnterStudentsData(){
    if(numberOfStudents > 0){
        int i;
        printf("Enter the data one by one:\n");
        for(i = 0 ; i < numberOfStudents ;i++){
            printf("Enter student %d data:\n",i);
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
void modifyStudentsData(){
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
    printf("press any key to return to the main menu.\n");
    getch();
    frame_one();
}

void deleteStudent(){
    printf("Enter the seat No. of the student you want to delete:\n");
    int seatNumber = -1;
    while(seatNumber == -1)
    {
        printf("Enter the seat number of the student:\n");
        seatNumber = getUnsignedInteger();
        if(seatNumber == -1){
            printf("please enter a valid seat number.");
        }
    }
    deleteNode(head,seatNumber);
    printf("press any key to go back to main menu.\n");
    getch();
    frame_one();
}
void searchByRollNumber(){
    printf("Enter the seat Number for the Student:\n");
    int seatNumber = -1;
    while(seatNumber == -1){
        printf("Enter the seat number of the student:\n");
        seatNumber = getUnsignedInteger();
        if(seatNumber == -1){
            printf("please enter a valid seat number.\n");
        }
    }
    Node* foundNode = search(head,seatNumber);
    if(foundNode == NULL){
        printf("Not found.\n");
    }else{
        printStudents(foundNode->data);
    }
    printf("Press any key to go back to main menu.\n");
    getch();
    frame_one();
}
