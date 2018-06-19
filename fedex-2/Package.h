//Josiah Holmes
//CSIS 112 – Spring 2016
//Lab 8 - FedEx Part 2.
//Package.h - interface file for class Package.

#ifndef PACKAGE_H
#define PACKAGE_H

#include <fstream>
#include <string>
using namespace std;

class Package
{
public:
	Package();
	Package(string &, int &, int &, char &);
	~Package();
	void incrementObjectID(int);

	void setName(string);
	void setZipCode(int);
	void setWeight(int);
	void setType(char);

	string getName();
	int getZipCode();
	int getWeight();
	char getType();

	int getObjectID();

	virtual void print(ofstream &);
private:
	string name;
	int zipCode,
		weight,
		ObjectID = 1001;
	static int ObjectCount;
	//double shipCost;
	char type;
};

#endif