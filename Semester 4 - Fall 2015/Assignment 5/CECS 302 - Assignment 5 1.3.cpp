#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

int hash(const int & key);
int nextPrime(int);

class HashTable
{
	public:
		explicit HashTable(int size = 101) :
			currentSize(0)
		{
			theLists.resize(7);//Use this to resize the table
			cout << "The Hash Table size is " << theLists.size() << endl;
		}

		bool insert(const int & x)
		{
			list<int> & whichList = theLists[myhash(x)];
			if (find(whichList.begin(), whichList.end(), x) != whichList.end())
			{
				return false;
			} // end if
			whichList.push_back(x);
			if (++currentSize > theLists.size())
			{
				rehash();
			} // end if
			return true;
		}

		void makeEmpty()
		{
			for (unsigned i = 0; i < theLists.size(); i++)
				theLists[i].clear();
		}

		bool contains(const int & x) const
		{
			const list<int> & whichList = theLists[myhash(x)];
			return find(whichList.begin(), whichList.end(), x) != whichList.end();
		}

		bool remove(const int & x)
		{
			list<int> & whichList = theLists[myhash(x)];
			list<int>::iterator itr = find(whichList.begin(), whichList.end(), x);

			if (itr == whichList.end())
				return false;

			whichList.erase(itr);
			--currentSize;
			return true;
		}
		void rehash()
		{
			vector<list<int> > oldLists = theLists;

			// Create new double-sized, empty table
			theLists.resize(nextPrime(2 * theLists.size()));
			for (unsigned j = 0; j < theLists.size(); j++)
				theLists[j].clear();

			// Copy table over
			currentSize = 0;
			for (unsigned i = 0; i < oldLists.size(); i++)
			{
				list<int>::iterator itr = oldLists[i].begin();
				while (itr != oldLists[i].end())
					insert(*itr++);
			}
		}

		void printList()
		{
			for (unsigned i = 0; i < theLists.size(); i++)
			{
				list<int> & whichList = theLists[i];
				if (theLists.size() != 0)
				{
					list<int>::iterator itr = whichList.begin();
					cout << i;
					while (itr != whichList.end())
					{
						cout << ",\t" << *itr << "\t";
						itr++;
					}
					cout << endl;
				}

			} // end for
		}

	private:
		vector<list<int> > theLists; // The array of Lists
		unsigned currentSize;

		int myhash(const int & x) const
		{
			int hashVal = hash(x);

			hashVal %= theLists.size();
			if (hashVal < 0)
				hashVal += theLists.size();

			return hashVal;
		}
};

int main()
{
	HashTable H;

	int itemsCount = 12;
	int myInt[itemsCount];
	myInt[0] = 121;
	myInt[1] = 81;
	myInt[2] = 16;
	myInt[3] = 100;
	myInt[4] = 25;
	myInt[5] = 0;
	myInt[6] = 1;
	myInt[7] = 9;
	myInt[8] = 4;
	myInt[9] = 36;
	myInt[10] = 64;
	myInt[11] = 49;
	

	for (int i = 0; i < itemsCount; ++i)
	{
		H.insert(myInt[i]);
	} // end for

	H.printList();

	cout << "Does H contain 1 " << H.contains(1) << endl;
	cout << "Does H contain 6 " << H.contains(6) << endl;
	cout << "Does H contain 36 " << H.contains(36) << endl;

	return 0;
}

int hash(const int & key)
{
	int hashVal = 0;

	for (unsigned i = 0; i < key; i++)
	{
		hashVal = 37 * hashVal + key;
	} // end for

	return hashVal;
}

/**
 * Internal method to test if a positive number is prime.
 * Not an efficient algorithm.
 */
bool isPrime(int n)
{
	if (n == 2 || n == 3)
		return true;

	if (n == 1 || n % 2 == 0)
		return false;

	for (int i = 3; i * i <= n; i += 2)
		if (n % i == 0)
			return false;

	return true;
}

/**
 * Internal method to return a prime number at least as large as n.
 * Assumes n > 0.
 */
int nextPrime(int n)
{
	if (n % 2 == 0)
		n++;

	for (; !isPrime(n); n += 2)
		;

	return n;
}
