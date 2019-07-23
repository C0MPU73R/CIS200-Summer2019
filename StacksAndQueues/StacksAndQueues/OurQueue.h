#pragma once
#include "LinkedList.h"

using namespace std;

template <typename T>
class OurQueue
{
private:
	LinkedList<T> items;
public:
	void enqueue(T data)
	{
		items.addToBack(data);
	}

	void dequeue()
	{
		items.remove(0);
	}

	T front()
	{
		return items.at(0);
	}

	bool isEmpty()
	{
		return items.isEmpty();
	}
};