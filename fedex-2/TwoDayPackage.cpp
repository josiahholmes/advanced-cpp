//Josiah Holmes
//CSIS 112 � Spring 2016
//Lab 8 - FedEx Part 2.
//TwoDayPackage.cpp - implementation file for class TwoDayPackage.

#include "TwoDayPackage.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;


TwoDayPackage::TwoDayPackage()
{
	cout << "TwoDayPackage object constructor running . . . " << endl;
}

/*
TwoDayPackage::TwoDayPackage(string &n, int &z, int &w, char &t)
	:Package(n, z, w, t)
{
	cout << "TwoDayPackage object constructor for Object " << getName() << "." << endl;
}
*/

TwoDayPackage::~TwoDayPackage()
{
	if (getName() != "")
		cout << "TwoDayPackage object destructor for Object " << getName() << "." << endl;
}


void TwoDayPackage::print(ofstream &output)
{
	output << "             ------------------------------------------" << endl
		<< "             TWODAYPACKAGE Print Function Running . . . " << endl
		<< "             ------------------------------------------" << endl
		<< "             Customer Name: " << getName() << endl
		<< "             Object ID: " << getObjectID() << endl
		<< "             Zip Code: " << getZipCode() << endl
		<< "             Object Weight: " << getWeight() << " lbs." 
		<< endl << endl << endl;
}