//Josiah Holmes
//CSIS 112 � Spring 2016
//Lab 6 - Savings Account Class.
//SavingsAccount.h - interface file for class SavingsAccount.

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include <iostream>
#include <fstream>
#include "Date.h"
using namespace std;

class SavingsAccount
{
	friend void sizeOfBalance(SavingsAccount &s, ofstream &output);
public:
	SavingsAccount(const int acctNum, const Date & dateOpened);
	~SavingsAccount();
	double calculateMonthlyInterest();
	static double modifyInterestRate(double newRate);
	void printBalance(ofstream &fout);
	void printAccountNumber(ofstream &output);
	void printDate(ofstream &output);
private:
	static double annualInterestRate;
	double savingsBalance;
	const Date openDate;
	const int accountNumber;
};

#endif