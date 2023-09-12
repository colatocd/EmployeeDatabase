////////////////////////////////////////////////////////////////////////
//
// File           : p2-support.h
// Description    : Header file for project2 
// Author         : ***Cesar Colato***
// Date           : ***3/31/2023***
// Notes          : ***N/A

#ifndef P2Header //To prevent double inclusion of header
#define P2Header //To prevent double inclusion of header

#include <stdio.h>
#define byID 1
#define byNAME 2
#define dbSIZE 100
#define idSIZE 6
#define nameSIZE 10
#define emailSIZE 20


typedef struct date// do not modify
{
  int day; 
  int month;
  int year;
}date;

typedef struct Employee
{
  char ID[idSIZE];
  //declare other members
  char first_name[10];
  char last_name[10];
  char email[20];
  double salary;
  struct date hire_date;
  
}employee, *employee_ptr;

typedef struct DataBase
{
  //a pointer to first element of empoloyee array
  struct Employee *emp;
  //number of employees in database
  int total;
}*dataBase_ptr;

// Functional Prototypes

// Function     : initialize
// Description  : This function creates an array in the database
//                then initalializes each array elemet with the data 
//                in the given file
// Inputs       : a pointer to DataBase struct
// Output       : none
void initialize (dataBase_ptr db);

//Write formal comments for each function header. 
//In the same format with the initialize function

// Function     : create_record
// // Description  : This function creates a new employee record with
// //		     the provided information and adds it to the given database.
// //		     It increases the total number of employees in the database after adding the new record.                
// //                
// // Inputs       : a character pointer representing the employee ID
// //		     a character pointer representing the employee's first name
// //		     a character pointer representing the employee's last name
// //		     a character pointer representing the employee's email address
// //		     a double representing the employee's salary
// //		     a struct representing the date the employee was hired
// //		     a pointer to DataBase struct
// // Output       : none
void create_record (char* ID, char* first_name, char* last_name, char* email, double salary, struct date hire_date,struct DataBase* db);//specify parameters types. Clues are in the initalize function.

// Function     : print_title
// // Description  : This function prints the title for the employees to all be printed under
// //                 
// //               
// // Inputs       : a pointer to DataBase struct
// // Output       : none
void print_title ();

// Function     : display_menu
// // Description  : This function displays a menu that allows the user to pick what they want
// //		     to do with the employee data in db.
// //                
// //                
// // Inputs       : a pointer to DataBase struct
// // Output       : none
void display_menu (dataBase_ptr);

//other function headers here

// Function     : cmpstr
// // Description  : A comparator function for sorting Employee structs by their ID field.
// //                
// //                
// // Inputs       : Pointers to two Employee structs (a and b).
// // Output       : Integer value indicating comparison result (-1, 0, or 1).
int cmpstr(const void *a, const void *b);

// Function     : sort_By_ID
// // Description  : This function sorts records with ID numbers from lowest to highest. 
// //                 
// //               
// // Inputs       : a pointer to DataBase struct
// // Output       : none
void sort_By_ID(struct DataBase *db);

// Function     : compDate
// // Description  : A comparator function for sorting Employee structs by their hire_date field
// //                
// // Inputs       : Pointers to two Employee structs (a and b).
// // Output       : Integer value indicating comparison result (-1, 0, or 1).
int compDate(const void* a, const void* b);

// Function     : sort_By_HireDate
// // Description  : This function sorts records with hire date from earliest to most recent.  
// //                 
// //                
// // Inputs       : a pointer to DataBase struct
// // Output       : none
void sort_By_HireDate(struct DataBase *db);

// Function     : display_employees
// // Description  : This function display all records as ordered in the database. 
// //                 
// //                
// // Inputs       : a pointer to DataBase struct
// // Output       : none
void display_employees(struct DataBase *db);

// Function     : display_employee_by_id
// // Description  : This function displays the employee with the given ID.
// //		     Will print a message if an employee with a given ID does not exist.
// //                                
// // Inputs       : a pointer to DataBase struct
// // Output       : none
void display_employee_by_id(struct DataBase* db);

// Function     : display_employees_by_lastName
// // Description  : This function searches the database by last name
// //		     and displays employee(s) partially or completely matching
// //		     with the given string. This option may result in multiple hits,
// //		     for example, there might be more than one entry with the same last name,
// //		     but a different first name.
// //                 
// // Inputs       : a pointer to DataBase struct
// // Output       : none
void display_employees_by_lastName(struct DataBase* db);

// Function     : delete_record
// // Description  : This function deletes one record with the matching ID from the list. Print a message if no match.
// //                 
// //                
// // Inputs       : a pointer to DataBase struct
// // Output       : none
void delete_record(struct DataBase* db);

// Function     : save
// // Description  : This function saves the database to another file named as database_updated.
// //                
// //              
// // Inputs       : a pointer to DataBase struct
// // Output       : none
void save(dataBase_ptr);


#endif //To prevent double inclusion of header
