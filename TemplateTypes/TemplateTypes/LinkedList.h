#pragma once

using namespace std;

template <typename T>
class LinkedList
{
private:
	template <typename T>
	class Node
	{
	public:
		Node(T data, Node* next = nullptr)
		{
			this->data = data;
			this->next = next;
		}
		T data;
		Node<T> *next;
	};
	
	Node<T>* head;
	Node<T>* tail;
	int numberOfItems;
	
public:
	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
		numberOfItems = 0;
	}

	~LinkedList()
	{
		if (numberOfItems > 0)
		{
			Node<T>* currentNode = head;
			Node<T>* nextToDelete = currentNode->next;
			delete currentNode;
			while (nextToDelete != nullptr)
			{
				currentNode = nextToDelete;
				nextToDelete = currentNode->next;
				delete currentNode;
			}
		}
		head = nullptr;
		tail = nullptr;
	}

	int size()
	{
		return numberOfItems;
	}

	bool isEmpty()
	{
		return numberOfItems == 0;
	}

	void Add(T data)
	{
		if (head == nullptr)
		{
			head = new Node<T>(data);
			tail = head;
		}
		else
		{
			tail->next = new Node<T>(data);
			tail = tail->next;
		}
		numberOfItems++;
	}

	T at(int index)
	{
		if (index >= numberOfItems)
		{
			throw invalid_argument("Invalid index");
		}

		Node<T> *currentNode = head;

		for (int item = 0; item < index; item++)
		{
			currentNode = currentNode->next;
		}

		return currentNode->data;
	}

};