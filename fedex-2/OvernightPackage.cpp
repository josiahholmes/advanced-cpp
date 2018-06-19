//Josiah Holmes
//CSIS 112 � Spring 2016
//Lab 8 - FedEx Part 2.
//OvernightPackage.cpp - implementation file for class OvernightPackage.

#include "OvernightPackage.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;


OvernightPackage::OvernightPackage()
{
	cout << "OvernightPackage object constructor running . . . " << endl;
}

/*
OvernightPackage::OvernightPackage(string &n, int &z, int &w, char &t)
	:Package(n, z, w, t)
{
	cout << "OvernightPackage object constructor for Object " << getName() << "." << endl;
}
*/

OvernightPackage::~OvernightPackage()
{
	if (getName() != "")
		cout << "OvernightPackage object destructor for Object " << getName() << "." << endl;
}


void OvernightPackage::print(ofstream &output)
{
	output << "             ------------------------------------------" << endl
		<< "             OVERNIGHT Print Function Running . . . " << endl
		<< "             ------------------------------------------" << endl
		<< "             Customer Name: " << getName() << endl
		<< "             Object ID: " << getObjectID() << endl
		<< "             Zip Code: " << getZipCode() << endl
		<< "             Object Weight: " << getWeight() << " lbs."
		<< endl << endl << endl;
}