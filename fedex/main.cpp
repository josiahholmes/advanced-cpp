//Josiah Holmes
//CSIS 112 � Spring 2016
//Lab 7 - FedEx. This lab calculates the cost of shipping
//               for six different consumers, based on whether
//               they chose standard shipping, two day shipping,
//               or overnight shipping.


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Package.h"
#include "TwoDayPackage.h"
#include "Overnight.h"
using namespace std;

const string ID = "Josiah Holmes - CSIS 112(2), Spring 2016 - Lab7";


int main()
{
	cout << endl << "Running Lab7 . . . " << endl;
	cout << ID << endl;
	cout << "              Console Output" << endl << endl << endl;


	//  DEFINITIONS
	bool  noErrors = true;
	char  exit;
	ofstream fout,
		errOut;
	ifstream fin;
	string name;
	int zipCode,
		i = 0;
	double weight;
	char type;

	// DEFINTIIONS FOR FORMATTING MAIN REPORT FILE
	string TAB = "    ";
	string MED_TAB = "                  ";
	string LONG_TAB = "                                       ";

	// ARRAY OF 10 POINTERS FOR EACH CLASS
	Package * pArray;
	TwoDayPackage * tArray;
	Overnight * oArray;

	pArray = new Package[10];
	tArray = new TwoDayPackage[10];
	oArray = new Overnight[10];

	//  ADMINISTRATIVE STUFF
	fout.open(ID + ".out");
	errOut.open(ID + ".err");
	fin.open("Lab7.dat");
	fout << ID << endl;
	fout << "               Main Report" << endl << endl << endl;
	errOut << ID << endl;
	errOut << "         ***  Error Report  ***" << endl << endl << endl;


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


	cout << "PACKAGE, TWO DAY PACKAGE, and OVERNIGHT constructors running . . . " << endl;


	//  PROGRAM LOGIC
	for (; fin >> name >> zipCode >> weight >> type;)
	{
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

		if (type == 'p')
		{
			Package * tempPackagePtr = new Package(name, zipCode, weight, type);
			pArray[i] = * tempPackagePtr;
		}

		if (type == 't')
		{
			TwoDayPackage * tempTwoPtr = new TwoDayPackage(name, zipCode, weight, type);
			tArray[i] = * tempTwoPtr;
			pArray[i] = * tempTwoPtr;
		}

		if (type == 'o')
		{
			Overnight * tempOvernightPtr = new Overnight(name, zipCode, weight, type);
			oArray[i] = * tempOvernightPtr;
			pArray[i] = * tempOvernightPtr;
		}

		i++;
	}


	fout << "             PACKAGE print function running . . . " << endl << endl;
	fout << LONG_TAB << "STANDARD PACKAGE INFORMATION" << MED_TAB << endl << endl;
	fout << "                  Name              Object ID            Zip Code             "
		<< "Cost Of Shipping" << endl;
	fout << "             ---------------       -----------          ----------         "
		<< "---------------------" << endl;
	for (int i = 0; i < 10; i++)
	{
		if (pArray[i].getName() != "")
			pArray[i].print(fout);
	}

	fout << endl << endl << endl;

	fout << "             OVERNIGHT print function running . . . " << endl << endl;
	fout << LONG_TAB << "OVERNIGHT PACKAGE INFORMATION" << MED_TAB << endl << endl;
	fout << "                  Name              Object ID            Zip Code                "
		<< "Cost Of Shipping" << endl;
	fout << "             ---------------       -----------          ----------         "
		<< "--------------------------" << endl;
	for (int i = 0; i < 10; i++)
	{
		if (oArray[i].getName() != "")
			oArray[i].print(fout);
	}

	fout << endl << endl << endl;

	fout << "             TWO DAY PACKAGE print function running . . . " << endl << endl;
	fout << LONG_TAB << "TWO DAY PACKAGE INFORMATION" << MED_TAB << endl << endl;
	fout << "                  Name              Object ID            Zip Code                "
		<< "Cost Of Shipping" << endl;
	fout << "             ---------------       -----------          ----------         "
		<< "--------------------------" << endl;
	for (int i = 0; i < 10; i++)
	{
		if (tArray[i].getName() != "")
			tArray[i].print(fout);
	}

	for (int i = 0; i < 10; i++)
	{
		pArray[i] + 3;
		tArray[i] + 3;
		oArray[i] + 3;
	}
		
	fout << endl << endl << endl << "             --------------------------------------------"
		<< "-------------------" << endl
		<< "             3 has been added to Package, Overnight, and TwoDayPackage . . . " << endl
		<< "             ---------------------------------------------------------------" 
		<< endl << endl << endl;
	
	fout << "             PACKAGE print function running . . . " << endl << endl;
	fout << LONG_TAB << "STANDARD PACKAGE INFORMATION" << MED_TAB << endl << endl;
	fout << "                  Name              Object ID            Zip Code             "
		<< "Cost Of Shipping" << endl;
	fout << "             ---------------       -----------          ----------         "
		<< "---------------------" << endl;
	for (int i = 0; i < 10; i++)
	{
		if (pArray[i].getName() != "")
			pArray[i].print(fout);
	}

	fout << endl << endl << endl;

	fout << "             OVERNIGHT print function running . . . " << endl << endl;
	fout << LONG_TAB << "OVERNIGHT PACKAGE INFORMATION" << MED_TAB << endl << endl;
	fout << "                  Name              Object ID            Zip Code                "
		<< "Cost Of Shipping" << endl;
	fout << "             ---------------       -----------          ----------         "
		<< "--------------------------" << endl;
	for (int i = 0; i < 10; i++)
	{
		if (oArray[i].getName() != "")
			oArray[i].print(fout);
	}

	fout << endl << endl << endl;

	fout << "             TWO DAY PACKAGE print function running . . . " << endl << endl;
	fout << LONG_TAB << "TWO DAY PACKAGE INFORMATION" << MED_TAB << endl << endl;
	fout << "                  Name              Object ID            Zip Code                "
		<< "Cost Of Shipping" << endl;
	fout << "             ---------------       -----------          ----------         "
		<< "--------------------------" << endl;
	for (int i = 0; i < 10; i++)
	{
		if (tArray[i].getName() != "")
			tArray[i].print(fout);
	}

	fout << endl << endl << endl;

	// DEMONSTRATING STREAM INSERTION OPERATOR
	fout << "            -------------------------------------------------------- " << endl
		<< "             Demonstrating overloaded stream insertion operator . . . " << endl
		<< "             -------------------------------------------------------- " << endl;
	for (int i = 0; i < 10; i++)
	{
		if (pArray[i].getName() != "")
			fout << pArray[i];
	}

	cout << endl << endl;

	cout << "PACKAGE destructors running . . . " << endl;
	delete[] pArray;


	cout << endl << endl << "TWO DAY PACKAGE destructors running . . . " << endl;
	delete[] tArray;


	cout << endl << endl << "OVERNIGHT destructors running . . . " << endl;
	delete[] oArray;


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

