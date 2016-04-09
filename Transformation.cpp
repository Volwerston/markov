#pragma once

#include <iostream>

#include "Transformation.h"

Transformation::Transformation(string _d)
	: data(_d),
	numOfOperations(0)
{
}

String Transformation::getWord() const
{
	return data;
}

void Transformation::setWord(const string& st)
{
	data = st;
}

int Transformation::getNumOfOperations()
{
	return numOfOperations;
}

void Transformation::setTransformations(int _num, initializer_list<string> st)
{
	numOfOperations = _num;

	left.insert(left.begin(), st.begin(), st.begin() + _num);
	right.insert(right.begin(), st.begin() + _num, st.end());

	for (size_t i = 0; i < numOfOperations; ++i)
	{
		if (right[i] == ".")
		{
			right[i] = "";
		}
	}
}

void Transformation::transform()
{
	if (left.empty() || right.empty())
	{

		cout << "Input the number of transformations: ";

		cin >> numOfOperations;

		if (numOfOperations < 0)
		{
			transform();
		}
		else
		{

			string l, r;

			for (size_t i = 0; i < numOfOperations; ++i)
			{
				cin >> l >> r;

				left.push_back(l);
				right.push_back(r);

				if (right[i] == ".")
				{
					right[i] = "";
				}
			}
		}
	}

	bool finish = false;

	while (!finish)
	{
		bool operationDone = false;

		for (size_t i = 0; i < numOfOperations; ++i)
		{
			int pos = data.findFirst(left[i]);

			if (pos != -1)
			{
				data.erase(pos, left[i].size());
				data.insert(right[i], pos);
				operationDone = true;
				break;
			}
		}

		if (!operationDone)
		{
			finish = true;
		}
	}
}