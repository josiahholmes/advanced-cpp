//Josiah Holmes
//CSIS 112 - Spring 2016
//Rectangles Lab.      This lab reads an unknown pair of numbers from a file,
//                     stores each pair of numbers in variables labeled length
//                     and width in an array, and prints out graphical rectangles
//                     based on the length and width provided.

#include "Rectangle.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


int main()
{
	cout << endl << "Running . . . " << endl;
	cout << "                            Console Output" << endl << endl << endl;


	//  DEFINITIONS
	bool  noErrors = true;
	char  exit;
	ofstream fout,
		errOut;
	ifstream fin;
	Rectangle arrayOfRectangles[7],
		standalone, // STANDALONE RECTANGLE
		&rectangleRef = arrayOfRectangles[0], // REFERENCE OBJECT POINT TO FIRST ELEMENT
		*rectanglePtr = &arrayOfRectangles[2]; // POINTER OBJECT POINTING TO THIRD ELEMENT
	int length = 0,
		width = 0,
		i = 0;


	//  ADMINISTRATIVE STUFF
	fout.open("output.txt");
	errOut.open("error.txt");
	fout << "                            Rectangles" << endl << endl << endl;
	errOut << "                            ***  Error Report  ***" << endl << endl << endl;
	fin.open("numbers.dat");


	cout << endl << "Reading input file . . . " << endl << endl;
	cout << "Input file integers: " << endl;


	//  PROGRAM LOGIC
	for (; fin >> width >> length;)
	{
		cout << width << " " << length << " ";

		if ((width < 1 || width > 10) || (length < 1 || length > 10))
		{
			noErrors = false;
			errOut << "*** ERROR: Pair (" << width << ", " << length << ") has a "
				<< "width and/or length that " << endl << "           does not fit "
				<< "in the range of 1 and 10. " << endl << endl;
		}

		if (i > 6)
		{
			noErrors = false;
			errOut << "*** ERROR: Pair (" << width << ", " << length 
				<< ") has been ignored. Seven pairs of "  << endl 
				<< "           integers have been read from the input file." << endl << endl;
			break;
		}

		arrayOfRectangles[i].setLength(length);
		arrayOfRectangles[i].setWidth(width);

		i++;

	}


	// MEMBER-WISE ASSIGNMENT
	standalone = arrayOfRectangles[1];


	// PRINTING RECTANGLES TO MAIN REPORT FILE
	rectangleRef.printRectangle(fout); // REFERENCE NOTATION
	standalone.printRectangle(fout);
	rectanglePtr->printRectangle(fout); // POINTER NOTATION


	for (int i = 3; i < 7; i++) // FOR-LOOP TO PRINT REMAINING RECTANGLES
		arrayOfRectangles[i].printRectangle(fout);


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