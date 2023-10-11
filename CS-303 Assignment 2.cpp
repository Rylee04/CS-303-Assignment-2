// CS-303 Assignment 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <stdexcept>
#include <string>
#include "Functions.h"
using namespace std;

int main() {

    //Example instances of a professional employee named Michael
    //and a nonprofessional named Dave

    //The order of parameters are name, employee ID, hourly rate, then hours worked
    Professional michael("Michael", 123, 20, 40);
    cout << "Professional Employee Information:" << endl;
    cout << "Weekly Salary: $" << michael.calcSalary() << endl;
    cout << "Health Care Contributions: $" << michael.calcHealthCare() << endl;
    cout << "Vacation Days: " << michael.calcVacationDays() << " days" << endl << endl;

    Nonprofessional dave("Dave", 234, 15, 30);
    cout << "Nonprofessional Employee Information:" << endl;
    cout << "Weekly Salary: $" << dave.calcSalary() << endl;
    cout << "Health Care Contributions: $" << dave.calcHealthCare() << endl;
    cout << "Vacation Days: " << dave.calcVacationDays() << " days" << endl;

}