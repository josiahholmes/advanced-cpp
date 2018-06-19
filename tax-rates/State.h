//Josiah Holmes
//CSIS 112 – Spring 2016
//Lab 4 - State.h.  Interface file for class State.


#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class State
{
public:
	State(string state_name);
	void setStateName(string argStateName);
	string getStateName();
	void setTaxBill(const double argSalary, const double argHouse,
		const double argAnnual, double argIncomeTax, double argPropTax,
		double argSalesTax);
	double getTaxBill();
	void setRowNumber(int argCount);
	int getRowNumber();
private:
	string stateName;
	double tax_bill;
	int rowNumber;
};