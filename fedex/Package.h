//Josiah Holmes
//CSIS 112 – Spring 2016
//Lab 7 - FedEx.
//Package.h - interface file for class Package.


#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Package
{
	friend ofstream &operator<<(ofstream &, const Package &);
public:
	Package();
	Package(string &, int &, double &, char &);
	~Package();
	void CostOfShipping(double, ofstream &);
	void operator+(int);
	void incrementObjectID(int);

	void setName(string);
	void setZipCode(int);
	void setWeight(double);
	void setType(char);

	string getName();
	int getZipCode();
	double getWeight();
	char getType();
	int getObjectID();

	void print(ofstream&);
private:
	string name;
	int zipCode,
		ObjectID = 1001;
	static int ObjectCount;
	double weight,
		shipCost;
	char type;
};

#endif