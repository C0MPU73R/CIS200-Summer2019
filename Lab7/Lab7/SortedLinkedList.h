#pragma once

using namespace std;

template <typename T>
class SortedLinkedList
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
	SortedLinkedList()
	{
		head = nullptr;
		tail = nullptr;
		numberOfItems = 0;
	}

	~SortedLinkedList()
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
			if (data <= head->data)
			{
				// new head
				Node<T> *newNode = new Node<T>(data, head);
				head = newNode;
			}
			else if (data >= tail->data)
			{
				// new tail
				Node<T> *newNode = new Node<T>(data);
				tail->next = newNode;
				tail = newNode;
			}
			else
			{
				// somewhere between 2 nodes
				Node<T> *currentNode = head;

				while (data > currentNode->next->data)
				{
					currentNode = currentNode->next;
				}

				Node<T> *newNode = new Node<T>(data, currentNode->next);
				currentNode->next = newNode;
			}

		}
		numberOfItems++;
	}

	void remove(int index)
	{
		if (index >= numberOfItems)
		{
			throw invalid_argument("Invalid index");
		}
		numberOfItems--;
		if (index == 0)
		{
			// remove head node
			Node<T> *toDelete = head;
			head = head->next;
			delete toDelete;
		}
		else 
		{
			// remove tail
			
			// get to node before the node you want to delete
			// save point to currentNode->next for deleting
			// set currentNode->next to currentNode->next->next to remove it from the list
			// delete saved pointer

			Node<T> *currentNode = head;
			for (int nodeNumber = 0; nodeNumber < index - 1; nodeNumber++)
			{
				currentNode = currentNode->next;
			}

			Node<T> *toDelete = currentNode->next;

			// update tail if index was last item
			if (index == numberOfItems)
			{
				tail = currentNode;
			}
			currentNode->next = currentNode->next->next;

			delete toDelete;
		}
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