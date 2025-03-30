# Student Database Management System

A C-based student database management system that uses a linked-list data structure to manage student records. The system provides functionality to add, remove, and insert students at runtime, with the ability to sort the database based on seat numbers using merge sort.

## Features

- Add new student records
- Remove existing student records
- Insert student records at specific positions
- Sort students by seat number using merge sort
- Display student information
- Persistent storage using text file
- Input validation and error handling

## Project Structure

```
.
├── main.c              # Main program entry point
├── student.h           # Student structure definition
├── student.c           # Student-related functions
├── linkedlist.h        # Linked list structure definition
├── linkedlist.c        # Linked list operations
├── mainFunctions.h     # Main program function declarations
├── mainFunctions.c     # Main program function implementations
├── input.h            # Input handling declarations
├── input.c            # Input handling implementations
├── functions.c        # Additional utility functions
└── database.txt       # Persistent storage file
```

## Building and Running

To compile and run the program:

1. Make sure you have a C compiler installed (e.g., GCC)
2. Compile the program:
   ```bash
   gcc *.c -o student_database
   ```
3. Run the executable:
   ```bash
   ./student_database
   ```

## Usage

The program provides an interactive menu with the following options:

1. Add a new student
2. Remove a student
3. Insert a student at a specific position
4. Display all students
5. Sort students by seat number
6. Exit

Follow the on-screen prompts to perform the desired operations.

## Data Structure

The program uses a singly linked list to store student records, where each node contains:
- Student name
- Seat number
- Pointer to the next student record

## File Storage

Student records are stored in `database.txt` for persistence between program runs.

## Contributing

Feel free to submit issues and enhancement requests!
