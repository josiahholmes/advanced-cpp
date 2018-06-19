//Josiah Holmes
//CSIS 112 � Spring 2016
//Lab 6 - Savings Account Class. A driver program tests
//        the class SavingsAccount, which is composed with
//        the Date class. Two savings accounts are created
//        with separate starting balances, and interest --
//        3%  and 4% -- is calculated for both accounts.
//        Both accounts are then assessed based on their
//        savings amounts.

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include "SavingsAccount.h"
#include "Date.h"
using namespace std;


const string ID = "Josiah Holmes - CSIS 112(2), Spring 2016 - Lab6";

int main()
{
	cout << endl << "Running Lab6 . . . " << endl;
	cout << ID << endl;
	cout << "              Console Output" << endl << endl << endl;


	//  DEFINITIONS
	bool  noErrors = true;
	char  exit;
	ofstream fout,
		errOut;


	//  ADMINISTRATIVE STUFF
	fout.open(ID + ".out");
	errOut.open(ID + ".err");
	fout << ID << endl;
	fout << "               Main Report" << endl << endl << endl;
	errOut << ID << endl;
	errOut << "         ***  Error Report  ***" << endl << endl << endl;

	//  PROGRAM LOGIC
	const Date date1(12, 16, 1999);
	const Date date2(3, 12, 2010);

	SavingsAccount saver1(12345, date1);
	SavingsAccount saver2(92834, date2);

	fout << "                        Saver 1" << endl;
	fout << "                Account Number: #";
	saver1.printAccountNumber(fout);
	fout << endl;
	fout << "                 Open Date: ";
	saver1.printDate(fout);
	fout << endl << endl;
	fout << "           Interest Rate           Balance" << endl;
	fout << "          ----------------        ---------" << endl;
	fout << "          Initial Balance          $" << fixed << setprecision(2);
	saver1.printBalance(fout);
	saver1.modifyInterestRate(0.03);
	saver1.calculateMonthlyInterest();
	fout << endl << "          3% Interest Rate         $" << fixed << setprecision(2);
	saver1.printBalance(fout);
	saver1.modifyInterestRate(0.04);
	saver1.calculateMonthlyInterest();
	fout << endl << "          4% Interest Rate         $" << fixed << setprecision(2);
	saver1.printBalance(fout);


	fout << endl << endl << endl;


	fout << "                        Saver 2" << endl;
	fout << "                Account Number: #";
	saver2.printAccountNumber(fout);
	fout << endl;
	fout << "                 Open Date: ";
	saver2.printDate(fout);
	fout << endl << endl;
	fout << "           Interest Rate           Balance" << endl;
	fout << "          ----------------        ---------" << endl;
	fout << "          Initial Balance         $" << fixed << setprecision(2);
	saver2.printBalance(fout);
	saver2.modifyInterestRate(0.03);
	saver2.calculateMonthlyInterest();
	fout << endl << "          3% Interest Rate        $" << fixed << setprecision(2);
	saver2.printBalance(fout);
	saver2.modifyInterestRate(0.04);
	saver2.calculateMonthlyInterest();
	fout << endl << "          4% Interest Rate        $" << fixed << setprecision(2);
	saver2.printBalance(fout);

	fout << endl << endl << endl << endl;

	fout << "Saver 1's current balance is $" << fixed << setprecision(2);
	saver1.printBalance(fout);
	fout << ". Saver 1 is ";
	sizeOfBalance(saver1, fout);

	fout << "Saver 2's current balance is $" << fixed << setprecision(2);
	saver2.printBalance(fout);
	fout << ". Saver 2 is ";
	sizeOfBalance(saver2, fout);

	//EXIT ROUTINE
	errOut << endl << endl;
	fout << endl << endl;
	cout << endl << endl;

	if (noErrors)
		errOut << "No Errors Were Detected" << endl << endl << endl;

	errOut << "END OF ERROR REPORT" << endl;
	fout << "END OF MAIN REPORT" << endl;
	cout << "Enter any key to end execution of this program   . . .   ";
	cin >> exit;                                             //to pause program
	return 0;
}

void sizeOfBalance(SavingsAccount &s, ofstream &output)
{
	if (s.savingsBalance < 100)
		output << "VERY POOR." << endl;
	else if (s.savingsBalance > 100 && s.savingsBalance < 5000)
		output << "TYPICAL." << endl;
	else if (s.savingsBalance > 5000 && s.savingsBalance < 100000)
		output << "WELL OFF." << endl;
	else
		output << "RICH." << endl;
}