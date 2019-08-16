#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;

	Node()
	{
		next = nullptr;
	}

	Node(int data, Node* next = nullptr)
	{
		this->data = data;
		this->next = next;
	}
};

void insertSorted(Node* head, int value)
{
	Node* currentNode = head;
	while (currentNode->next != nullptr)
	{
		if (value < currentNode->next->data)
		{
			currentNode->next = new Node(value, currentNode->next);
			return;
		}
		currentNode = currentNode->next;
	}

	currentNode->next = new Node(value);
}

int main()
{
	Node* ten = new Node(10);
	Node* five = new Node(5, ten);
	Node* head = new Node(0, five);


	insertSorted(head, 6);
	insertSorted(head, 2);
	insertSorted(head, 12);



	Node* currentNode = head;

	while (currentNode != nullptr)
	{
		cout << currentNode->data << endl;
		currentNode = currentNode->next;
	}

	

	system("pause");
	return 0;
}
