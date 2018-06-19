//Josiah Holmes
//CSIS 112 – Spring 2016
//Lab 8 - FedEx Part 2.
//Queue.h - interface file for class Queue.

#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>
using namespace std;

template<typename T>
class Queue
{
public:
	Queue(int s = 2)
		:size(s > 0 ? s : 2),
		front(-1), // Queue initially empty
		rear(-1), // Queue initially empty
		queuePtr(new T[s]), // allocate memory for elements
		sum(0), // sum of elements in queue
		count(0) // number of elements in queue
	{
		// empty body
	}

	~Queue()
	{
		delete[] queuePtr; // deallocate internal space for Queue
	}

	bool enqueue(const T &enqueueValue)
	{
		if (!isFull())
		{
			queuePtr[++rear] = enqueueValue; // place item on Queue
			sum += enqueueValue;
			count++;
			return true; // enqueue successful
		} // end if

		return false; // enqueue unsuccessful
	}

	bool dequeue(T &dequeueValue, ofstream &output)
	{
		if (!isEmpty())
		{
			dequeueValue = queuePtr[++front]; // remove item from Queue
			output << dequeueValue << ' ';
			return true; // dequeue successful
		} // end if
		
		return false; // dequeue unsuccessful
	}
	
	bool isFull() const
	{
		return (rear == size - 1);
	}

	bool isEmpty() const
	{
		return (front == size - 1);
	}

	T getQuotient() const
	{
		return sum / count;
	}

	T getSum() const
	{
		return sum;
	}

	T getCount() const
	{
		return count;
	}

	T zeroQuotient(T numerator, T denominator)
	{
		if (denominator == 0)
			throw runtime_error("attempted to divide by zero.");

		return numerator / denominator;
	}

private:
	int front,
		rear,
		sum,
		count;
	T * queuePtr;
	const int size;
};

#endif