#pragma once
#include <iostream>
using namespace std;

template<class L>
class Stack
{
	struct Node
	{
		L value;
		Node* next;
	};
	Node* head;
public:

	Stack()
	{
		head = nullptr;
	}

	void Push(L value)
	{
		Node* newElement = new Node;
		newElement->value = value;
		newElement->next = nullptr;

		if (head == nullptr)
		{
			head = newElement;
		}
		else
		{
			Node* current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}

			current->next = newElement;
		}
	}


	void Pop()
	{
		if (head == nullptr) return;

		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			Node* current = head;

			while (current->next->next != nullptr)
			{
				current = current->next;
			}
			delete current->next;
			current->next = nullptr;
		}
	}


	L Peek()
	{
		Node* current = head;
		while (current != nullptr)
		{
			if (current->next == nullptr)
			{
				return current->value;
			}
			current = current->next;
		}
	}

	void ShowInfo()const
	{
		Node* current = head;
		while (current != nullptr)
		{
			cout << current->value << ", ";
			current = current->next;
		}
		cout << endl;
	}

	bool isEmpty()const
	{
		return head == nullptr;
	}

	void Delete()
	{
		if (head == nullptr) return;

		Node* temp = head->next;
		delete head;

		if (temp == nullptr)
			head = nullptr;
		else
			head = temp;
	}

	~Stack()
	{
		while (!isEmpty())
		{
			Delete();
		}
	}

};
