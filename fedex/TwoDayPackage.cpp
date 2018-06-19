//Josiah Holmes
//CSIS 112 � Spring 2016
//Lab 7 - FedEx.
//TwoDayPackage.cpp - implementation file for class TwoDayPackage.


#include "TwoDayPackage.h"
#include <iomanip>
using namespace std;


TwoDayPackage::TwoDayPackage()
{
}


TwoDayPackage::TwoDayPackage(string &n, int &z, double &w, char &t)
	:Package(n, z, w, t)
{
	additionalFee = 0;
	cout << "TwoDayPackage object constructor for Object " << getName() << "." << endl;
}


TwoDayPackage::~TwoDayPackage()
{
	if (getName() != "")
		cout << "TwoDayPackage object destructor for Object " << getName() << "." << endl;
}


void TwoDayPackage::CostOfShipping(double w, ofstream &output)
{
	double shipCost = 0;
	shipCost = 4 * w + additionalFee;
	output << shipCost;
}


void TwoDayPackage::operator+(int n)
{
	Package::operator+(n);
	this->additionalFee += n;
}


void TwoDayPackage::print(ofstream &output)
{
	output << showpoint << fixed << setprecision(2);
	output << "             " << getName() << setw(30 - getName().length())
		<< getObjectID() << "               " << getZipCode()
		<< "            $";
	CostOfShipping(getWeight(), output);
	output << " ($" << additionalFee << " Additional Fee)" << endl;
}