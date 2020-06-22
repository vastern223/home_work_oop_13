#pragma once
#include<iostream>
using namespace std;

template<class T>
class List
{
private:
	struct Node
	{
		T value;
		Node* next;
	};

	Node* head;
public:

	List() : head(nullptr) { }

	void AddToHead(T value)
	{
		Node* newEleme = new Node;
		newEleme->value = value;
		newEleme->next = head;
		head = newEleme;
	}

	List(const List& other)
	{
		Node* current = other.head;
		while (current != nullptr)
		{
			AddToTail(current->value);
			current = current->next;
		}
	}

	List& operator=(const List& other)
	{
		if (this == &other)
		{
			return *this;
		}

		if (this != nullptr)
		{
			while (IsEmptup())
			{
				DeleteHead();
			}
		}

		Node* current = other.head;
		while (current != nullptr)
		{
			AddToTail(current->value);
			current = current->next;
		}
		return *this;
	}

	void operator++()
	{
		AddToTail(0);
	}

	void List_search(int num)
	{
		if (num > 0 && num <= Number_of_elements())
		{
			Node* current = head;
			int counter = 0;
			while (counter != num - 1)
			{
				current = current->next;
				counter++;
			}

			cout << current->value;
		}
	}

	int Number_of_elements()
	{
		Node* current = head;
		int count = 0;
		while (current != nullptr)
		{
			current = current->next;
			count++;
		}
		return count;
	}

	void Add_element(T value, int position)
	{
		int count = 0;
		Node* newEleme = new Node;
		newEleme->value = value;
		newEleme->next = nullptr;
		if (head == nullptr)
		{
			head = newEleme;
		}
		else
		{
			Node* current = new Node;
			while (count != position + 1)
			{
				newEleme = current->next;
				current->next = current;
				current = current->next;
				count++;
			}

			current->next = newEleme;

		}
	}

	void AddToTail(T value)
	{
		Node* newEleme = new Node;
		newEleme->value = value;
		newEleme->next = nullptr;
		if (head == nullptr)
		{
			head = newEleme;
		}
		else
		{
			Node* current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			current->next = newEleme;
		}
	}
	void Print() const
	{
		Node* current = head;
		while (current != nullptr)
		{
			cout << current->value << " : ";
			current = current->next;
		}
	}
	void DeleteHead()
	{
		if (head == nullptr)return;

		Node* temp = head->next;
		delete head;
		if (temp == nullptr)
			head = nullptr;
		else
			head = temp;
	}

	void DeleteTail()
	{
		if (head == nullptr)return;

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

	void AddByIndex(int index, T value)
	{
		if (index > ShowSizeOfList() || index < 0)
		{
			cout << "error" << endl;
			return;
		}
		else
		{
			if (index == ShowSizeOfList())
			{
				AddToTail(value);
				return;
			}
			int count = 0;

			Node* newElement = new Node;
			newElement->value = value;

			Node* current = head;
			while (current != nullptr)
			{
				if (count + 1 == index)
				{
					newElement->next = current->next;
					current->next = newElement;
				}
				++count;
				current = current->next;
			}
		}
	}

	void DeleteByIndex(int index)
	{

		if (index > (ShowSizeOfList() - 1) || index < 0)
		{
			cout << "error" << endl;
			return;
		}
		else
		{
			if (head == nullptr) return;

			if (head->next == nullptr)
			{
				delete head;
				head = nullptr;
			}
			else
			{
				int count = 0;
				Node* current = head;
				Node* temp = new Node;
				while (current != nullptr)
				{
					if (count + 1 == index)
					{
						temp = current->next;
						current->next = current->next->next;
						delete temp;
					}
					++count;
					current = current->next;
				}
			}
		}
	}

	int ShowSizeOfList()
	{
		int count = 0;
		Node* current = head;
		while (current != nullptr)
		{
			++count;
			current = current->next;
		}
		return count;
	}

	bool IsEmptup()const
	{
		return head == nullptr;
	}

	~List()
	{
		while (IsEmptup())
		{
			DeleteHead();
		}
	}


};
