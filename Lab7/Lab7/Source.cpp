#include <iostream>
#include <time.h>
#include "SortedLinkedList.h"

using namespace std;

int main()
{
	srand(time(NULL));

	SortedLinkedList<int> sortedInts;

	for (int number = 0; number < 10; number++)
	{
		sortedInts.Add(rand());
	}

	for (int index = 0; index < sortedInts.size(); index++)
	{
		cout << sortedInts.at(index) << endl;
	}

	sortedInts.remove(0);

	sortedInts.remove(sortedInts.size() - 1);

	sortedInts.remove(3);

	for (int index = 0; index < sortedInts.size(); index++)
	{
		cout << sortedInts.at(index) << endl;
	}

	system("pause");
	return 0;
}