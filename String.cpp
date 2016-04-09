#pragma once

#include <iostream>
#include <string>

#include "String.h"

using namespace std;

String::String(const char* d)
{
	for (size_t i = 0; i < strlen(d); ++i)
	{
		strData.pushBack(d[i]);
	}

	strData.pushBack('\0');
}

String::String(const string& st)
{
	for (size_t i = 0; i < st.size(); ++i)
	{
		strData.pushBack(st[i]);
	}

	strData.pushBack('\0');
}

String::String(const String& s)
{
	if (this != &s)
	{
		strData = s.strData;
	}
}

String& String::operator=(char* ch)
{
	while (!strData.isEmpty())
	{
		strData.popFront();
	}

	for (size_t i = 0; i < strlen(ch); ++i)
	{
		strData.pushBack(ch[i]);
	}

	strData.pushBack('\0');

	return *this;
}

String& String::operator=(string& st)
{
	while (!strData.isEmpty())
	{
		strData.popFront();
	}

	for (size_t i = 0; i < st.size(); ++i)
	{
		strData.pushBack(st[i]);
	}

	strData.pushBack('\0');

	return *this;
}

String String::operator+(const String& right)
{
	String buffer = *this;

	buffer.strData.popBack();

	for (size_t i = 0; i < right.strData.getLength(); ++i)
	{
		buffer.strData.pushBack(right.strData.operator[](i));
	}

	return buffer;
}

int String::size() const
{
	return strData.getLength() - 1;
}

void String::erase(int _start, int _num)
{
	if (_start >= 0 && _start <= size())
	{
		if (_num > 0 && _num <= size())
		{
			for (size_t i = 0; i < _num; ++i)
			{
				strData.deleteFromPosition(_start);
			}
		}
	}
}

void String::insert(const string& st, int _pos)
{
	if (_pos == 0)
	{
		*this = String(st) + *this;
	}
	else if (_pos >= size())
	{
		*this = *this + String(st);
	}
	else
	{
		if (_pos > 0 && _pos < size())
		{
			for (size_t i = 0; i < st.size(); ++i)
			{
				strData.insertInPosition(_pos + i, st[i]);
			}
		}
	}
}

int String::findFirst(const string& st) const
{
	int toReturn = -1;

	for (size_t i = 0; i < size(); ++i)
	{
		if (strData[i] == st[0])
		{
			bool subFound = true;

			for (size_t j = 1; j < st.size(); ++j)
			{
				if (i + j > size() - 1 || strData[i + j] != st[j])
				{
					subFound = false;

					break;
				}
			}

			if (subFound)
			{
				toReturn = i;
				break;
			}
		}
	}

	return toReturn;
}

char String::operator[](size_t index) const
{
	if (index >= 0 && index < size())
	{
		return strData.operator[](index);
	}
}

char& String::operator[](size_t index)
{
	if (index >= 0 && index < size())
	{
		return strData.operator[](index);
	}
}

bool String::operator==(const string& s)
{
	string text = "";

	for (size_t i = 0; i < size(); ++i)
	{
		text += strData[i];
	}

	return (text == s);
}

bool String::operator!=(const string& s)
{
	return !(operator==(s));
}

istream& operator>>(istream& in, String& st)
{
	string buf;

	in >> buf;

	st = buf;

	return in;
}

ostream& operator<<(ostream& out, const String& str)
{
	for (size_t i = 0; i < str.size(); ++i)
	{
		out << str.strData[i];
	}
	return out;
}