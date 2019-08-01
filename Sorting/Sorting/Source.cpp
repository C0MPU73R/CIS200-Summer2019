#include <iostream>
#include <vector>

using namespace std;

template <typename T>
vector<T> selectionSort(vector<T> items)
{
	for (int index = 0; index < items.size() - 1; index++)
	{
		T smallest = items[index];
		int indexOfSmallest = index;
		for (int indexOfPossibleSmaller = index + 1; indexOfPossibleSmaller < items.size(); indexOfPossibleSmaller++)
		{
			if (items[indexOfPossibleSmaller] < smallest)
			{
				smallest = items[indexOfPossibleSmaller];
				indexOfSmallest = indexOfPossibleSmaller;
			}
		}

		T temp = items[index];
		items[index] = items[indexOfSmallest];
		items[indexOfSmallest] = temp;

	}

	return items;
}

template <typename T>
vector<T> insertionSort(vector<T> items)
{
	for (int index = 1; index < items.size(); index++)
	{
		int currentIndex = index;

		while (currentIndex > 0 && items[currentIndex] < items[currentIndex - 1])
		{
			T temp = items[currentIndex];
			items[currentIndex] = items[currentIndex - 1];
			items[currentIndex - 1] = temp;
			currentIndex--;
		}

	}

	return items;
}

int main()
{
	cout << "How many numbers do you want sort?" << endl;
	int size;
	cin >> size;

	vector<int> numbers(size);

	for (int number = 0; number < size; number++)
	{
		cout << "Enter a number to add to the list" << endl;
		cin >> numbers[number];
	}

	vector<int> sortedInts = selectionSort(numbers);

	cout << endl << "Selection sort results:" << endl;
	for (int number : sortedInts)
	{
		cout << number << endl;
	}

	cout << endl << "Insertion sort results:" << endl;
	vector<int> sortedInts2 = insertionSort(numbers);
	for (int number : sortedInts2)
	{
		cout << number << endl;
	}

	system("pause");
	return 0;
}