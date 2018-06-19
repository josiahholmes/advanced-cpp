//Josiah Holmes
//CSIS 112 � Spring 2016
//Lab 6 - Savings Account Class.
//Date.h - interface file for class Date.

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <fstream>
using namespace std;

class Date
{
public:
	Date(int mn, int dy, int yr);
	~Date();
	void print(ofstream &output) const;
private:
	int month,
		day,
		year;
};

#endif