// Cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <regex>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using  namespace std;

class MyClass
{
public:
	MyClass(int value = INT_MIN, int bigger = INT_MIN)
	{
		this->bigger = bigger;
		this->value = value;
	}
	int value;
	int bigger;
};

int getPost(vector<MyClass> list2, int value)
{
	for (int i = 0; i < list2.size(); i++)
	{
		if (list2[i].value == value)
		{
			return i;
		}
	}
	return -1;
}

int getBigger(vector<MyClass> list2, int pos)
{
	int value = list2[pos].value;
	for (int i =  pos + 1; i < list2.size() - 1; i++)
	{
		if (list2[i].value > value)
		{
			return list2[i].value;
		}
	}
	return -1;
}




int main() {
	int n1;
	cin >> n1;
	vector<int> list1(n1);
	
	for (int i = 0; i < n1; i++)
	{
		cin >> list1[i];
	}
	int n2;
	cin >> n2;
	vector<MyClass> list2(n2);
	for (int i = 0; i < n2; i++)
	{
		cin >> list2[i].value;
	}

	for (int i = 0; i < n2; i++)
	{
		list2[i].bigger = getBigger(list2, i);
	}

	for (int i = 0; i < n1; i++)
	{
		int posInList2 = getPost(list2, list1[i]);
		cout << list2[posInList2].bigger << " ";
	}

	return 0;
}
