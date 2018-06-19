//Josiah Holmes
//CSIS 112 – Spring 2016
//Lab 4 - Tax Rates.  This program stores five states into a vector of objects, their tax
//                    rates in a two-dimensional array, and the row number in the oppropriate
//                    state object. The program also calculates the tax bill for each state
//                    in the appropriate object. Afterwards, the program prints out a report
//                    that display the states in alphabetical order, their tax bills, their tax rates
//                    the total tax rates, the total tax bill, the total tax rate sum, and statistics
//                    about the state tax rates under general observations.


#include "stdafx.h"
#include "State.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

const string ID = "Josiah Holmes - CSIS 112(2), Spring 2016 - Lab4";


void printVector(ofstream& fout, vector<State>& argVector, double argArray[][3]);
void selectionSort(vector<State>& argVector, const int size);
double getTotalTaxBill(vector<State>& argVector);
double getTotalTaxSum(double argArray[][3]);
string getLowestTaxBill(vector<State>& argVector);
int getStateSalesTaxCount(double argArray[][3]);
int getStatePropTaxCount(double argArray[][3]);
void printStatistics(ofstream& fout, double taxes[][3], vector<State>& stateInfo,
	string(*lowestTaxBillFuncPtr)(vector<State>& argVector),
	int(*salesTaxFuncPtr)(double argArray[][3]),
	int(*propTaxFuncPtr)(double argArray[][3]));


int main()
{
	cout << endl << "Running Lab4 . . . " << endl;
	cout << ID << endl;
	cout << "              Console Output" << endl << endl << endl;


	//  DEFINITIONS
	bool  noErrors = true;
	char  exit;
	ofstream fout,
		errOut;
	ifstream fin;
	int i = 0,
		(*salesTaxFuncPtr)(double argArray[][3]),
		(*propTaxFuncPtr)(double argArray[][3]);
	const double SALARY = 100000,
		HOUSE_COST = 267000,
		ANNUAL_PURCHASE = 36000;
	double sales_tax = 0,
		property_tax = 0,
		income_tax = 0,
		taxes[5][3] = { 0 };
	string state_name,
		(*lowestTaxBillFuncPtr)(vector<State>& argVector);
	vector<State> stateInfo;

	//  ADMINISTRATIVE STUFF
	fout.open(ID + ".out");
	errOut.open(ID + ".err");
	fout << ID << endl;
	fout << "               Main Report" << endl << endl << endl;
	errOut << ID << endl;
	errOut << "         ***  Error Report  ***" << endl << endl << endl;
	fin.open("Lab4.dat");


	if (!fin) // Test to ensure file exists; error procedure executes in case file does not exist
	{
		cout << "*** ERROR:  file not found; program terminated" << endl << endl << endl;
		fout << "*** ERROR:  file not found; program terminated" << endl << endl << endl;
		errOut << "*** ERROR:  file not found; program terminated" << endl << endl << endl;
		errOut << "END OF ERROR REPORT";
		fout << "END OF MAIN REPORT";
		cout << "Enter any key to end execution of this program   . . .   ";
		cin >> exit;                                             //to pause program
		return 1;
	}


	//  PROGRAM LOGIC
	cout << "Reading input file . . . " << endl << endl;


	for (; fin >> state_name >> taxes[i][0] >> taxes[i][1] >> taxes[i][2];)
	{
		State newState(state_name);


		cout << "Tax Rates for " << state_name << ":" << endl;
		cout << "SALES: " << taxes[i][0] << ", PROPERTY: " << taxes[i][1]
			<< ", INCOME: " << taxes[i][2] << endl << endl;


		if (taxes[i][0] < 0)
		{
			errOut << "*** ERROR: Negative sales tax for " << state_name <<
				". (" << taxes[i][0] << ")" << endl;
			cout << "*** ERROR: Negative sales tax for " << state_name << "." << endl;
			cout << "           Tax amount has been changed to 0.00." << endl << endl;
			noErrors = false;
			taxes[i][0] = 0;
		}
		
		if (taxes[i][1] < 0)
		{
			errOut << "*** ERROR: Negative property tax for " << state_name <<
				". (" << taxes[i][1] << ")" << endl;
			cout << "*** ERROR: Negative property tax for " << state_name << "." << endl;
			cout << "           Tax amount has been changed to 0.00." << endl << endl;
			noErrors = false;
			taxes[i][1] = 0;
		}	
		
		if (taxes[i][2] < 0)
		{
			errOut << "*** ERROR: Negative income tax for " << state_name <<
				". (" << taxes[i][2] << ")" << endl;
			cout << "*** ERROR: Negative income tax for " << state_name << "." << endl;
			cout << "           Tax amount has been changed to 0.00." << endl << endl;
			noErrors = false;
			taxes[i][2] = 0;
		}

		sales_tax = taxes[i][0];
		property_tax = taxes[i][1];
		income_tax = taxes[i][2];
		
		newState.setStateName(state_name);
		newState.setTaxBill(SALARY, HOUSE_COST, ANNUAL_PURCHASE, income_tax, property_tax, sales_tax);
		newState.setRowNumber(i);
		stateInfo.insert(stateInfo.end(), newState);

		i++;
		
	}


	selectionSort(stateInfo, stateInfo.size()); // selectionSort function call
	lowestTaxBillFuncPtr = &getLowestTaxBill; // points to getLowestTaxBill function
	salesTaxFuncPtr = &getStateSalesTaxCount; // points to getStateSalesTaxCount function
	propTaxFuncPtr = &getStatePropTaxCount; // points to getStatePropTaxCount function


	fout << "                                TAX RATES                             Total" << endl;
	fout << "State           Tax Bill        Sales   Property   Income           Tax Rate" << endl;
	fout << "------------------------        --------------------------------------------" << endl;
	printVector(fout, stateInfo, taxes);
	fout << "               ---------                                              ------" << endl;
	fout << "                " << setprecision(2) << getTotalTaxBill(stateInfo)
		<< "               (control totals)               " << setprecision(4) << fixed
		<< getTotalTaxSum(taxes) << endl << endl;
	fout << "GENERAL OBSERVATIONS:" << endl;
	printStatistics(fout, taxes, stateInfo, lowestTaxBillFuncPtr, salesTaxFuncPtr, propTaxFuncPtr);
	

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


void printVector(ofstream& fout, vector<State>& argVector, double argArray[][3])
{
	unsigned int size = argVector.size();

	for (unsigned int i = 0; i < size; i++)
	{
		int counter = argVector.at(i).getRowNumber();
		double tax_sum = argArray[counter][0] + argArray[counter][1] + argArray[counter][2];
		fout << argVector.at(i).getStateName() << setprecision(2) << fixed
			<< setw(24 - argVector.at(i).getStateName().length())
			<< argVector.at(i).getTaxBill() << setw(14)
			<< setprecision(4) << fixed << argArray[counter][0]
			<< setw(9) << argArray[counter][1]
			<< setw(10) << argArray[counter][2] << setw(19)
			<< setprecision(4) << fixed << tax_sum << endl;
	}

}


void selectionSort(vector<State>& argVector, const int size)
{
	string empty = " ";
	unsigned int smallest;
	State hold(empty);

	for (int i = 0; i < size - 1; ++i)
	{
		smallest = i;

		for (unsigned int index = i; index < size; ++index)
		{
			if (argVector.at(index).getStateName() < 
				argVector.at(smallest).getStateName())
			{
				smallest = index;
			}
		}

		if (smallest != i)
		{
			hold = argVector.at(i);
			argVector.at(i) = argVector.at(smallest);
			argVector.at(smallest) = hold;
		}
	}
}


double getTotalTaxBill(vector<State>& argVector)
{
	double totalTaxBill = 0;
	unsigned int size = argVector.size();

	for (unsigned int i = 0; i < size; i++)
	{
		totalTaxBill += argVector.at(i).getTaxBill();
	}
	return totalTaxBill;
}


double getTotalTaxSum(double argArray[][3])
{
	double totalTaxSum = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			totalTaxSum += argArray[i][j];
		}
	}
	return totalTaxSum;
}


