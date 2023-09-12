////////////////////////////////////////////////////////////////////////
////
//// File           : p2-support.c
//// Description    : Source file for project2 
//// Author         : ***Cesar Colato***
//// Date           : ***3/31/2023***
//// Notes          : ***N/A

#define _GNU_SOURCE		//strcasestr is a nonstandard GNU extension, 
//we need this line while serching for matching last name
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "p2-support.h"


void create_record (char* ID, char* first_name, char* last_name, char* email, double salary, struct date hire_date, struct DataBase* db)// specify parameters. Clues are in the initalize function.
{
	//define function. Clues are in the initalize function
	//do not forget to increase total number of employees in the database
	strcpy(db->emp[db->total].ID, ID);
	strcpy(db->emp[db->total].first_name, first_name);
	strcpy(db->emp[db->total].last_name, last_name);
	strcpy(db->emp[db->total].email, email);
	db->emp[db->total].salary = salary;
	db->emp[db->total].hire_date = hire_date;
	db->total++;

}
void print_title ()// you can keep this fuction or remove if needed
{
	printf ("No. ID    Name          Email        Salary     Hire Date\n");
	printf ("--- ----- ------------- ------------ ---------- --/--/----\n");
}


//fix save function. Save array into file: database_updated in the same format with the 
//database file.
void save (dataBase_ptr db)// this function is for saving the database into a text file
{
	FILE *dbfu;
	int i;
	dbfu = fopen ("database_updated", "w");//open an Std IO file to write into
	if (dbfu == NULL)
	{
		printf ("File cannot be created");
		return;
	}
	for (i = 0; i < db->total; i++)
	{
		//add format specifiers here , db->emp[i].ID, //add other members);
		fprintf (dbfu, "%-s %-s %-s %-s %.2lf %d/%d/%4d\n", db->emp[i].ID, db->emp[i].first_name, db->emp[i].last_name, db->emp[i].email, db->emp[i].salary, db->emp[i].hire_date.month, db->emp[i].hire_date.day, db->emp[i].hire_date.year);

		//sscanf (line, "%s %s %s %s %lf %d/%d/%d\n", ID, first_name, last_name, email, &salary, &hire_date.month, &hire_date.day, &hire_date.year);

	}

	fclose (dbfu);//close file after writing
	return;

}

int cmpstr(const void* a, const void* b){
	struct Employee* aa = (struct Employee*)a;
	struct Employee* bb = (struct Employee*)b;
	return atoi(aa->ID) > atoi(bb->ID); 
}

void sort_By_ID(struct DataBase *db){
	qsort(&db->emp[0], db->total, sizeof(struct Employee), cmpstr);  
}

int compDate(const void* a, const void* b){
	struct Employee* emp1 = (struct Employee*)a;
	struct Employee* emp2 = (struct Employee*)b;
	if (emp1->hire_date.year < emp2->hire_date.year) {
		return -1;
	} else if (emp1->hire_date.year > emp2->hire_date.year) {
		return 1;
	} else if (emp1->hire_date.month < emp2->hire_date.month) {
		return -1;
	} else if (emp1->hire_date.month > emp2->hire_date.month) {
		return 1;
	} else if (emp1->hire_date.day < emp2->hire_date.day) {
		return -1;
	} else if (emp1->hire_date.day > emp2->hire_date.day) {
		return 1;
	} else {
		return 0;
	}
}

void sort_By_HireDate(struct DataBase *db){
	qsort(&db->emp[0], db->total, sizeof(struct Employee), compDate);
}


void display_employees(struct DataBase *db){
	//set up column widths
	const int name_width = 13;
	int i;

	print_title();
	//loop through employee data and print each row
	for (i = 0; i < db->total; i++) {
		//extract employee data from the database
		char* id = db->emp[i].ID;
		char* first_name = db->emp[i].first_name;
		char* last_name = db->emp[i].last_name;
		char* email = db->emp[i].email;
		double salary = db->emp[i].salary;
		struct date hire_date = db->emp[i].hire_date;

		//format the employee name column to fit within the specified width	
		char name[name_width];
		char trunc[14];
		memset(name, '\0', sizeof(name));
		//combine first and last name, truncating to 13 characters
		strcat(name, first_name);
		strcat(name, " ");
		strcat(name, last_name);
		strncpy(trunc, name, 13);
		trunc[13] = '\0';

		//print the employee row, formatted to fit within the specified column widths
		printf("%-3d %-5s %-13s %-12.12s $%9.2lf %02d/%02d/%4d\n", i, id, trunc, email, salary,hire_date.month, hire_date.day, hire_date.year);
	}
}


