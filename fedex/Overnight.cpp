//Josiah Holmes
//CSIS 112 � Spring 2016
//Lab 7 - FedEx.
//Overnight.cpp - implementation file for class Overnight.


#include "Overnight.h"
#include <iomanip>
using namespace std;


Overnight::Overnight()
{
}


Overnight::Overnight(string &n, int &z, double &w, char &t)
	:Package(n, z, w, t)
{
	additionalFee = 0;
	cout << "Overnight object constructor for Object " << getName() << "." << endl;
}


Overnight::~Overnight()
{
	if (getName() != "")
		cout << "Overnight object destructor for Object " << getName() << "." << endl;
}


void Overnight::CostOfShipping(double w, ofstream &output)
{
	double shipCost = 0;
	shipCost = 14 * w + additionalFee;
	output << shipCost;
}


void Overnight::operator+(int n)
{
	Package::operator+(n);
	this->additionalFee += (2 * n);
}


void Overnight::print(ofstream &output)
{
	output << showpoint << fixed << setprecision(2);
	output << "             " << getName() << setw(30 - getName().length())
		<< getObjectID() << "               " << getZipCode()
		<< "            $";
	CostOfShipping(getWeight(), output);
	output << " ($" << additionalFee << " Additional Fee)" << endl;
}