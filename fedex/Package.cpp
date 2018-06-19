//Josiah Holmes
//CSIS 112 � Spring 2016
//Lab 7 - FedEx.
//Package.cpp - implementation file for class Package.


#include "Package.h"
#include <iomanip>
using namespace std;


int Package::ObjectCount = 0;


Package::Package()
{
}


Package::Package(string &n, int &z, double &w, char &t)
	:name(n),
	zipCode(z),
	weight(w),
	type(t)
{
	cout << "Package object constructor for Object " << name << "." << endl;
	incrementObjectID(ObjectCount);
	ObjectCount++;
}


Package::~Package()
{
	if (name != "")
		cout << "Package object destructor for Object " << name << "." << endl;
}


ofstream &operator<<(ofstream &output, const Package &pkgObject)
{
	output << "             Object " << pkgObject.ObjectID << " weighs "
		<< pkgObject.weight << " lbs." << endl;
	return output;
}


 void Package::CostOfShipping(double w, ofstream &output)
{
	double shipCost = 0;
	shipCost = 2 * w;
	output << shipCost;
}


void Package::operator+(int n)
{
	this->weight += n;
}


void Package::incrementObjectID(int number)
{
	ObjectID += number;
}


void Package::setName(string n)
{
	name = n;
}


void Package::setZipCode(int z)
{
	zipCode = z;
}


void Package::setWeight(double w)
{
	weight = w;
}


void Package::setType(char t)
{
	type = t;
}


string Package::getName()
{
	return name;
}


int Package::getZipCode()
{
	return zipCode;
}


double Package::getWeight()
{
	return weight;
}


char Package::getType()
{
	return type;
}


int Package::getObjectID()
{
	return ObjectID;
}


void Package::print(ofstream &output)
{
	output << showpoint << fixed << setprecision(2);
	output << "             " << name << setw(30 - name.length())
		<< ObjectID << "               " << zipCode
		<< "            ";
	if (type == 'o')
		output << "   N/A (overnight)" << endl;

	if (type == 't')
		output << "   N/A (two day)" << endl;

	if (type == 'p')
	{
		output << "       $";
		CostOfShipping(weight, output);
		output << endl;
	}
		
}


