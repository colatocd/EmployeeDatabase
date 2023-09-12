# Employee-DataBase
## Makefile 
### Description 
This is a C program consisting of two source code files, 'cmsc257-p2.c' and 'p2-support.c', as well as a Makefile used to compile the program. 

### Requirements 
To build and run this program, you will need:

- A C compiler (such as 'gcc')
- 'make'

### Usage 
To build the program, run the following command:
```
make
```
This will compile the program using the 'gcc' compiler and create an executable file named 'p2'.

To run the program, use the following command:
```
./p2
```
To clean up the program, use the following command:

```
make clean 
```
This will remove the 'p2' executable as well as any object files created during compilation.

## p2-support.h
### Description
This project contains a header file 'p2-support.h' which contains several functions to manage an employee database.

### Requirements 
This code requires 'stdio.h' library to run.

### Usage
This header file can be included in a C project to manage an employee database. The available functions are:

- 'initialize(dataBase_ptr)' - This function creates an array in the database and initializes each array element with the data in the given file.
- 'create_record(char*, char*, char*, char*, double, struct date, dataBase_ptr)' - This function creates a brand new employee record and stores it inside the database.
- 'print_title()' - This function prints the employee title header.
- 'display_menu(dataBase_ptr)': This function displays the menu for the user to interact with and change the employee database.
- 'sort_by_id(struct DataBase *db)': This function sorts employee records by ID numbers from lowest to highest.
- 'sort_by_date(struct DataBase *db)': This function sorts employee records by hire date from lowest to highest.
- 'search_by_id(struct DataBase *db)': This function displays the employee with the given ID from the user input.
- 'search_by_last(struct DataBase *db)': This function searches the database by last name and displays employee(s) partially or completely matching with the given string.
- 'save(struct DataBase *db)': This function saves the database to a text file.
- 'delete_by_id(struct DataBase *db)': This function deletes one employee record with the matching ID from user input from the list.
- 'display_all_records(struct DataBase *db)': This function displays the records of all employees that are within the database.
- 'cmpfunc_id(const void* a, const void* b)': This function is a compare function which is used for the qsort of sorting the employees by ID.
- 'cmpfunc_date(const void* a, const void* b)': This function is a compare function which is used for the qsort of sorting the employees by hire date.

To use these functions, include this header file in your project and call the functions with appropriate parameters.

## p2-support.c
### Description 
This project implements a simple employee database system. The database system can store employee information, such as ID, first name, last name, email, salary, and hire date. It provides several functionalities, such as adding a new employee, printing the database, saving the database to a text file, sorting the database by ID or hire date, and searching for an employee by ID.

### Requirements 
- C compiler
- C standard library
- 'p2-support.h' header file


### Usage
1. Download the 'p2-support.h' header file and put it in the same directory as the main program file.
2. Compile the program with a C compiler.
3. Run the compiled program in a terminal or console.
4. Follow the instructions provided by the program.


## Credits 
This project was created by Cesar Colato
