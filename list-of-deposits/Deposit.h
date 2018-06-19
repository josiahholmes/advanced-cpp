//Josiah Holmes
//CSIS 112 � Spring 2016
//Deposit.h � Interface file for class Deposit

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#pragma once
using namespace std;

// In the functions, 'Var' is short for Variable.

class Deposit
{
public:
	Deposit();
	void setDeposit(double amount);
	void displayDeposits(ofstream &fout);
	void setNextAvailable(int nAvailableInt);
	int getNextAvailable();
	void setDate(int monthVar, int dayVar, int yearVar);
	void setDayOfWeek(string dayVar);
	string getDayOfWeek();
	void setCount(int dayCount);
	int getCount();
	void setTotal(double totalVar);
	double getTotal();
private:
	int month,
		day,
		year,
		nextAvailable,
		count;      // Variable used to count the number of deposits for each weekday.
	string dayOfWeek;
	double depositArray[100],
		grandTotal; // Variable used to get total of all deposits when added together.
};