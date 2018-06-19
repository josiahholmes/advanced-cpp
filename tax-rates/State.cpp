//Josiah Holmes
//CSIS 112 � Spring 2016
//Lab 4 - State.cpp.  Implementation file for class State.


#include "State.h"
#include <iostream>
#include <string>
using namespace std;


State::State(string state_name)
{
	if (state_name != " ")
	{
		cout << "Constructor running for " << state_name << " . . . " << endl;
	}
}


void State::setStateName(string argStateName)
{
	stateName = argStateName;
}


string State::getStateName()
{
	return stateName;
}


void State::setTaxBill(const double argSalary, const double argHouse,
	const double argAnnual, double argIncomeTax, double argPropTax,
	double argSalesTax)
{
	tax_bill = (argSalary * argIncomeTax) + (argHouse * argPropTax) +
		(argAnnual * argSalesTax);
}


double State::getTaxBill()
{
	return tax_bill;
}


void State::setRowNumber(int argCount)
{
	rowNumber = argCount;
}


int State::getRowNumber()
{
	return rowNumber;
}
