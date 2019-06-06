#include <iostream>
#include <list>
#include <queue>
#include <stack>

using namespace std;

class SortedVector
{
private:
	vector<int> numbers;
public:
	void addNumber(int number)
	{
		vector<int>::iterator iter = numbers.begin();
		while (iter != numbers.end() && *iter < number)
		{
			iter++;
		}
		numbers.insert(iter, number);
	}
	friend ostream& operator<<(ostream& os, const SortedVector& sortedVector)
	{
		for (int index = 0; index < sortedVector.numbers.size(); index++)
		{
			os << sortedVector.numbers.at(index) << " ";
		}
		return os;
	}
};


void convertIntegerToBinaryWithStack(int number)
{
	stack<char> binaryDigits;
	// first in last out
	// first in should be 2^0
	// last in should be 2^30

	while (number > 0)
	{
		if (number % 2 == 0)
		{
			binaryDigits.push('0');
		}
		else
		{
			binaryDigits.push('1');
		}
		number /= 2;
	}

	while (!binaryDigits.empty())
	{
		cout << binaryDigits.top();
		binaryDigits.pop();
	}
	cout << endl;
}

void convertIntegerToBinaryWithQueue(int number)
{
	queue<char> binaryDigits;
	// first in first out
	// first in should be 2^30
	// last in should be 2^0

	for (int exponent = 30; exponent >= 0; exponent--)
	{
		if (number >= pow(2, exponent))
		{
			if (number / pow(2, exponent) == 0)
			{
				binaryDigits.push('0');
			}
			else
			{
				binaryDigits.push('1');
			}
		}
	}

	while (!binaryDigits.empty())
	{
		cout << binaryDigits.front();
		binaryDigits.pop();
	}
	cout << endl;
}

void convertNumberWithQueueAndStack(int number)
{
	cout << number << " converted to binary:" << endl;

	cout << "With a queue: ";
	convertIntegerToBinaryWithQueue(number);
	cout << "With a stack: ";
	convertIntegerToBinaryWithStack(number);
}

int main()
{
	SortedVector sortedNumbers;

	sortedNumbers.addNumber(5);
	sortedNumbers.addNumber(7);
	sortedNumbers.addNumber(3);
	sortedNumbers.addNumber(2);
	sortedNumbers.addNumber(11);

	cout << sortedNumbers << endl;

	convertNumberWithQueueAndStack(0);

	convertNumberWithQueueAndStack(255);

	convertNumberWithQueueAndStack(2147483647);

	system("pause");
	return 0;
}