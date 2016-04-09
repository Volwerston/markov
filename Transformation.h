#pragma once

#include <string>
#include <vector>

#include "String.h"

using namespace std;

class Transformation
{
	String data;
	int numOfOperations;
	vector<string> left;
	vector<string> right;

public:
	Transformation(string = "");

	String getWord() const;

	void setWord(const string&);

	int getNumOfOperations();

	void setTransformations(int, initializer_list<string>);

	void transform();
};