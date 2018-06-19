//Josiah Holmes
//CSIS 112 � Spring 2016
//Lab 6 - Savings Account Class.
//SavingsAccount.cpp - implementation file for class SavingsAccount.

#include <iostream>
#include "SavingsAccount.h"
using namespace std;

double SavingsAccount::annualInterestRate = 0;

SavingsAccount::SavingsAccount(const int acctNum, const Date & dateOpened)
	: accountNumber(acctNum),
	openDate(dateOpened)
{
	if (accountNumber == 12345)
		savingsBalance = 2000;

	if (accountNumber == 92834)
		savingsBalance = 30000;

	cout << "SavingsAccount object constructor for Account #" 
		<< accountNumber << "." << endl;
}


SavingsAccount::~SavingsAccount()
{
	cout << "SavingsAccount object destructor for Account #" << accountNumber << "." << endl;
}


double SavingsAccount::calculateMonthlyInterest()
{
	double monthlyInterest = 0;
	monthlyInterest = savingsBalance * annualInterestRate / 12;
	savingsBalance += monthlyInterest;
	return this->savingsBalance;
}


double SavingsAccount::modifyInterestRate(double newRate)
{
	annualInterestRate = newRate;
	return annualInterestRate;
}


void SavingsAccount::printBalance(ofstream &output)
{
	output << (*this).savingsBalance;
}


void SavingsAccount::printAccountNumber(ofstream &output)
{
	output << (*this).accountNumber;
}


void SavingsAccount::printDate(ofstream &output)
{
	openDate.print(output);
}
