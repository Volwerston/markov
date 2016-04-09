#pragma once

#include "TwoLinkedList.h"

using namespace std;

/*	FUNCTIONALITY:
	
 V	String a("ABC");
 V	String a = "ABC";
 V	String a = b;
 V	a = b;
 V	a = "ABC";
 V	cout << a;
 V	cin >> a;
 V	c = a + b;
 V	c.erase(0, 2);
	c.append("ABC");
	c.toUpper();
	c.toLower();
 V	c.findFirst("ABC");
 V	c.findFirst(a);
	c.findLast("DEF");
	c.findLast(b);
	c.replaceFirst("ABC", "DEF");
	c.replaceLast("ABC", "DEF");
	c.replaceAll("ABC", "DEF");
V	c.insert(a);
V	c.insert("ABC");
	c == a;
	c == "ABC";
	c != b;
	c != "ABC"

*/

class String
{
	LinkedList strData;

public:
	String(const char* = " ");

	String(const string&);

	String(const String&);

	String& operator=(char*);

	String& operator=(string&);

	String operator+(const String&);

	int size() const;

	void erase(int, int);

	void insert(const string&, int = 0);

	int findFirst(const string&) const;

	char operator[](size_t) const;

	char& operator[](size_t);

	bool operator==(const string&);

	bool operator!=(const string&);
	
	friend istream& operator>>(istream&, String&);

	friend ostream& operator<<(ostream&, const String&);
};