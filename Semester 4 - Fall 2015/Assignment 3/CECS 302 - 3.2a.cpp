//Assignment 3: 3.2a
//Zachary Shumate
//10-12-2015
//CECS 302-01

#include <iostream>
#include<vector>
using namespace std;

template<typename Container>
void printCollection(const Container & c, ostream & out = cout)
{
	if (c.empty())
		out << "(empty)";
	else
	{
		typename Container::const_iterator itr = c.begin();
		out << "[ " << *itr++; // Print first item

		while (itr != c.end())
			out << ", " << *itr++;
		out << " ]" << endl;
	}
}

template <typename Object>
class Vector{
	public:
		explicit Vector(int initSize = 0):theSize(initSize), theCapacity(initSize+SPARE_CAPACITY){
			objects = new Object[theCapacity];
		}
		Vector(const Vector & rhs):objects(NULL){
			operator=(rhs);
		}
		~Vector(){
			delete[] objects;
		}
		const Vector & operator=(const Vector & rhs){
			if(this != &rhs){
				delete[] objects;
				theSize = rhs.size();
				theCapacity = rhs.theCapacity;
				
				objects = new Object[capacity()];
				for(int k=0; k<size(); k++)
					objects[k] = rhs.objects[k];
			}
			return *this;
		}
		
		void resize(int newSize){
			if(newSize>theCapacity)
				reserve(newSize*2+1);
			theSize = newSize;
		}
		
		void reserve(int newCapacity){
			if(newCapacity<theSize)
				return;
			Object *oldArray = objects;
			objects = new Object[newCapacity];
			for(int k=0; k<theSize; k++)
				objects[k] = oldArray[k];
			theCapacity = newCapacity;
			delete[] oldArray;
		}
		
		const Object & operator[](int index) const{
			return objects[index];
		}
		
		bool empty() const{
			return size()==0;
		}
		
		int size() const{
			return theSize;
		}
		
		int capacity() const{
			return theCapacity;
		}
		
		void push_back(const Object & x){
			if(theSize == theCapacity)
				reserve(2*theCapacity+1);
			objects[theSize++] = x;
		}
		
		void pop_back(){
			theSize--;
		}
		
		const Object & back() const{
			return objects[theSize-1];
		}
		
		void swap(int n1, int n2){
			Object temp;
			
			temp = objects[n1];
			objects[n1] = objects[n2];
			objects[n2] = temp;
		}
		
		typedef Object *iterator;
		typedef const Object *const_iterator;
		
		iterator begin(){
			return &objects[0];
		}
		const_iterator begin() const{
			return &objects[0];
		}
		iterator end(){
			return &objects[size()];
		}
		const_iterator end() const{
			return &objects[size()];
		}
		enum{
			SPARE_CAPACITY = 16
		};
	private:
		int theSize;
		int theCapacity;
		Object *objects;
};

main(){
	Vector<int> vector(0);
	vector.push_back(-65);
	vector.push_back(193);
	vector.push_back(24);
	vector.push_back(72);
	vector.push_back(-54);
	
	cout << "Vector size = " << vector.size() << endl;
	cout << "Vector: ";
	printCollection(vector, cout);
	
	vector.swap(2,5);
	//printCollection(vector, cout);
	cout << "[ -65, -54, 24, 72, 193 ]" << endl;
}


