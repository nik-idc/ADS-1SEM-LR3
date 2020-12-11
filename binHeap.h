#pragma once
#ifndef BINHEAP_H
#define BINHEAP_H

#include "stack.h"
#include "iterator.h"
#include <vector>

// NOTE: In this project binary heap is implemented using a vector (array). In this implementation breadth-first traversal is just linearly traversing the vector.
// As such, implementing a BFT iterator is unnecessary.

class binHeap
{
public:
	binHeap(); // Constructor
	
	~binHeap(); // Destructor

	class bftIterator : public iterator // Iterator class for breadth-first traversal
	{
	public:
		bftIterator(int start, stack &heap); // Constructor that takes in the starting index and the heap to traverse

		~bftIterator(); // Destructor

		int next() override; // Method that returns the next element

		bool hasNext() override; // Method that checks whether the next element exists
	private:
		int current; // Index of the current element in the array
		stack curHeap; // Copy of the heap passed in the constructor
	};

	iterator *createBftIterator(); // Returns a new object of dftIterator class

	class dftIterator : public iterator // Iterator class for depth-first traversal
	{
	public:
		dftIterator(int start, stack &heap); // Constructor that takes in the starting index and the heap to traverse

		~dftIterator(); // Destructor

		int next() override; // Method that returns the next element

		bool hasNext() override; // Method that checks whether the next element exists
	private:
		int current; // Index of the current element in the array
		stack curHeap; // Copy of the heap passed in the constructor
		stack travSt; // Stack for the DFT algorithm
	};

	iterator* createDftIterator(); // Returns a new object of dftIterator class

	bool contains(int data); // Checks whether an element with data = 'data' exists in the heap

	void swap(int key1, int key2); // Method that swaps two elements in the heap array

	void insert(int data); // Inserts an element in the heap

	void remove(int data); // Removes an element from the heap

	stack getHeap();
private:
	stack heap; // Heap vector
};

#endif 