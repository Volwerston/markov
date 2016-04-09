#pragma once

using namespace std;

struct Elem
{

	Elem* next;
	Elem* prev;
	char data;

	Elem(char = ' '); 

	char getData() const;
};


class LinkedList
{
	Elem* first;
	Elem* last;

	int numOfElmnts;
public:

	LinkedList();

	bool isEmpty() const;
	
	LinkedList& operator=(const LinkedList&);

	int getLength() const;

	void insertInPosition(int, char);
	void deleteFromPosition(int);

	void pushFront(char);
	void pushBack(char);

	char popFront();
	char popBack();

	char operator[](size_t index) const;
	char & operator[](size_t index);

	bool operator==(const LinkedList&) const;

	bool operator!=(const LinkedList&) const;

	friend istream& operator>>(istream&, LinkedList&);
	friend ostream& operator<<(ostream&, const LinkedList&);

	~LinkedList();
};