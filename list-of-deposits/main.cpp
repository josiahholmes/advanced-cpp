//Josiah Holmes
//CSIS 112 � Spring 2016
//Lab 2 � List of Deposits. This program reads an input file containing deposits
//                that have been made to a bank, and writes a report of all 
//                valid deposits made.

#include <fstream>
#include <iostream>
#include "Deposit.h"
#include <string>
using namespace std;

const string ID = "Josiah Holmes - CSIS 112(2), Spring 2016 - Lab2";


int main()
{
	cout << endl << "Running Lab2 . . . " << endl << endl;
	cout << "              " << ID << endl;
	cout << "                             Console Output" << endl << endl << endl;


	//  DEFINITIONS
	bool  noErrors = true;
	char  exit;
	int inMonth,                  // input month variable for file
		inDay,                    // input day variable for file
		inYear,                   // input year variable for file
		mondayCount = 0,          // count keeps track of Monday deposits
		tuesdayCount = 0,         // count keeps track of Tuesday deposits
		wednesdayCount = 0,       // count keeps track of Wednesday deposits
		thursdayCount = 0,        // count keeps track of Thursday deposits
		fridayCount = 0,          // count keeps track of Friday deposits
		totalCount = 0;           // The total count of valid deposits in the file
	double inAmount;              // input amount variable for file
	ofstream fout,
		errOut;
	ifstream fin;


	// CLASS DEPOSIT OBJECTS
	Deposit Monday;
	Deposit Tuesday;
	Deposit Wednesday;
	Deposit Thursday;
	Deposit Friday;
	

	//  ADMINISTRATIVE STUFF
	fout.open(ID + ".out");
	errOut.open(ID + ".err");
	fout << "                         " << ID << endl;
	fout << "                                          Main Report" << endl << endl << endl;
	errOut << "                         " << ID << endl;
	errOut << "                                    ***  Error Report  ***" << endl << endl << endl;
	fin.open("Lab2.dat");


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
	cout << endl << "Reading input file . . . " << endl << endl << endl;

	//  Reading input file and executing data validation
	for (; fin >> inMonth >> inDay >> inYear >> inAmount;)
	{
		if (inAmount < 0.00)
		{
			if (inMonth < 10)
			{
				cout << "    ****Error: Amount cannot be negative, " << inAmount << " on 0" << inMonth << "/" << inDay << "/" << inYear << endl;
				errOut << "  **** ERROR: Deposit has a negative balance, " << inAmount << " on 0" << inMonth << "/" << inDay << "/" << inYear << endl;
				noErrors = false;
			}
			else
			{
				cout << "    ****Error: Amount cannot be negative,  " << inAmount << " on " << inMonth << "/" << inDay << "/" << inYear << endl;
				errOut << "  **** ERROR: Deposit has a negative balance, " << inAmount << " on " << inMonth << "/" << inDay << "/" << inYear << endl;
				noErrors = false;
			}
			continue;
		}
		else if (inMonth < 1 || inMonth > 12)
		{
			if (inMonth < 10)
			{
				cout << "    ****Error: Month must be in the range of 1 to 12. Date was  0" << inMonth << "/" << inDay << "/" << inYear << endl;
				errOut << "  **** ERROR: Month is not in the range of 1 to 12: 0" << inMonth << "/" << inDay << "/" << inYear << endl;
				noErrors = false;
			}
			else
			{
				cout << "    ****Error: Month must be in the range of 1 to 12. Date was  " << inMonth << "/" << inDay << "/" << inYear << endl;
				errOut << "  **** ERROR: Month is not in the range of 1 to 12: " << inMonth << "/" << inDay << "/" << inYear << endl;
				noErrors = false;
			}
			continue;
		}
		else if (inDay < 1 || inDay > 31)
		{
			if (inMonth < 10)
			{
				cout << "    ****Error: Day must range between 1 and 31. Date was 0" << inMonth << "/" << inDay << "/" << inYear << endl;
				errOut << "  **** ERROR: Day does not range between 1 and 31. Date was 0" << inMonth << "/" << inDay << "/" << inYear << endl;
				noErrors = false;
			}
			else
			{
				cout << "    ****Error: Day must range from 1 to 31. Date was " << inMonth << "/" << inDay << "/" << inYear << endl;
				errOut << "  **** ERROR: Day does not range between 1 and 31. Date was " << inMonth << "/" << inDay << "/" << inYear << endl;
				noErrors = false;
			}
			continue;
		}
		else if (inYear < 2000)
		{
			if (inMonth < 10)
			{
				cout << "    ****Error: Year must be greater than or equal to 2000. Date was  0" << inMonth << "/" << inDay << "/" << inYear << endl;
				errOut << "  **** ERROR: Year is not greater than or equal to 2000: 0" << inMonth << "/" << inDay << "/" << inYear << endl;
				noErrors = false;
			}
			else
			{
				cout << "    ****Error: Year must be greater than or equal to 2000. Date was  " << inMonth << "/" << inDay << "/" << inYear << endl;
				errOut << "  **** ERROR: Year is not greater than or equal to 2000: " << inMonth << "/" << inDay << "/" << inYear << endl;
				noErrors = false;
			}
			continue;
		}
		else                           // Day modulus 5 places amount in correct object.
		{
			if (inDay % 5 == 0)
			{
				Monday.setDayOfWeek("Monday");             // Day of week is set according to object.
				Monday.setDate(inMonth, inDay, inYear);    // The date for the deposit is stored.
				Monday.setDeposit(inAmount);               // The amount is stored in the array.
				mondayCount++;                             // Count for specific day is incremented for every deposit for that day.
			}
			else if (inDay % 5 == 1)
			{
				Tuesday.setDayOfWeek("Tuesday");
				Tuesday.setDate(inMonth, inDay, inYear);
				Tuesday.setDeposit(inAmount);
				tuesdayCount++;
			}
			else if (inDay % 5 == 2)
			{
				Wednesday.setDayOfWeek("Wednesday");
				Wednesday.setDate(inMonth, inDay, inYear);
				Wednesday.setDeposit(inAmount);
				wednesdayCount++;
			}
			else if (inDay % 5 == 3)
			{
				Thursday.setDayOfWeek("Thursday");
				Thursday.setDate(inMonth, inDay, inYear);
				Thursday.setDeposit(inAmount);
				thursdayCount++;
			}
			else if (inDay % 5 == 4)
			{
				Friday.setDayOfWeek("Friday");
				Friday.setDate(inMonth, inDay, inYear);
				Friday.setDeposit(inAmount);
				fridayCount++;
			}
		}
		totalCount++;                                 // Total count is incremented after each loop
	}                                                 // in order to count the total number of valid
	                                                  // deposits. 
	
	Monday.setCount(mondayCount);                     // Total count for each weekday is stored in count variable in class Deposit.
	Tuesday.setCount(tuesdayCount);
	Wednesday.setCount(wednesdayCount);
	Thursday.setCount(thursdayCount);
	Friday.setCount(fridayCount);


	cout << endl << endl;
	cout << "File reading completed. A report file of deposits has been created . . . " << endl;

	 
	fout << "      TOTAL OF " << totalCount << " DEPOSITS:" << endl << endl << endl;
	Monday.displayDeposits(fout);          // Void function displays array elements for every deposit in a weekday.
	Tuesday.displayDeposits(fout);
	Wednesday.displayDeposits(fout);
	Thursday.displayDeposits(fout);
	Friday.displayDeposits(fout);
	fout << "      TOTAL of all deposits: " << Monday.getTotal() + Tuesday.getTotal() + Wednesday.getTotal() + Thursday.getTotal() + Friday.getTotal();
	fout << endl << endl;                  // ^---- The total for each weekday is added to the "grand total" amount of all deposits.


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

