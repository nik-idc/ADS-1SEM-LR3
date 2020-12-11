#pragma once
#ifndef STACK_H
#define STACK_H

#include "nodes.h"

class stack
{
public:
	// Constructor
	stack();

	// Construct from existing array
	stack(int* arr, int size);

	// Copy constructor
	stack(const stack& toCopy);

	// Destructor
	~stack();

	// Add an element to the stack
	void push(int data);

	// Delete element from stack
	int pop();

	// Return top element
	int getTop();

	// Check if the stack is empty
	bool isEmpty();

	// Clear the stack
	void clear();

	// Return size of the stack
	int getSize();

	// [] operator overload
	int& operator[](int ind);

	// = operator overload
	stack& operator=(const stack &rightStack);

	// == operator overload
	bool operator==(const stack& rightStack);
private:
	// The top node
	node *top;
	// Size variable
	int size;
};

#endif