#include "binHeap.h"

// ***CODE FOR BREADTH-FIRST TRAVERSAL ITERATOR*** //

binHeap::bftIterator::bftIterator(int start, stack &heap)
{
	current = start;
	curHeap = heap;
}

binHeap::bftIterator::~bftIterator()
{
	delete this;
}

iterator *binHeap::createBftIterator()
{
	return new bftIterator(0, heap);
}

int binHeap::bftIterator::next()
{
	if (hasNext())
		return curHeap[current++];
}

bool binHeap::bftIterator::hasNext()
{
	if (current < curHeap.getSize()) // As long as the stack isn't empty the next element is there (except for the first iteration of the traversal)
		return true;
	else
		return false;
}

///////////////////////////////////////////////////


// ***CODE FOR DEPTH-FIRST TRAVERSAL ITERATOR*** //

binHeap::dftIterator::dftIterator(int start, stack &heap)
{
	if (!heap.isEmpty())
	{
		current = start; // Setting current index to start
		curHeap = heap;
		travSt.push(start); // Initialising traversal stack
	}
}

binHeap::dftIterator::~dftIterator()
{
	travSt.clear(); // Clearing the stack
	delete this; // Deallocating memory
}

iterator *binHeap::createDftIterator()
{
	return new dftIterator(0, heap); // Returning a new dftIterator object
}

int binHeap::dftIterator::next()
{
	if (hasNext())
	{
		travSt.pop(); // Deleting top element from the stack

		if (current * 2 + 2 < curHeap.getSize()) // If right child of current node exists
			travSt.push(current * 2 + 2); // Pushing the right child to the top
		if (current * 2 + 1 < curHeap.getSize()) // If left child of current node exists
			travSt.push(current * 2 + 1); // Pushing the left child to the top


		int temp = curHeap[current];
		current = travSt.getTop(); // Setting current to the top of the stack
		return temp;
	}
}

bool binHeap::dftIterator::hasNext()
{
	if (!travSt.isEmpty()) // As long as the stack isn't empty the next element is there (except for the first iteration of the traversal)
		return true;
	else
		return false;
}

///////////////////////////////////////////////////


// ***CODE FOR BINARY HEAP CLASS*** //
binHeap::binHeap()
{
	heap;// Initialising the heap as an empty vector
}

binHeap::~binHeap()
{
	if(!heap.isEmpty())
		heap.clear(); // Clearing the vector
}

bool binHeap::contains(int data)
{
	if (!heap.isEmpty())
	{
		for (int i = 0; i < heap.getSize(); i++)
			if (heap[i] == data)
				return true;
		return false;
	}
}

void binHeap::swap(int key1, int key2)
{
	int temp = heap[key1];
	heap[key1] = heap[key2];
	heap[key2] = temp;
}

void binHeap::insert(int data)
{
	heap.push(data); // Inserting at the end

	// up-heap operation
	int i = heap.getSize() - 1;
	while (heap[i] > heap[(i - 1) / 2])
	{
		swap((i - 1) / 2, i);
		i = (i - 1) / 2;
	}
}

void binHeap::remove(int data)
{
	if (!heap.isEmpty())
	{
		int i = 0;

		while (heap[i] != data && i < heap.getSize()) // Finding index of element with data = 'data'
			i++;

		swap(heap.getSize() - 1, i); // Swapping element we want to delete with the last element

		heap.pop(); // Deleting the element we wanted to delete

		// down-heap operation
		while (heap[i] < heap[2 * i + 1] || heap[i] < heap[2 * i + 2]) // As long as the heap property isn't restored
		{
			// Next two if's figure out which child is the largest and swap the current element with that largest child
			if (heap[2 * i + 1] > heap[2 * i + 2])
			{
				swap(2 * i + 1, i);
				i = 2 * i + 1;
			}
			else if (heap[2 * i + 2] > heap[2 * i + 1])
			{
				swap(2 * i + 2, i);
				i = 2 * i + 2;
			}


			if (2 * i + 1 < heap.getSize() & 2 * i + 2 >= heap.getSize()) // If the current node's child is the last element
			{
				if (heap[i] < heap[2 * i + 1]) // If the heap property isn't restored
					swap(2 * i + 1, i);
				break; // Now the heap property is restored and we can safely exit the loop
			}
			else if (2 * i + 1 >= heap.getSize() || 2 * i + 2 >= heap.getSize()) // If the current node has no children then the heap property is restored
				break;
		}
	}
}

stack binHeap::getHeap()
{
	return heap;
}