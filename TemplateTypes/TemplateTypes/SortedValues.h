#pragma once

#include <iostream>
#include <exception>

using namespace std;

template <typename T>
class SortedItems
{
private:
	T first;
	T second;
	T third;
	T fourth;
	T fifth;
	int numberOfItems;
public:
	SortedItems()
	{
		numberOfItems = 0;
	}
	void Add(T item)
	{
		if (numberOfItems == 0)
		{
			first = item;
		}
		else if (numberOfItems == 1)
		{
			if (item > first)
			{
				second = item;
			}
			else
			{
				second = first;
				first = item;
			}
		}
		else if (numberOfItems == 2)
		{
			if (item > second)
			{
				third = item;
			}
			else if (item > first)
			{
				third = second;
				second = item;
			}
			else
			{
				third = second;
				second = first;
				first = item;
			}
		}
		else if (numberOfItems == 3)
		{
			if (item > third)
			{
				fourth = item;
			}
			else if (item > second)
			{
				fourth = third;
				third = item;
			}
			else if (item > first)
			{
				fourth = third;
				third = second;
				second = item;
			}
			else
			{
				fourth = third;
				third = second;
				second = first;
				first = item;
			}
		}
		else if (numberOfItems == 4)
		{
			if (item > fourth)
			{
				fifth = item;
			}
			else if (item > third)
			{
				fifth = fourth;
				fourth = item;
			}
			else if (item > second)
			{
				fifth = fourth;
				fourth = third;
				third = item;
			}
			else if (item > first)
			{
				fifth = fourth;
				fourth = third;
				third = second;
				second = item;
			}
			else
			{
				fifth = fourth;
				fourth = third;
				third = second;
				second = first;
				first = item;
			}
		}
		else
		{
			throw invalid_argument("Full!");
		}
		numberOfItems++;
	}

	void Print()
	{
		if (numberOfItems > 0)
		{
			cout << "1: " << first << endl;
		}
		if (numberOfItems > 1)
		{
			cout << "2: " << second << endl;
		}
		if (numberOfItems > 2)
		{
			cout << "3: " << third << endl;
		}
		if (numberOfItems > 3)
		{
			cout << "4: " << fourth << endl;
		}
		if (numberOfItems > 4)
		{
			cout << "5: " << fifth << endl;
		}
	}
};