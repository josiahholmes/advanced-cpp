//Josiah Holmes
//CSIS 112 � Spring 2016
//Lab 8 - FedEx Part 2. This lab focuses on two packages and performs
//                      various tasks encompassing polymorphism, virtual
//                      functions, pure virtual functions, templates, and
//                      exceptions. This lab also explores the capabilities
//                      of a queue through use of a class template.

#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"
#include "Queue.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const string ID = "Josiah Holmes - CSIS 112(2), Spring 2016 - Lab8";


int main()
{
	cout << endl << "Running Lab8 . . . " << endl;
	cout << ID << endl;
	cout << "              Console Output" << endl << endl << endl;


	//  DEFINITIONS
	bool  noErrors = true;
	char  exit,
		type;
	ofstream fout,
		errOut;
	ifstream fin;
	string name;
	int zipCode,
		weight,
		result = 0;
	double doubleWeight;
	Queue<double> doubleQueue;
	Queue<int> intQueue;


	// OUTPUT FORMATTING
	string LONG_TAB = "                                                       ";


	//  ADMINISTRATIVE STUFF
	fout.open(ID + ".out");
	errOut.open(ID + ".err");
	fout << ID << endl;
	fout << "               Main Report" << endl << endl << endl;
	errOut << ID << endl;
	errOut << "         ***  Error Report  ***" << endl << endl << endl;
	fin.open("Lab8.dat");


	if (!fin) // Test to ensure file exists; error procedure executes in case file does not exist
	{
		cout << "*** ERROR:  file not found; program terminated" << endl << endl << endl;
		fout << "*** ERROR:  file not found; program terminated" << endl << endl << endl;
		errOut << "*** ERROR:  file not found; program terminated" << endl << endl << endl;
		errOut << "END OF ERROR REPORT";
		fout << "END OF MAIN REPORT";
		cout << "Enter any key to end execution of this program   . . .   ";
		cin >> exit;                                             //to pause program
		return 1;
	}


	//  PROGRAM LOGIC

	// OBJECTS CREATED FOR DERIVED CLASSES
	OvernightPackage overnightObject;
	TwoDayPackage twoDayObject;

	// BASE-CLASS POINTERS
	Package * opackagePtr = 0;
	Package * tpackagePtr = 0;

	// DERIVED-CLASS POINTERS
	OvernightPackage * overnightPtr = 0;
	TwoDayPackage * twoDayPtr = 0;

	// BASE-CLASS POINTERS TO DERIVED-CLASS OBJECTS
	opackagePtr = &overnightObject;
	tpackagePtr = &twoDayObject;

	// DERIVED-CLASS POINTERS TO DERIVED-CLASS OBJECTS
	overnightPtr = &overnightObject;
	twoDayPtr = &twoDayObject;

	// READING INPUT FILE & DATA VALIDATION
	for (int count = 1; fin >> name >> zipCode >> weight >> type; count++)
	{
		int objectQuantity = 2; // number of objects to create

		if (zipCode < 0)
		{
			noErrors = false;
			errOut << "             *** ERROR: Zip Code " << zipCode << " is negative. Object for "
				<< name << " ignored." << endl;
			continue;
		}

		if (weight < 0)
		{
			noErrors = false;
			errOut << "             *** ERROR: Weight " << weight << " is negative. Object for "
				<< name << " ignored." << endl;
			continue;
		}

		if (count <= objectQuantity)
		{
			if (type == 'o')
			{
				overnightObject.setName(name);
				overnightObject.setZipCode(zipCode);
				overnightObject.setWeight(weight);
				overnightObject.setType(type);
			}

			if (type == 't')
			{
				twoDayObject.setName(name);
				twoDayObject.setZipCode(zipCode);
				twoDayObject.setWeight(weight);
				twoDayObject.setType(type);
			}

		}

		if (count > objectQuantity)
		{
			if (weight % 2 == 0)
			{
				doubleWeight = double(weight);
				if (doubleQueue.enqueue(doubleWeight))
					cout << doubleWeight << " has been added to the double queue . . . " << endl;
			}
			
			if (weight % 2 == 1)
			{
				if (intQueue.enqueue(weight))
					cout << weight << " has been added to the int queue . . . " << endl;
			}
		}
	
	}		


	// MAIN REPORT PRINTING
	fout << LONG_TAB << "Part I - static binding" << endl << endl;
	twoDayObject.print(fout);
	overnightObject.print(fout);
	twoDayObject.Package::print(fout); // accessing base print through binary scope resolution operator
	overnightObject.Package::print(fout); // accessing base print through binary scope resolution operator
	
	fout << LONG_TAB << "Part II - dynamic binding" << endl << endl;


	// BASE-CLASS POINTER TO DERIVED-CLASS OBJECT PRINT
	fout << "             BASE-CLASS POINTERS TO DERIVED-CLASS OBJECTS" << endl << endl;
	tpackagePtr->print(fout);
	opackagePtr->print(fout);


	// DERIVED-CLASS POINTER TO DERIVED-CLASS OBJECT PRINT
	fout << "             DERIVED-CLASS POINTERS TO DERIVED-CLASS OBJECTS" << endl << endl;
	twoDayPtr->print(fout);
	overnightPtr->print(fout);


	// INT QUEUE
	fout << LONG_TAB << "Int Queue" << endl << endl;
	fout << "            Elements: ";

	for (int i = 0; i < 2; i++)
		intQueue.dequeue(weight, fout);

	fout << endl << "            The sum of the items divided by the number of the items is " 
		<< intQueue.getQuotient() << "." << endl;


	// DOUBLE QUEUE 
	fout << endl << endl << endl;
	fout << LONG_TAB << "Double Queue" << endl << endl;
	fout << "            Elements: ";

	for (int i = 0; i < 2; i++)
		doubleQueue.dequeue(doubleWeight, fout);

	fout << endl << "            The sum of the items divided by the number of the items is "
		<< doubleQueue.getQuotient() << "." << endl;


	// DIVIDE BY ZERO EXCEPTION HANDLING
	fout << endl << endl << endl;
	fout << LONG_TAB << "DIVIDE BY ZERO" << endl << endl;

	fout << "            Double Queue -- ";
	try
	{
		result = doubleQueue.zeroQuotient(doubleQueue.getSum(), 0);
		fout << "The quotient is: " << result << endl;
	}
	catch (runtime_error &e)
	{
		fout << "Exception occurred: "
			<< e.what() << endl;
	}


	fout << "            Int Queue -- ";
	try
	{
		result = intQueue.zeroQuotient(intQueue.getSum(), 0);
		fout << "The quotient is: " << result << endl;
	}
	catch (runtime_error &e)
	{
		fout << "Exception occurred: "
			<< e.what() << endl;
	}


	//EXIT ROUTINE
	errOut << endl << endl;
	fout << endl << endl;
	cout << endl << endl;

	if (noErrors)
		errOut << "No Errors Were Detected" << endl << endl << endl;

	errOut << "END OF ERROR REPORT" << endl;
	fout << "END OF MAIN REPORT" << endl;
	cout << "Enter any key to end execution of this program   . . .   ";
	cin >> exit;                                             //to pause program
	return 0;
}

