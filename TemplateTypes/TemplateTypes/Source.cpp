#include <iostream>
#include <string>
#include "SortedValues.h"
#include "BetterSortedItems.h"

int main()
{
	SortedItems<int> sortedInts;
	sortedInts.Add(10);
	sortedInts.Add(6);
	sortedInts.Add(42);
	sortedInts.Add(1);

	sortedInts.Print();

	SortedItems<char> sortedChars;
	sortedChars.Add('T');
	sortedChars.Add('A');
	sortedChars.Add('N');
	
	sortedChars.Print();


	SortedItems<string> sortedStrings;
	sortedStrings.Add("Grace");
	sortedStrings.Add("Mohamed");
	sortedStrings.Add("Caleb");
	sortedStrings.Add("Tommy");
	sortedStrings.Add("Eric");
	sortedStrings.Print();


	BetterSortedItems<int> numbers;
	for (int number = 0; number < 20; number++)
	{
		numbers.Add(rand());
	}
	
	numbers.Print();

	system("pause");
	return 0;
}