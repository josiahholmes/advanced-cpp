//Josiah Holmes
//CSIS 112 � Spring 2016
//Lab 8 - FedEx Part 2.
//TwoDayPackage.h - interface file for class TwoDayPackage.

#ifndef TWODAY_H
#define TWODAY_H

#include <fstream>
#include <string>
#include "Package.h"
using namespace std;

class TwoDayPackage : public Package
{
public:
	TwoDayPackage();
	TwoDayPackage(string &, int &, int &, char &);
	~TwoDayPackage();
	virtual void print(ofstream &);
private:
};

#endif