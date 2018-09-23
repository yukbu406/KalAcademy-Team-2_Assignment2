// EmployeeRecordsApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Database.h"

using namespace std;
using namespace AirlineReservationSystem;

int displayMenu();
void doHire(Database& db);
void doFire(Database& db);
void doPromote(Database& db);
//void doDemote(Database& db);

int main()
{
	/*cout << "Testing the Employee class." << endl;
	Employee emp;
	emp.setFirstName("John");
	emp.setLastName("Doe");
	emp.setEmployeeNumber(71);
	emp.setSalary(50000);
	emp.promote();
	emp.promote(50);
	emp.hire();
	emp.display();*/

	/*Database myDB;

	Employee& emp1 = myDB.addEmployee("Greg", "Wallis");
	emp1.fire();

	Employee& emp2 = myDB.addEmployee("Marc", "White");
	emp2.setSalary(100000);

	Employee& emp3 = myDB.addEmployee("John", "Doe");
	emp3.setSalary(10000);
	emp3.promote();

	cout << "all employees: " << endl << endl;
	myDB.displayAll();

	cout << endl << "current employees: " << endl << endl;
	myDB.displayCurrent();

	cout << endl << "former employees: " << endl << endl;
	myDB.displayFormer();*/

	Database employeeDB;

	while (true) {
		int selection = displayMenu();
		switch (selection) {
		case 0:
			return 0;
		case 1:
			doHire(employeeDB);
			break;
		case 2:
			doFire(employeeDB);
			break;
		case 3:
			doPromote(employeeDB);
			break;
		case 4:
			employeeDB.displayAll();
			break;
		case 5:
			employeeDB.displayCurrent();
			break;
		case 6:
			employeeDB.displayFormer();
			break;
		default:
			cerr << "Unknown command." << endl;
			break;
		}
	}

	return 0;
}

int displayMenu()
{
	int selection;

	cout << endl;
	cout << "Employee Database" << endl;
	cout << "-----------------" << endl;
	cout << "1) Hire a new employee" << endl;
	cout << "2) Fire an employee" << endl;
	cout << "3) Promote an employee" << endl;
	cout << "4) List all employees" << endl;
	cout << "5) List all current employees" << endl;
	cout << "6) List all former employees" << endl;
	cout << "0) Quit" << endl;
	cout << endl;
	cout << "---> ";

	cin >> selection;

	return selection;
}

void doHire(Database& db)
{
	string firstName;
	string lastName;

	cout << "First name? ";
	cin >> firstName;
	cout << "Last name? ";
	cin >> lastName;

	db.addEmployee(firstName, lastName);
}

void doFire(Database& db)
{
	int employeeNumber;

	cout << "Employee number? ";
	cin >> employeeNumber;

	try {
		Employee& emp = db.getEmployee(employeeNumber);
		emp.fire();
		cout << "Employee " << employeeNumber << " terminated." << endl;
	}
	catch (const std::logic_error& exception) {
		cerr << "Unable to terminate employee: " << exception.what() << endl;
	}

}

void doPromote(Database& db)
{
	int employeeNumber;
	int raiseAmount;

	cout << "Employee number? ";
	cin >> employeeNumber;
	cout << "How much of a raise? ";
	cin >> raiseAmount;

	try {
		Employee& emp = db.getEmployee(employeeNumber);
		emp.promote(raiseAmount);
	}
	catch (const std::logic_error& exception) {
		cerr << "Unable to promote employee: " << exception.what() << endl;
	}
}