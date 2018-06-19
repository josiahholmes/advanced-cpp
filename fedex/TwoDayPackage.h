//Josiah Holmes
//CSIS 112 � Spring 2016
//Lab 7 - FedEx.
//TwoDayPackage.h - interface file for class TwoDayPackage.


#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "Package.h"
using namespace std;

class TwoDayPackage
	:public Package
{
public:
	TwoDayPackage();
	TwoDayPackage(string &, int &, double &, char &);
	~TwoDayPackage();
	void CostOfShipping(double, ofstream &);
	void operator+(int);
	void print(ofstream &);
private:
	int additionalFee;
};

#endif