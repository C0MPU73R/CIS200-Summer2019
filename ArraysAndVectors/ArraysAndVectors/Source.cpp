#include <iostream>
#include <vector>

using namespace std;

int sumOfVector(vector<int> numbers)
{
	int sum = 0;
	for (int index = 0; index < numbers.size(); index++)
	{
		numbers.at(index)++;
		sum += numbers.at(index);
	}
	return sum;
}

int main()
{
	int twoDimensionalArray[3][4] = { { 1,2,3,4 }, {5,6,7,8}, {9,10,11,12 } };
	
	for (int rowIndex = 0; rowIndex < 3; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < 4; columnIndex++)
		{
			cout << twoDimensionalArray[rowIndex][columnIndex] << " ";
		}
		cout << endl;
	}

	twoDimensionalArray[0][0] = 1;
	twoDimensionalArray[0][1] = 2;
	twoDimensionalArray[0][2] = 3;
	twoDimensionalArray[0][3] = 4;

	twoDimensionalArray[1][0] = 5;
	twoDimensionalArray[1][1] = 6;
	twoDimensionalArray[1][2] = 7;
	twoDimensionalArray[1][3] = 8;

	twoDimensionalArray[2][0] = 9;
	twoDimensionalArray[2][1] = 10;
	twoDimensionalArray[2][2] = 11;
	twoDimensionalArray[2][3] = 12;

	for (int rowIndex = 0; rowIndex < 3; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < 4; columnIndex++)
		{
			cout << twoDimensionalArray[rowIndex][columnIndex] << " ";
		}
		cout << endl;
	}

	vector<vector<int>> twoDimensionalVector = { { 1,2,3,4 }, {5,6,7,8}, {9,10,11,12 } };


	for (int rowIndex = 0; rowIndex < twoDimensionalVector.size(); rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < twoDimensionalVector.at(rowIndex).size(); columnIndex++)
		{
			cout << twoDimensionalVector.at(rowIndex).at(columnIndex) << " ";
		}
		cout << endl;
	}

	for (int rowIndex = 0; rowIndex < twoDimensionalVector.size(); rowIndex++)
	{
		cout << "the sum of row " << rowIndex << " is : " << sumOfVector(twoDimensionalVector.at(rowIndex));
		cout << endl;
	}


	for (int rowIndex = 0; rowIndex < twoDimensionalVector.size(); rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < twoDimensionalVector.at(rowIndex).size(); columnIndex++)
		{
			cout << twoDimensionalVector.at(rowIndex).at(columnIndex) << " ";
		}
		cout << endl;
	}



	// gives an error - this is a good thing
	// cout << twoDimensionalVector.at(3).at(3);

	system("pause");
	return 0;
}