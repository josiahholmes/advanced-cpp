//Josiah Holmes
//CSIS 112 � Spring 2016
//Lab 6 - Savings Account Class.
//Date.cpp - implementation file for class Date.

#include <iostream>
#include "Date.h"
using namespace std;

Date::Date(int mn, int dy, int yr)
	: month(mn),
	day(dy),
	year(yr)
{
	cout << "Date object constructor for " << month << '/' << day << '/' << year << endl;
}


Date::~Date()
{
	cout << "Date object destructor for " << month << '/' << day << '/' << year << endl;
}


void Date::print(ofstream &output) const
{
	output << month << '/' << day << '/' << year;
}