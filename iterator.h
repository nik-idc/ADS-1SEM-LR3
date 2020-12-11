#pragma once
#ifndef ITERATOR_H
#define ITERATOR_H

class iterator // Base iterator class
{
public:
	virtual int next() = 0; // Returns the next element
	virtual bool hasNext() = 0; // Checks whether next element exists
};

#endif