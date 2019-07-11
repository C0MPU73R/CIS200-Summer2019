#pragma once

#include <iostream>
#include <vector>

using namespace std;

class LuckyNumberChecker
{
private:
	int luckyDivisor;
public:
	LuckyNumberChecker(int luckyDivisor)
	{
		if (luckyDivisor <= 0)
		{
			throw invalid_argument("luckyDivisor cannot be <= 0");
		}
		this->luckyDivisor = luckyDivisor;
	}

	virtual string checkNumber(int number)
	{
		if (number % luckyDivisor == 0)
		{
			return "This number is lucky";
		}
		if (number % 2 == 1)
		{
			return "This number might be lucky";
		}
		return "This number is not lucky";
	}
};

class DoublyLuckyNumberChekcer : public LuckyNumberChecker
{
private:
	int superLuckyDivisor;
public:
	DoublyLuckyNumberChekcer(int superLuckyDivisor, int luckyDivisor) : LuckyNumberChecker(luckyDivisor)
	{
		this->superLuckyDivisor = superLuckyDivisor;
	}

	string checkNumber(int number)
	{
		if (number % superLuckyDivisor == 0)
		{
			return "This number is super lucky";
		}
		return LuckyNumberChecker::checkNumber(number);
	}

};

int whiteMinusBlackSquares(vector<vector<int>> numbers)
{
	int total = 0;
	for (int rowIndex = 0; rowIndex < numbers.size(); rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < numbers.at(rowIndex).size(); columnIndex++)
		{
			if (rowIndex % 2 == 0)
			{
				if (columnIndex % 2 == 0)
				{
					total += numbers.at(rowIndex).at(columnIndex);
				}
				else
				{
					total -= numbers.at(rowIndex).at(columnIndex);
				}
			}
			else
			{
				if (columnIndex % 2 == 0)
				{
					total -= numbers.at(rowIndex).at(columnIndex);
				}
				else
				{
					total += numbers.at(rowIndex).at(columnIndex);
				}
			}
		}
	}
	return total;
}

int RecursiveSumOfOddNumbersUpToN(int n)
{
	if (n == 1)
	{
		return 1;
	}
	if (n % 2 == 0)
	{
		return RecursiveSumOfOddNumbersUpToN(n - 1);
	}
	else
	{
		return n + RecursiveSumOfOddNumbersUpToN(n - 2);
	}
}

int SumOfOddNumbersUpToN(int n)
{
	int sum = 0;
	if (n % 2 == 0)
	{
		n--;
	}

	while (n >= 1)
	{
		sum += n;
		n -= 2;
	}

	return sum;
}