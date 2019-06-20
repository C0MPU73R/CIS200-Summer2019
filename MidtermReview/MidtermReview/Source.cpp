#include <iostream>

using namespace std;

const int MAX = 5;



void _recursivePrintStringBackwards(string toReverse, int index)
{
	cout << toReverse.at(index);
	if (index != 0)
	{
		_recursivePrintStringBackwards(toReverse, index - 1);
	}
}

void recursivePrintStringBackwards(string toReverse)
{
	_recursivePrintStringBackwards(toReverse, toReverse.size() - 1);
}

void printStringBackwards(string toReverse)
{
	for (int index = toReverse.size() - 1; index >= 0; index--)
	{
		cout << toReverse.at(index);
	}
}

class IHasAPointer
{
private:
	int* number;
public:
	IHasAPointer(int number)
	{
		this->number = new int(number);
	}

	~IHasAPointer()
	{
		delete number;
	}

	IHasAPointer(IHasAPointer &other)
	{
		this->number = new int(*(other.number));
	}

	IHasAPointer operator=(const IHasAPointer &other)
	{
		delete number;
		this->number = new int(*(other.number));
		return *this;
	}

	void changeNumber(int number)
	{
		*(this->number) = number;
	}
	void printNumber()
	{
		cout << *number << endl;
	}
};

int recursiveSumOfIntegersNAndBelow(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	return (n + recursiveSumOfIntegersNAndBelow(n - 1));
}

int sumOfIntegersNAndBelow(int n)
{
	// this is not cheating
	// return n * (n+1) / 2;
	
	int sum = 0;
	for (int number = 1; number <= n; number++)
	{
		sum += number;
	}
	return sum;
}


class NumberGame
{
private:
	int numberOfGuesses;
	int magicNumber;
	bool guessedCorrectly;
public:
	NumberGame(int magicNumber)
	{
		this->magicNumber = magicNumber;
		numberOfGuesses = 0;
		guessedCorrectly = false;
	}

	void guess(int number)
	{
		if (guessedCorrectly)
		{
			cout << "You already guessed it!" << endl;
		}
		else
		{
			numberOfGuesses++;
			if (number < magicNumber)
			{
				cout << "Too low!" << endl;
			}
			else if (number > magicNumber)
			{
				cout << "Too high!" << endl;
			}
			else
			{
				cout << "You guessed it in " << numberOfGuesses << " guesses!" << endl;
				guessedCorrectly = true;
			}
		}
	}

};


int sumEdge(int nums[MAX][MAX])
{
	int sum = 0;

	for (int rowIndex = 0; rowIndex < MAX; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < MAX; columnIndex++)
		{
			if (rowIndex == 0 || columnIndex == 0 ||
				rowIndex == MAX - 1 || columnIndex == MAX - 1)
			{
				sum += nums[rowIndex][columnIndex];
			}
		}
	}

	return sum;
}


int sumCenter(int nums[MAX][MAX])
{
	int sum = 0;

	for (int rowIndex = 0; rowIndex < MAX; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < MAX; columnIndex++)
		{
			if (rowIndex != 0 && columnIndex != 0 &&
				rowIndex != MAX - 1 && columnIndex != MAX - 1)
			{
				sum += nums[rowIndex][columnIndex];
			}
		}
	}

	return sum;
}

int fib(int nth)
{
	if (nth == 1 || nth == 2)
	{
		return 1;
	}
	return fib(nth - 1) + fib(nth - 2);
}

int factorial(int nth)
{
	if (nth == 1 || nth == 0)
	{
		return 1;
	}
	return nth * factorial(nth - 1);
}

int main()
{
	recursivePrintStringBackwards("Deliver");



	IHasAPointer first(42);
	first.printNumber();

	IHasAPointer second(first);
	second.printNumber();

	first.changeNumber(100);

	first.printNumber();
	second.printNumber();

	second = first;

	first.changeNumber(0);

	first.printNumber();
	second.printNumber();



	char *alphabet;

	cout << "How many letters?" << endl;
	int size;
	cin >> size;

	alphabet = new char[size];

	delete [] alphabet;

	NumberGame game(42);

	game.guess(30);
	game.guess(50);
	game.guess(42);
	game.guess(101011);

	int *fib;

	cin >> size;
	fib = new int[size];

	int previous = 0;
	int current = 1;
	
	for (int index = 0; index < size; index++)
	{
		fib[index] = current;
		int temp = current;
		current += previous;
		previous = temp;
		cout << fib[index] << endl;
	}

	system("pause");
	return 0;
}