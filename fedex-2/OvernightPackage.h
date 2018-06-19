//Josiah Holmes
//CSIS 112 – Spring 2016
//Lab 8 - FedEx Part 2.
//OvernightPackage.h - interface file for class OvernightPackage.

#ifndef OVERNIGHT_H
#define OVERNIGHT_H

#include <fstream>
#include <string>
#include "Package.h"
using namespace std;

class OvernightPackage : public Package
{
public:
	OvernightPackage();
	OvernightPackage(string &, int &, int &, char &);
	~OvernightPackage();
	virtual void print(ofstream &);
private:
};

#endif