#include "binHeap.h"
#include <iostream>

int main()
{
	binHeap bh;
	
	for (int i = 0; i < 10;)
		bh.insert(++i);
	
	stack bftTrav, dftTrav;
	
	iterator *it1 = bh.createBftIterator();
	int cur = 0;
	while (it1->hasNext())
	{
		cur = it1->next();
		bftTrav.push(cur);
	}
	
	iterator *it2 = bh.createDftIterator();
	cur = 0;
	while (it2->hasNext())
	{
		cur = it2->next();
		dftTrav.push(cur);
	}
	
	std::cout << "Breadth-first traversal vector: " << std::endl;
	for (int i = 0; i < 10;i++)
		std::cout << bftTrav[i] << " ";
	
	std::cout << std::endl;
	
	std::cout << "Depth-first traversal vector: " << std::endl;
	for (int i = 0; i < 10;i++)
		std::cout << dftTrav[i] << " ";

	return 0;
}