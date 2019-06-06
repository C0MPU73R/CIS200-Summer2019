#pragma once
#include <vector>

using namespace std;

int numberOfEvenSummedRows(vector<vector<int>> &numbers)
{
	int numberOfRowsWithEvenSum = 0;
	for (int rowIndex = 0; rowIndex < numbers.size(); rowIndex++)
	{
		int sum = 0;
		for (int columnIndex = 0; columnIndex < numbers.at(rowIndex).size(); columnIndex++)
		{
			sum += numbers.at(rowIndex).at(columnIndex);
		}

		if (sum % 2 == 0)
		{
			numberOfRowsWithEvenSum++;
		}
	}

	return numberOfRowsWithEvenSum;
}

int numberOfOddSummedRows(vector<vector<int>> &numbers)
{
	return numbers.size() - numberOfEvenSummedRows(numbers);
}

double standardDeviation(vector<int> &numbers)
{
	double sum = 0;
	for (int &number : numbers)
	{
		sum += number;
	}
	double average = sum / numbers.size();

	double sumOfDifferencesSquared = 0;

	for (int &number : numbers)
	{
		sumOfDifferencesSquared += (number-average)*(number - average);
	}


	return sqrt(sumOfDifferencesSquared/numbers.size());
}