void display_employee_by_id(struct DataBase* db){
	int input;
	int i, found = 0;
	char name[13];
	char trunc[14];
	char* id;
	char* first_name;
	char* last_name;
	char* email;
	double salary;
	struct date hire_date;
	memset(name, '\0', sizeof(name));
	printf("Enter the ID you are searching for\n");
	scanf("%d", &input);

	for (i = 0; i < db->total; i++){
		id = db->emp[i].ID;
		first_name = db->emp[i].first_name;
		last_name = db->emp[i].last_name;
		email = db->emp[i].email;
		salary = db->emp[i].salary;
		hire_date = db->emp[i].hire_date;
		if (atoi (db->emp[i].ID) == input) {
			found = 1;
			strcat(name, first_name);
			strcat(name, " ");
			strcat(name, last_name);
			strncpy(trunc, name, 13);
			trunc[13] = '\0';
			break;
		}
	}
	if (found) {
		print_title();
		printf("%-3d %-5s %-13s %-12.12s $%9.2lf %02d/%02d/%4d\n", i, id, trunc, email, salary,hire_date.month, hire_date.day, hire_date.year);

	} else {
		printf("No employee with ID %d exists in the database.\n", input);
	}
}

void display_employees_by_lastName(struct DataBase* db){
	char input[14];
	int i, count = 0;
	char name[13];
	char trunc[14];
	char* id;
	char* first_name;
	char* last_name;
	char* email;
	double salary;
	struct date hire_date;
	memset(name, '\0', sizeof(name));
	printf("Enter the Last Name you are searching for\n");
	scanf("%s", input);

	print_title();
	for(i = 0; i < db->total; i++){
		id = db->emp[i].ID;
		first_name = db->emp[i].first_name;
		last_name = db->emp[i].last_name;
		email = db->emp[i].email;
		salary = db->emp[i].salary;
		hire_date = db->emp[i].hire_date;
		if(strcasestr(db->emp[i].last_name, input) != NULL){
			count++;
			memset(name, '\0', sizeof(name));
			strcat(name, first_name);
			strcat(name, " ");
			strcat(name, last_name);
			strncpy(trunc, name, 13);
			trunc[13] = '\0';
			printf("%-3d %-5s %-13s %-12.12s $%9.2lf %02d/%02d/%4d\n", i, id, trunc, email, salary,hire_date.month, hire_date.day, hire_date.year);		

		}
}
	if(count == 0){
		printf("No employees found with that last name.\n");
		return;
	}
}


void delete_record(struct DataBase* db) {
	int input, i, j;
	char name[13];
	char trunc[14];
	char* id;
	char* first_name;
	char* last_name;
	char* email;
	double salary;
	struct date hire_date;
	memset(name, '\0', sizeof(name));

	printf("Enter the ID you are searching for\n");
	scanf("%d", &input);
	for (i = 0; i < db->total; i++) {
		id = db->emp[i].ID;
		first_name = db->emp[i].first_name;
		last_name = db->emp[i].last_name;
		email = db->emp[i].email;
		salary = db->emp[i].salary;
		hire_date = db->emp[i].hire_date; 
		if (atoi (db->emp[i].ID) == input) {
			strcat(name, first_name);
			strcat(name, " ");
			strcat(name, last_name);
			strncpy(trunc, name, 13);
			trunc[13] = '\0';

			printf("The following employee is deleted:\n");
			print_title();
			printf("%-3d %-5s %-13s %-12.12s $%9.2lf %02d/%02d/%4d\n", i, id, trunc, email, salary,hire_date.month, hire_date.day, hire_date.year);


			for (j = i; j < db->total - 1; j++) {
				db->emp[j] = db->emp[j + 1];
			}
			db->total--;
			return;
		}
	}
	printf("Record with ID %d not found in database.\n", input);
}






void display_menu (struct DataBase *db)
{
	int input = 0;
	while (input != 8)
	{
		puts
			("\n**************************************************************");
		printf
			(  "********** Employee Database - Total Employees: %03d **********\n",
			   db->total);//you need to fix this line so that total employees in the database is printed
		puts
			("**************************************************************\n");
		puts ("Choose one of the menu options below:");
		puts ("1. Sort by ID");
		puts ("2. Sort by Hire Date");
		puts ("3. Display all employees");
		puts ("4. Search employees by ID");
		puts ("5. Search employees by Last Name");
		puts ("6. Delete employee by ID");
		puts ("7. Save");
		puts ("8. Exit");

		scanf ("%d", &input);

		switch (input)
		{
			case 1:
				//call the function you defined for sorting by ID
				sort_By_ID(db);
				break;
			case 2:
				//call the function you defined for sorting by Hire Date
				sort_By_HireDate(db);
				break;
			case 3:
				//call the function you defined for displaying employees
				display_employees(db);
				break;
			case 4:
				//call the function you defined for searching employees by ID
				display_employee_by_id(db);
				break;
			case 5:
				//call the function you defined for searching employees by Last Name
				display_employees_by_lastName(db);
				break;
			case 6:
				//call the function you defined for deleting employee by ID
				delete_record(db);
				break;
			case 7:
				save (db);
				break;
			case 8:
				//free all allocated memory
				printf("Bye!\n");
				free(db->emp);
				free(db);
				break;

		}
	}

}
