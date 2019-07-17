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

	OurStack<OurStack<char>> letters;

	for (int stackNumber = 1; stackNumber <= 5; stackNumber++)
	{
		OurStack<char> newStack;
		for (int letter = 65; letter < 65 + 26; letter += stackNumber)
		{
			newStack.push(letter);
		}
		letters.push(newStack);
	}

	while (!letters.isEmpty())
	{
		OurStack<char> stack = letters.peek();
		while (!stack.isEmpty())
		{
			cout << stack.peek() << endl;
			stack.pop();
		}
		letters.pop();
	}


	system("pause");
	return 0;
}