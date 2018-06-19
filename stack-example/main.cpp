#include "stack.h"
#include <string>
#include <iostream>
using namespace std;

int main(){
	//Instantiate a Stack object
	Stack myStack;

	//Test Stack methods
	bool full = myStack.isFull();
	if (full)
		cout << "The stack is full\n";
	else
		cout << "The stack is not full\n";

	//Test the Push() method
	myStack.Push("Josiah");
	cout << "Pushed Josiah" << endl;
	myStack.Push("Holmes");
	cout << "Pushed Holmes" << endl;

	//Test the isEmpty() method
	if (myStack.isEmpty())
		cout << "My stack is empty.";
	else
		cout << "My stack is not empty.";
	cout << endl << endl;

	//Test the Size() method
	cout << "The size of my stack is " << myStack.Size() << endl << endl;

	//Test the Peek() method
	cout << "The word that's at the top of the stack is " << myStack.Peek() << endl;
	cout << "The stack size is " << myStack.Size() << endl;
	
	//Test the Pop() method
	cout << "The word popped off the stack is " << myStack.Pop() << endl;
	cout << "The stack size is now " << myStack.Size() << endl << endl;

	//Close program
	system("pause");
	return 0;
}