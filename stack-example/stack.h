#ifndef STACK_H
#define STACK_H

#include <string>
using namespace std;

const int MAX_SIZE = 100;

//A stack of strings
class Stack {
public:
	//Stack operations
	void Push(string s);	//Adds 's' to the top of the stack

	string Pop();			//Returns the item at the top of the stack and removes
							//it from the stack
	string Peek() const;	//Returns the item at the top of the stack without removing it

	int Size() const;		//Returns the size of the stack

	bool isEmpty() const;	//Returns true if the stack is empty, false otherwise

	bool isFull() const;	//Returns true if the stack is full, false otherwise

	int Capacity() const;

private:
	string stack[MAX_SIZE];
	int size = 0;				//Current size of the stack
	int capacity = MAX_SIZE;	//Capacity of the stack
};

#endif