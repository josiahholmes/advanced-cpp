//Josiah Holmes
//CSIS 112 � Spring 2016
//Deposit.cpp � Implementation file for class Deposit

#include <iostream>
#include "Deposit.h"
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// In functions, 'Var' is short for variable.

Deposit::Deposit()
{
	setNextAvailable(0);
	setDate(99, 99, 9999);                            // Function sets date to all 9's (99/99/9999).
	cout << "Constructor is running . . . " << endl;  // Constructor runs for each object.
}


void Deposit::setDeposit(double amount)
{
	depositArray[nextAvailable] = amount;  
	nextAvailable++;    // nextAvailable is incremented.
	if (month < 10)
	{
		cout << "       A deposit of $" << amount << " for " << getDayOfWeek() << ", 0" << month << "/" << day << "/" << year << " was processed." << endl;
	}
	else
	{
		cout << "       A deposit of $" << amount << " for " << getDayOfWeek() << ", " << month << "/" << day << "/" << year << " was processed." << endl;
	}
}


void Deposit::displayDeposits(ofstream &fout)
{
	double total = 0;  // Variable 'total' created for set and get total functions.
	if (count >= 1)   
	{
		fout << "      " << getCount() << " ";   // getCount() returns the count for each weekday.
		if (count > 1)
		{
			fout << "deposits for ";
		}
		else if (count <= 1)
		{
			fout << "deposit for ";
		}
		fout << getDayOfWeek() << ", ";        // getDayOfWeek() returns the day name as a string.
		if (month < 10)
		{
			fout << "0" << month << "/" << day << "/" << year << ":";
		}
		else
		{
			fout << month << "/" << day << "/" << year << ":";
		}
		fout << endl << endl;
		fout << "      ---------------------" << endl;
		fout << "                     Amount" << endl;
		fout << "      ---------------------" << endl;
		for (int i = 0; i < nextAvailable; i++)
		{
			total = total + depositArray[i];
			fout << "                     ";
			fout << setprecision(2) << fixed << setw(6) << depositArray[i] << endl;
		}
		fout << "      ---------------------" << endl;
		fout << "      Total:         " << setprecision(2) << fixed << setw(6) << total << endl;
		setTotal(total);   // Total is sent to the set function for each object.
		fout << endl << endl << endl;
	}
	else if (count == 0)
	{
		total = 0;         // If there are no objects in the object, total is set to 0.
		setTotal(total);
		fout << "";        // This omits the printing of an object since it does not contain objects.
	}
}


void Deposit::setNextAvailable(int nAvailableInt)
{
	nextAvailable = nAvailableInt;
}


int Deposit::getNextAvailable()
{
	return nextAvailable;
}


void Deposit::setDate(int monthVar, int dayVar, int yearVar)
{
	month = monthVar;
	day = dayVar;
	year = yearVar;
}


void Deposit::setDayOfWeek(string dayVar)
{
	dayOfWeek = dayVar;
}


string Deposit::getDayOfWeek()
{
	return dayOfWeek;
}


void Deposit::setCount(int dayCount)
{
	count = dayCount;
}


int Deposit::getCount()
{
	return count;
}


void Deposit::setTotal(double totalVar)
{
	grandTotal = totalVar;
}


double Deposit::getTotal()
{
	return grandTotal;
}

