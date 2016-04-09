#pragma once

#include <iostream>

#include "TwoLinkedList.h"

using namespace std;


Elem::Elem(char _dat)
	: data(_dat),
	next(nullptr),
	prev(nullptr)
{
}

char Elem::getData() const
{
	return data;
}

LinkedList::LinkedList()
	: first(nullptr),
	last(nullptr),
	numOfElmnts(0)
{
}

bool LinkedList::isEmpty() const
{
	return first == nullptr;
}

LinkedList& LinkedList::operator=(const LinkedList& list)
{
	if (this != &list)
	{
		while (!isEmpty())
		{
			popBack();
		}

		for (size_t i = 0; i < list.numOfElmnts; ++i)
		{
			pushBack(list.operator[](i));
		}

		numOfElmnts = list.numOfElmnts;
	}

	return *this;
}

int LinkedList::getLength() const
{
	return numOfElmnts;
}

void LinkedList::insertInPosition(int pos, char data)
{
	if (pos >= numOfElmnts)
	{
		pushBack(data);
	}
	else if (pos == 0)
	{
		pushFront(data);
	}
	else
	{
		++numOfElmnts;
		int counter = 1;
		Elem* current = first->next;

		while (counter < pos)
		{
			current = current->next;
			++counter;
		}

		Elem* toAdd = new Elem(data);

		current->prev->next = toAdd;
		toAdd->prev = current->prev;
		toAdd->next = current;
		current->prev = toAdd;
	}
}

void LinkedList::pushBack(char data)
{
	++numOfElmnts;

	Elem* toAdd = new Elem(data);

	if (isEmpty())
	{
		first = last = toAdd;
	}
	else
	{
		Elem* buf = last;
		last->next = toAdd;
		last = toAdd;
		last->prev = buf;
	}
}

char LinkedList::popBack()
{
	char toReturn = ' ';

	if (isEmpty())
	{
		cout << "The list is empty" << endl;
	}
	else
	{
		--numOfElmnts;

		if (first == last)
		{
			toReturn = first->data;
			delete first;
			first = last = nullptr;
		}
		else
		{
			Elem* buffer = last;
			toReturn = buffer->data;

			last = last->prev;
			last->next = nullptr;

			delete buffer;
		}
	}

	return toReturn;
}

char LinkedList::operator[](size_t index) const
{
	if (index < 0 || index >= numOfElmnts)
	{
		cout << "Attempt to access a non-existing element";
		system("pause");
		exit(1);
	}
	else
	{
		int counter = 0;
		Elem* needed = first;

		while (counter < index)
		{
			needed = needed->next;
			++counter;
		}

		return needed->data;
	}
}

void LinkedList::pushFront(char data)
{
	++numOfElmnts;

	Elem* toAdd = new Elem(data);

	if (isEmpty())
	{
		first = last = toAdd;
	}
	else
	{
		Elem* buffer = first;
		first->prev = toAdd;
		first = toAdd;
		first->next = buffer;
	}
}

char& LinkedList::operator[](size_t index)
{
	if (index < 0 || index >= numOfElmnts)
	{
		cout << "Attempt to access a non-existing element";
		system("pause");
		exit(1);
	}
	else
	{
		int counter = 0;
		Elem* needed = first;

		while (counter < index)
		{
			needed = needed->next;
			++counter;
		}

		return needed->data;
	}
}

char LinkedList::popFront()
{
	char toReturn = ' ';

	if (isEmpty())
	{
		cout << "The list is empty" << endl;
	}
	else
	{
		--numOfElmnts;

		if (first == last)
		{
			toReturn = first->data;
			delete first;
			first = last = nullptr;
		}
		else
		{
			Elem* buffer = first;
			toReturn = buffer->data;
			first = first->next;
			delete buffer;
		}
	}

	return toReturn;
}

bool LinkedList::operator==(const LinkedList& list) const
{
	bool equal = true;

	if (numOfElmnts != list.numOfElmnts)
	{
		equal = false;
	}
	else
	{
		for (size_t i = 0; i < numOfElmnts; ++i)
		{
			if (this->operator[](i) != list.operator[](i))
			{
				equal = false;
				break;
			}
		}
	}

	return equal;
}

bool LinkedList::operator!=(const LinkedList& list) const
{
	return !(*this == list);
}

istream& operator>>(istream& in, LinkedList& list)
{
	char data;
	while (in >> data)
	{
		list.pushBack(data);
	}

	return in;
}

ostream& operator<<(ostream& out, const LinkedList& list)
{
	if (list.isEmpty())
	{
		cout << "The list is empty" << endl;
	}
	else
	{
		Elem* cur = list.first;

		while (cur != nullptr) // take away some functionality later
		{
			if (cur->data == '\0')
			{
				cout << "|";
			}
			else
			{
				cout << cur->data;
			}
			cur = cur->next;
		}

		cout << endl;
	}

	return out;
}

void LinkedList::deleteFromPosition(int pos)
{

	if (isEmpty())
	{
		cout << "The list is empty" << endl;
	}
	else
	{
		if (pos == 0)
		{
			popFront();
		}
		else if (pos >= numOfElmnts - 1)
		{
			popBack();
		}
		else
		{

			Elem* current = first->next;
			int position = 1;

			while (current->next != nullptr)
			{

				if (position == pos)
				{
					--numOfElmnts;
					Elem* buf = current;
					current->prev->next = current->next;
					current->next->prev = current->prev;
					buf->next = nullptr;
					buf->prev = nullptr;
					delete buf;
					break;
				}
				else
				{
					current = current->next;
					++position;
				}

			}

		}
	}
}

LinkedList::~LinkedList()
{
	if (!isEmpty())
	{
		Elem* cur = first;
		Elem* tech;

		while (cur != nullptr)
		{
			tech = cur;
			cur = cur->next;
			delete tech;
		}
	}
}