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

/**
 * Shellsort, using Shell's (poor) increments.
 */
template<typename Comparable>
void shellSort(vector<Comparable> & a)
{

	for (int gap = a.size() / 2; gap > 0; gap /= 2)
	{
		// The following loop starts at gap and increment forward
		// Until we reach the end
		for (unsigned i = gap; i < a.size(); i++)
		{
			Comparable tmp = a[i];
			unsigned switches = 0;
			int j = i;

			// The loop below is a clever way of starting at a[gap] and comparing it with
			// it's predecessors that are gap apart and doing insert sort when needed

			for (; j >= gap && tmp < a[j - gap]; j -= gap)
			{
				a[j] = a[j - gap];
				switches++;
			}
			a[j] = tmp;
			cout << "Gap = " << gap << ", " << "Switches = " << switches << " ";
			printArray(a);
		}
	}
}

void initializeV1(vector<int> & V1)
{
	V1[0] = 34;
	V1[1] = 8;
	V1[2] = 64;
	V1[3] = 51;
	V1[4] = 32;
	V1[5] = 21;
}

void initializeV2(vector<int> & V2)
{
	V2[0] = 9;
	V2[1] = 8;
	V2[2] = 7;
	V2[3] = 6;
	V2[4] = 5;
	V2[5] = 4;
	V2[6] = 3;
	V2[7] = 2;
	V2[8] = 1;
}

int main()
{
	vector<int> V2(9);

	initializeV2(V2);

	printArray(V2);
	cout << "Shell is starting" << endl;
	shellSort(V2);
	cout << "Shell is done" << endl;
	printArray(V2);

	return 0;
}
