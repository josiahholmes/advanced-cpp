//Josiah Holmes
//CSIS 112 – Spring 2016
//Lab 7 - FedEx.
//Overnight.h - interface file for class Overnight.


#ifndef OVERNIGHT_H
#define OVERNIGHT_H

#include "Package.h"
using namespace std;

class Overnight
	:public Package
{
public:
	Overnight();
	Overnight(string &, int &, double &, char &);
	~Overnight();
	void CostOfShipping(double, ofstream &);
	void operator+(int);
	void print(ofstream &);
private:
	int additionalFee;
};

#endif