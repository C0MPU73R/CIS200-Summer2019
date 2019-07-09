#pragma once

#include <iostream>

using namespace std;

template<typename T>
class BetterSortedItems
{
private:
	T items[5];
	int numberOfItems;
	int currentStorageSize;
	void shiftRight(int indexToShiftFrom)
	{
		for (int index = numberOfItems; index > indexToShiftFrom; index--)
		{
			items[index] = items[index - 1];
		}
	}
	void checkCapacity()
	{
		if (numberOfItems == currentStorageSize)
		{
			T temp[currentStorageSize];
			
			temp = items;

			currentStorageSize *= 2;
			items = T[currentStorageSize];

			for (int index = 0; index < numberOfItems; index++)
			{
				items[index] = temp[index];
			}
		}
	}
public:
	BetterSortedItems()
	{
		currentStorageSize = 5;
		numberOfItems = 0;
	}

	void Add(T item)
	{
		checkCapacity();
		for (int index = 0; index <= numberOfItems; index++)
		{
			// we are at the end of the loop and must be bigger than everything else
			if (index == numberOfItems)
			{
				items[index] = item;
			}
			else if (item < items[index])
			{
				shiftRight(index);
				items[index] = item;
				break;
			}
		}
		numberOfItems++;
	}

	void Print()
	{
		for (int index = 0; index < numberOfItems; index++)
		{
			cout << index << ": " << items[index] << endl;
		}
	}
	
};