#include <iostream>

#include "OurStack.h"
#include "OurQueue.h"

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

	OurQueue<float> floats;

	floats.enqueue(1.1);
	floats.enqueue(2.3);
	floats.enqueue(4.5);
	floats.enqueue(6.7);
	floats.enqueue(8.9);

	while (!floats.isEmpty())
	{
		cout << floats.front() << endl;
		floats.dequeue();
	}


	system("pause");
	return 0;
}