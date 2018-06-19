//Josiah Holmes
//CSIS 112 � Spring 2016
//Lab 8 - FedEx Part 2.
//Package.cpp - implementation file for class Package.

#include "Package.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;


int Package::ObjectCount = 0;


Package::Package()
{
	cout << "Package object constructor running . . . " << endl;
	incrementObjectID(ObjectCount);
	ObjectCount++;
}

/*
Package::Package(string &n, int &z, int &w, char &t)
	:name(n),
	zipCode(z),
	weight(w),
	type(t)
{
	cout << "Package object constructor for Object " << name << "." << endl;
	incrementObjectID(ObjectCount);
	ObjectCount++;
}
*/

Package::~Package()
{
	if (name != "")
		cout << "Package object destructor for Object " << name << "." << endl;
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


void Package::setWeight(int w)
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


int Package::getWeight()
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
	output << "             ------------------------------------------" << endl
		<< "             PACKAGE Print Function Running . . . " << endl
		<< "             ------------------------------------------" << endl
		<< "             Customer Name: " << getName() << endl
		<< "             Object ID: " << getObjectID() << endl
		<< "             Zip Code: " << getZipCode() << endl
		<< "             Object Weight: " << getWeight() << " lbs."
		<< endl << endl << endl;
}