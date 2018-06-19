//Josiah Holmes
//CSIS 112 - Spring 2016
//Rectangle.cpp - Implementation file for class Rectangle


#include "Rectangle.h"
using namespace std;


Rectangle::Rectangle(int w, int l)
{
	setLength(l);
	setWidth(w);
	cout << "Constructor running for " << getWidth() <<
		" x " << getLength() << " rectangle." << endl;
}


Rectangle::~Rectangle()
{
	cout << "Destructor running for " << getWidth() <<
		" x " << getLength() << " rectangle." << endl;
}


void Rectangle::setLength(int argLength)
{
	if ((argLength == 0) || (argLength < 1 || argLength > 10))
		length = 1;
	else
		length = argLength;
}


void Rectangle::setWidth(int argWidth)
{
	if ((argWidth == 0) || (argWidth < 1 || argWidth > 10))
	{
		width = length;
		setLength(1);
	}
	else
		width = argWidth;
}


int Rectangle::getLength()
{
	return length;
}


int Rectangle::getWidth()
{
	return width;
}


void Rectangle::printRectangle(ofstream& fout)
{
	fout << getWidth() << " x " << getLength() << endl;
	printTopBottom(fout);
	if (getLength() > 1)
	{
		printBody(fout);
		printTopBottom(fout);
	}
	fout << endl << endl;
}


void Rectangle::printTopBottom(ofstream& fout)
{
	for (int i = 1; i <= getWidth(); i++)
		fout << "*";
	fout << endl;
}


void Rectangle::printBody(ofstream& fout)
{
	for (int i = 1; i <= getLength() - 2; i++)
		fout << "*" << setw(getWidth() - 1) << "*" << endl;
}