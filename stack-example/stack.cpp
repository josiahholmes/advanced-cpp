#include "stack.h"
#include <string>
#include <iostream>
using namespace std;

bool Stack::isFull() const {
	if (size < capacity)
		return false;
	else
		return true;
}

bool Stack::isEmpty() const {
	if (size == 0)
		return true;
	else
		return false;
}

int Stack::Size() const {
	return size;
}

string Stack::Peek() const {
	if (!isEmpty())
		return stack[size - 1];
	else
		cout << "The stack is empty!!!\n";
}

string Stack::Pop() {
	if (!isEmpty())
		return stack[--size];
	else
		cout << "The stack is empty!!!\n";
}

int Stack::Capacity() const {
	return capacity;
}

void Stack::Push(string s){
	if (!isFull())
		stack[size++] = s;
	else
		cout << "Stack is full!!!\n";
}