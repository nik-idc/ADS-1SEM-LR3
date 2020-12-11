#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../binHeap.h"

namespace LR3UT
{
	TEST_CLASS(LR3UT)
	{
	public:
		TEST_METHOD(TestInsert) // Test method to test the 'insert' method
		{
			binHeap bh;

			for (int i = 0; i < 10;)
				bh.insert(++i);

			// bh will look like this:
			//				10
			//			  /    \
			//			 9      6
			//         /  \    /  \
			//        7   8    2   5
			//       /\   |
			//      1  4  3
			//////////////////////////

			int arr[] = { 10, 9, 6, 7, 8, 2, 5, 1, 4, 3 };

			stack heapVec(arr, 10); // heapVec - a vector that is supposed to represent bh

			Assert::IsTrue(bh.getHeap() == heapVec); // Some issue with destructors, prolly need a copy constructor or some other shtick
		}
		
		TEST_METHOD(TestBFTIterator)
		{
			binHeap bh;

			for (int i = 0; i < 10;)
				bh.insert(++i);

			// bh will look like this:
			//				10
			//			  /    \
			//			 9      6
			//         /  \    /  \
			//        7   8    2   5
			//       /\   |
			//      1  4  3
			//////////////////////////

			int bftArr[] = { 10, 9, 6, 7, 8, 2, 5, 1, 4, 3 };

			stack trav1(bftArr, 10), trav2; // trav1 - vector of bft on bh, trav2 - vector that will be filled with node values during bft

			iterator *it = bh.createBftIterator();
			int cur = 0;
			while (it->hasNext())
			{
				cur = it->next();
				trav2.push(cur);
			}

			Assert::IsTrue(trav1 == trav2);
		}

		TEST_METHOD(TestDFTIterator) // Test method for testing the dftIterator class
		{
			binHeap bh;

			for (int i = 0; i < 10;)
				bh.insert(++i);

			// bh will look like this:
			//				10
			//			  /    \
			//			 9      6
			//         /  \    /  \
			//        7   8    2   5
			//       /\   |
			//      1  4  3
			//////////////////////////

			int dftArr[] = { 10, 9, 7, 1, 4, 8, 3, 6, 2, 5 };

			stack trav1(dftArr, 10), trav2; // trav1 - vector of dft on bh, trav2 - vector that will be filled with node values during dft

			iterator *it = bh.createDftIterator();
			int cur = 0;
			while (it->hasNext())
			{
				cur = it->next();
				trav2.push(cur);
			}

			Assert::IsTrue(trav1 == trav2);
		}

		TEST_METHOD(TestContains) // Test method to test the 'contains' method
		{
			binHeap bh;

			for (int i = 0; i < 10;)
				bh.insert(++i);

			for (int i = 0; i < 10;)
				Assert::IsTrue(bh.contains(++i));
		}

		TEST_METHOD(TestRemove) // Test method to test the 'remove' method
		{
			binHeap bh;

			for (int i = 0; i < 10;)
				bh.insert(++i);

			// bh before root removal:		--> bh after root removal
			//				10				-->				9		
			//			  /    \			-->			  /    \	
			//			 9      6			-->			 8      6	
			//         /  \    /  \			-->         / \    /  \	
			//        7   8    2   5		-->        7   3  2   5
			//       /\   |					-->       /\   			
			//      1  4  3					-->      1  4  			
			/////////////////////////////////////////////////////////

			int arr[] = { 9, 8, 6, 7, 3, 2, 5, 1, 4 };

			stack heapVec(arr, 9); // bh vector after root removal

			bh.remove(10);

			Assert::IsTrue(bh.getHeap() == heapVec);
		}
	};
}