string getLowestTaxBill(vector<State>& argVector)
{
	int lowIndex = 0;
	string stateName;
	State *vecPtr = argVector.data();

	
	for (unsigned int i = 1; i < argVector.size(); i++)
	{
		if ((*(vecPtr + i)).getTaxBill() < 
			(*(vecPtr + lowIndex)).getTaxBill())
			lowIndex = i;
	}

	stateName = (*(vecPtr + lowIndex)).getStateName();
	return stateName;
}


int getStateSalesTaxCount(double argArray[][3])
{
	int count = 0;
	double (*argPtr)[3] = argArray;
	for (int i = 0; i < 5; i++)
		if (*(*(argArray + i)) >= .08)
			count++;
	return count;
}


int getStatePropTaxCount(double argArray[][3])
{
	int count = 0;
	double(*argPtr)[3] = argArray;
	for (int i = 0; i < 5; i++)
		if (*(argPtr[i] + 1) >= .05)
			count++;
	return count;
}


void printStatistics(ofstream& fout, double taxes[][3], vector<State>& stateInfo, 
	string(*lowestTaxBillFuncPtr)(vector<State>& argVector), 
	int(*salesTaxFuncPtr)(double argArray[][3]), 
	int(*propTaxFuncPtr)(double argArray[][3]))
{
	string state = (*lowestTaxBillFuncPtr)(stateInfo);
	int salesTaxCount = (*salesTaxFuncPtr)(taxes);
	int propTaxCount = (*propTaxFuncPtr)(taxes);

	fout << "     The state with the lowest tax bill is " << state << "." << endl;

	if (salesTaxCount > 1)
		fout << "     There are " << salesTaxCount << " states with"
		<< " sales tax greater than or equal to 8%." << endl;
	else
		fout << "     There is " << salesTaxCount << " state with"
		<< " sales tax greater than or equal to 8%." << endl;


	if (propTaxCount > 1)
		fout << "     There are " << propTaxCount << " states with"
		<< " property tax greater than or equal to 5%." << endl;
	else
		fout << "     There is " << propTaxCount << " state with"
		<< " property tax greater than or equal to 5%." << endl;
}
