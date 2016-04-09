#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#include "Transformation.h"

using namespace std;

bool test1()
{
		_CrtMemState c1, c2, c3;

		_CrtMemCheckpoint(&c1);

		{
			Transformation test;
		}

		_CrtMemCheckpoint(&c2);

		return !_CrtMemDifference(&c3, &c1, &c2);
}


bool test2()
{
	Transformation t("bacaabaa");

	t.setTransformations(3, { "ab", "ac", "aa", "b", "a", "a" });

	t.transform();

	bool passed = (t.getWord() == "bba" ? true : false);

	return passed;
}


bool test3()
{
	Transformation t("111*11");

	t.setTransformations(8, { "*11", "*1", "1a", "ba", "b1", "a1", "ab", "b",
							  "a*1", "a", "a1b", "ab", "1b", "a", "b", "1"});

	t.transform();

	bool passed = (t.getWord() == "111111" ? true : false);

	return passed;
}



int main()
{
	if (!test1())
	{
		cout << "Test 1 failed" << endl;
	}
	else if (!test2())
	{
		cout << "Test 2 failed" << endl;
	}
	else if (!test3())
	{
		cout << "Test 2 failed" << endl;
	}
	else
	{
		cout << "All tests succeeded" << endl;
	}


	system("pause");
	return 0;
}