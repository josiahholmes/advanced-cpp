//Josiah Holmes
//CSIS 112 - Spring 2016
//Rectangle.h - Interface file for class Rectangle

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
public:
	Rectangle(int = 1, int = 1);
	~Rectangle();
	void setLength(int);
	void setWidth(int);
	int getLength();
	int getWidth();
	void printRectangle(ofstream&);
private:
	int length,
		width;
	void printTopBottom(ofstream&);
	void printBody(ofstream&);
};

#endif