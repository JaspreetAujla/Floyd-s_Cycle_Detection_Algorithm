#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node* next;

	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};


Node* head = NULL;
class Linked 
{
public:
	void insert(int value)
	{
		Node* newNode = new Node(value);
		if (head == NULL)
			head = newNode;
		else
        {
			newNode->next = head;
			head = newNode;
		}
	}

	bool detectLoop()
	{
		Node *slowPointer = head,
			*fastPointer = head;

		while (slowPointer != NULL
			&& fastPointer != NULL
			&& fastPointer->next != NULL)
        {
			slowPointer = slowPointer->next;
			fastPointer = fastPointer->next->next;
			if (slowPointer == fastPointer)
				return 1;
		}

		return 0;
	}
};

int main()
{
	Linked l1;
	l1.insert(15);
	l1.insert(20);
	l1.insert(17);
	l1.insert(11);
	l1.insert(22);


	Node* temp = head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = head;

	if (l1.detectLoop())
		cout << "Cycle exists in the Linked List" << endl;
	else
		cout << "Cycle does not exists in the Linked List" << endl;

	return 0;
}
