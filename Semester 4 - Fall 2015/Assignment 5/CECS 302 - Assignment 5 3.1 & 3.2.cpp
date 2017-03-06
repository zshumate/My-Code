#include <iostream>
#include <vector>
using namespace std;

class UnderflowException
{
};

template<typename Comparable>
class BinaryHeap
{
	public:
		explicit BinaryHeap(int capacity = 100) :
			array(capacity + 1), currentSize(0)
		{
		}

		explicit BinaryHeap(const vector<Comparable> & items) :
			array(items.size() + 10), currentSize(items.size())
		{
			for (int i = 0; i < items.size(); i++)
				array[i + 1] = items[i];
			buildHeap();
		}

		bool isEmpty() const
		{
			return currentSize == 0;
		}

		/**
		 * Find the smallest item in the priority queue.
		 * Return the smallest item, or throw Underflow if empty.
		 */
		const Comparable & findMin() const
		{
			if (isEmpty())
				throw UnderflowException();
			return array[1];
		}
		/**
		 * Insert item x, allowing duplicates.
		 */
		void insert(const Comparable & x)
		{
			if (currentSize == array.size() - 1)
				array.resize(array.size() * 2);

			// Percolate up
			int hole = ++currentSize;
			for (; hole > 1 && x < array[hole / 2]; hole /= 2)
				array[hole] = array[hole / 2];
			array[hole] = x;
		}

		/**
		 * Remove the minimum item.
		 * Throws UnderflowException if empty.
		 */
		void deleteMin()
		{
			if (isEmpty())
				throw UnderflowException();

			array[1] = array[currentSize--];
			percolateDown(1);
		}

		/**
		 * Remove the minimum item and place it in minItem.
		 * Throws Underflow if empty.
		 */
		void deleteMin(Comparable & minItem)
		{
			if (isEmpty())
				throw UnderflowException();

			minItem = array[1];
			array[1] = array[currentSize--];
			percolateDown(1);
		}
		
		void findK(int k){
			for(int i=0; i<k; i++){
				deleteMin();
				if(i+1==k){
					cout << array[1] << endl;
				}
			}
		}

		void makeEmpty()
		{
			currentSize = 0;
		}

		void printHeap()
		{
			cout << "Start of heap" << endl;
			for (unsigned i = 0; i <= currentSize; i++)
				cout << array[i] << endl;
			cout << "End of heap" << endl;
		}

	private:
		vector<Comparable> array; // The heap array
		unsigned currentSize; // Number of elements in heap


		/**
		 * Establish heap order property from an arbitrary
		 * arrangement of items. Runs in linear time.
		 */
		void buildHeap()
		{
			for (int i = currentSize / 2; i > 0; i--)
				percolateDown(i);
		}

		/**
		 * Internal method to percolate down in the heap.
		 * hole is the index at which the percolate begins.
		 */
		void percolateDown(unsigned hole)
		{
			unsigned child;
			Comparable tmp = array[hole];

			for (; hole * 2 <= currentSize; hole = child)
			{
				child = hole * 2;
				if (child != currentSize && array[child + 1] < array[child])
					child++;
				if (array[child] < tmp)
					array[hole] = array[child];
				else
					break;
			}
			array[hole] = tmp;
		}
};

int main()
{
	int k;
	
	BinaryHeap<int> h(12);

	h.insert(121);
	h.insert(81);
	h.insert(16);
	h.insert(100);
	h.insert(25);
	h.insert(0);
	h.insert(1);
	h.insert(9);
	h.insert(4);
	h.insert(36);
	h.insert(64);
	h.insert(49);
	
	cout << "For finding the kth smallest number, what is k: " << endl;
	cin >> k;

	h.findK(k);
	return 0;
}
