//============================================================================
// Name        : 01_InsertionSort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

template<typename Comparable>
void printArray(vector<Comparable> & a)
{
	int i = 0;
	int length = a.size();

	if (length == 0)
	{
		cout << "[empty]";
	}
	else
	{
		cout << "[ ";
		while (i < length)
		{
			cout << a[i];
			i++;
			if (i < length)
			{
				cout << ", ";
			} // end if
		}
		cout << " ]" << endl;
	}
}

template<typename Comparable>
void myInsertionSort(vector<Comparable> & a)
{
	// p is the pass number
	// switches is a counter for number of switches
	// in a given pass, It is not needed for the sort

	unsigned p, j, switches = 0;
	Comparable tmp;

	for (p = 1; p < a.size(); p++) // Runs (n-1) times
	{
		switches = 0;
		tmp = a[p];
		j = p;
		while (j > 0 && a[j - 1] > tmp) // Max comparisons or switches is p
		{
			a[j] = a[j - 1];
			j--;
			switches++;
		} // end while
		a[j] = tmp;
		// Print array and switches after every pass, It is not needed for the sort
		cout << "Pass = " << p << ", " << "Switches = " << switches << " ";
		printArray(a);
	}
}

template<typename Comparable>
void insertionSort(vector<Comparable> & a)
{
	unsigned p, j;
	for (p = 1; p < a.size(); p++)
	{
		Comparable tmp = a[p];
		for (j = p; j > 0 && tmp < a[j - 1]; j--)
		{
			a[j] = a[j - 1];
		} // end for
		a[j] = tmp;
	}
}

void initializeV1(vector<int> & V1)
{
	V1[0] = 3;
	V1[1] = 1;
	V1[2] = 4;
	V1[3] = 1;
	V1[4] = 5;
	V1[5] = 9;
	V1[6] = 2;
	V1[7] = 6;
	V1[8] = 5;
}

int main()
{
	vector<int> V1(9);
	initializeV1(V1);

	printArray(V1);
	cout << "Insertion is starting" << endl;
	myInsertionSort(V1);
	cout << "Insertion is done" << endl;
	printArray(V1);
}
