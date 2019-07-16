#include <iostream>

#include "OurStack.h"

int main()
{
	OurStack<int> numbers;

	for (int number = 0; number < 10; number++)
	{
		numbers.push(number);
	}

	while (!numbers.isEmpty())
	{
		cout << numbers.peek() << endl;
		numbers.pop();
	}

	OurStack<OurStack<char>> *letters = new OurStack<OurStack<char>>();

	for (int stackNumber = 0; stackNumber < 5; stackNumber++)
	{
		OurStack<char> *newStack = new OurStack<char>();
		letters->push(*newStack);
		for (int letter = 65; letter < 65 + 26; letter + stackNumber)
		{
			letters->peek().push(letter);
		}
	}

	while (!letters->isEmpty())
	{
		while (!letters->peek().isEmpty())
		{
			cout << letters->peek().peek() << endl;
			letters->peek().pop();
		}
		letters->pop();
	}


	system("pause");
	return 0;
}