//Josiah Holmes
//CSIS 112 � Spring 2016
//Lab 3 - GCD.  This program reads a file containing an unknown quanity of pairs of numbers,
//              and computes the greatest common divisor (GCD) between the two numbers. The
//              program also covers inline and overloaded functions, storing the first four
//              valid valuescof the file and using them as arguments in two functions of the
//              same name.


#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


const string ID = "Josiah Holmes - CSIS 112(2), Spring 2016 - Lab3";


int second_num = 12; // Global variable


int recursive_GCD(int inputNumOne, int inputNumTwo);
int iterative_GCD(int inputNumOne, int inputNumTwo);
void Mul_Sub(ofstream &fout, double validNumOne, int validNumTwo, int validNumThree = 9, int validNumFour = 11);
void printReport(ofstream &fout, int argNumOne, int argNumTwo);


inline void Mul_Sub(ofstream &fout, int validNumOne, int validNumTwo, int validNumThree, int validNumFour = 6)
{
	int total = 0;
	total = validNumOne * validNumTwo - validNumThree - validNumFour;
	fout << "        " << validNumOne << " * " << validNumTwo << " - " << validNumThree << " - " 
		<< validNumFour << " = " << total << endl;
}


int main()
{
	cout << endl << "Running Lab3 . . . " << endl;
	cout << "              " << ID << endl;
	cout << "                             Console Output" << endl << endl << endl;


	//  DEFINITIONS
	bool  noErrors = true;
	char  exit;
	int fileNum_X,
		fileNum_Y,
		first_num = 0,
		second_num = 0,
		third_num = 0,
		fourth_num = 0;
	double dFirstNum = 0;
	ofstream fout,
		errOut;
	ifstream fin;


	//  ADMINISTRATIVE STUFF
	fout.open(ID + ".out");
	errOut.open(ID + ".err");
	fout << "                         " << ID << endl;
	fout << "                                          Main Report" << endl << endl << endl;
	errOut << "                         " << ID << endl;
	errOut << "                                    ***  Error Report  ***" << endl << endl << endl;
	fin.open("Lab3.dat");


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
	cout << "Reading input file . . . " << endl << endl << endl;

	//  Reading input file and executing data validation
	for (int count = 1; fin >> fileNum_X >> fileNum_Y; count++)
	{
		if (fileNum_X < fileNum_Y)
		{
			cout << "       *** Error (line " << count << "): " << fileNum_X <<
				" is not greater than " << fileNum_Y << endl;
			errOut << "*** Error (line " << count << "): " << fileNum_X <<
				" is not greater than " << fileNum_Y << endl;
			noErrors = false;
			continue;
		}
		else if ((fileNum_X > fileNum_Y) && first_num == 0 && second_num == 0)
		{
			first_num = fileNum_X;
			second_num = fileNum_Y;
			dFirstNum = double(first_num) + .1; // Double variable stores the sum of first_num and .1
			printReport(fout, fileNum_X, fileNum_Y);
		}
		else if ((fileNum_X > fileNum_Y) && third_num == 0 && fourth_num == 0)
		{
			third_num = fileNum_X;
			fourth_num = fileNum_Y;
			printReport(fout, fileNum_X, fileNum_Y);
		}
		else
		{
			printReport(fout, fileNum_X, fileNum_Y);
		}
	}


	cout << endl << endl << "File reading completed . . . " << endl << endl << endl;
	cout << "A main output file containing valid numbers from the input file";
	cout << " and their" << endl << "greatest common divisor (GCD) has been created. The";
	cout << " first four valid" << endl << "numbers have also been saved in order to demonstrate";
	cout << " both inline" << endl << "and overloaded functions . . . " << endl; 

	
	fout << "Results of inline function:" << endl;
	Mul_Sub(fout, first_num, second_num, third_num, fourth_num);
	Mul_Sub(fout, first_num, ::second_num, third_num);
	fout << endl << endl;
	fout << "Results of overloaded function:" << endl;
	Mul_Sub(fout, dFirstNum, second_num, third_num, fourth_num);
	Mul_Sub(fout, dFirstNum, ::second_num, third_num);
	Mul_Sub(fout, dFirstNum, ::second_num);


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


int recursive_GCD(int inputNumOne, int inputNumTwo)
{
	if (inputNumTwo == 0)
	{
		return inputNumOne;
	}
	else
	{
		return recursive_GCD(inputNumTwo, inputNumOne % inputNumTwo);
	}
}


int iterative_GCD(int inputNumOne, int inputNumTwo)
{
	int iGCD = 0;
	for (int i = 1; i <= inputNumOne && i <= inputNumTwo; i++)
	{
		if (inputNumOne % i == 0 && inputNumTwo % i == 0)
		{
			iGCD = i;
		}
	}
	return iGCD;
}


void Mul_Sub(ofstream &fout, double validNumOne, int validNumTwo, int validNumThree, int validNumFour)
{
	double total = 0;
	total = validNumOne * validNumTwo - validNumThree - validNumFour;
	fout << "        " << validNumOne << " * " << validNumTwo << " - " << validNumThree << " - " 
		<< validNumFour << " = " << setprecision(1) << fixed << total << endl;
}


void printReport(ofstream &fout, int argNumOne, int argNumTwo)
{
	fout << "Given the input numbers " << argNumOne << " and " << argNumTwo;
	if (iterative_GCD(argNumOne, argNumTwo) == 1 && 
		recursive_GCD(argNumOne, argNumTwo) == 1)
	{
		fout << ", there is no GCD" << endl << endl;
		fout << endl << endl;
	}
	else
	{
		fout << ", the GCD" << endl;
		fout << "       as computed by the recursive function is " << 
			recursive_GCD(argNumOne, argNumTwo) << endl;
		fout << "       as computed by the iterative function is " <<
			iterative_GCD(argNumOne, argNumTwo) << endl;
		fout << endl << endl; 
	}
}