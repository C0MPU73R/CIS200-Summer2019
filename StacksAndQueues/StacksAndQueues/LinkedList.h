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

	LinkedList& operator=(const LinkedList& rhs)
	{
		if (this != &rhs)
		{
			head = nullptr;
			tail = nullptr;
			numberOfItems = 0;

			Node<T> *rhsCurrentNode = rhs.head;

			if (rhsCurrentNode != nullptr)
			{
				Node<T> *currentNode = new Node<T>(rhsCurrentNode->data);
				head = currentNode;
				tail = currentNode;
				numberOfItems++;

				while (rhsCurrentNode->next != nullptr)
				{
					currentNode->next = new Node<T>(rhsCurrentNode->next->data);
					currentNode = currentNode->next;
					rhsCurrentNode = rhsCurrentNode->next;
					tail = currentNode;
					numberOfItems++;
				}
			}
		}

		return *this;
	}

	LinkedList(const LinkedList& rhs)
	{
		head = nullptr;
		tail = nullptr;
		numberOfItems = 0;

		Node<T> *rhsCurrentNode = rhs.head;

		if (rhsCurrentNode != nullptr)
		{
			Node<T> *currentNode = new Node<T>(rhsCurrentNode->data);
			head = currentNode;
			tail = currentNode;
			numberOfItems++;

			while (rhsCurrentNode->next != nullptr)
			{
				currentNode->next = new Node<T>(rhsCurrentNode->next->data);
				currentNode = currentNode->next;
				rhsCurrentNode = rhsCurrentNode->next;
				tail = currentNode;
				numberOfItems++;
			}
		}
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

	void addToFront(T data)
	{
		Node<T> *newNode = new Node<T>(data, head);
		if (head == nullptr)
		{
			tail = newNode;
		}
		head = newNode;
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