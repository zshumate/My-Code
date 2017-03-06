//Assignment 3: 3.6
//Zachary Shumate
//10-12-2015
//CECS 302-01

#include <iostream>
#include <iterator>
#include <ctime>
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

template<typename Object>
class List
{
	private:
		struct Node
		{
				Object data;
				Node *prev;
				Node *next;

				Node(const Object & d = Object(), Node *p = NULL, Node *n = NULL) :
					data(d), prev(p), next(n)
				{
				}
		};

	public:
		class const_iterator
		{
			public:
				const_iterator() : current(NULL)
				{
				}

				const Object & operator*() const
				{
					return retrieve();
				}

				const_iterator & operator++()
				{
					current = current->next;
					return *this;
				}

				const_iterator operator++(int)
				{
					const_iterator old = *this;
					++(*this);
					return old;
				}

				bool operator==(const const_iterator & rhs) const
				{
					return current == rhs.current;
				}
				bool operator!=(const const_iterator & rhs) const
				{
					return !(*this == rhs);
				}

			protected:
				Node *current;

				Object & retrieve() const
				{
					return current->data;
				}

				const_iterator(Node *p) :
					current(p)
				{
				}

				friend class List<Object> ;
		};
		class iterator : public const_iterator
		{
			public:
				iterator()
				{
				}

				Object & operator*()
				{
					return this.retrieve();
				}

				const Object & operator*() const
				{
					return const_iterator::operator*();
				}

				iterator & operator++()
				{
					this.current = this.current->next;
					return *this;
				}

				iterator operator++(int)
				{
					iterator old = *this;
					++(*this);
					return old;
				}

			protected:
				iterator(Node *p) :
					const_iterator(p)
				{
				}

				friend class List<Object> ;
		};

	public:
		List()
		{
			init();
		}

		~List()
		{
			clear();
			delete head;
			delete tail;
		}

		List(const List & rhs)
		{
			init();
			*this = rhs;
		}

		const List & operator=(const List & rhs)
		{
			if (this == &rhs)
				return *this;
			clear();
			for (const_iterator itr = rhs.begin(); itr != rhs.end(); ++itr)
				push_back(*itr);
			return *this;
		}

		iterator begin()
		{
			return iterator(head->next);
		}
		const_iterator begin() const
		{
			return const_iterator(head->next);
		}
		iterator end()
		{
			return iterator(tail);
		}
		const_iterator end() const
		{
			return const_iterator(tail);
		}
		int size() const
		{
			return theSize;
		}
		bool empty() const
		{
			return size() == 0;
		}
		void clear()
		{
			while (!empty())
				pop_front();
		}
		Object & front()
		{
			return *begin();
		}
		const Object & front() const
		{
			return *begin();
		}
		Object & back()
		{
			return *--end();
		}
		const Object & back() const
		{
			return *--end();
		}
		void push_front(const Object & x)
		{
			insert(begin(), x);
		}
		void push_back(const Object & x)
		{
			insert(end(), x);
		}
		void pop_front()
		{
			erase(begin());
		}
		void pop_back()
		{
			erase(--end());
		}
		// Insert x before itr.
		iterator insert(iterator itr, const Object & x)
		{
			Node *p = itr.current;
			theSize++;
			return iterator(p->prev = p->prev->next = new Node(x, p->prev, p));
		}
		// Erase item at itr.
		iterator erase(iterator itr)
		{
			Node *p = itr.current;
			iterator retVal(p->next);
			p->prev->next = p->next;
			p->next->prev = p->prev;
			delete p;
			theSize--;

			return retVal;
		}

		iterator erase(iterator start, iterator end)
		{
			for (iterator itr = start; itr != end;)
				itr = erase(itr);

			return end;
		}
		
		void loop(){
			head->prev = tail;
			tail->next = head;
		}

	private:
		int theSize;
		Node *head;
		Node *tail;
		void init()
		{
			theSize = 0;
			head = new Node;
			tail = new Node;
			head->next = tail;
			tail->prev = head;
		}
};

main(){
	clock_t init, final;
	init = clock();
	
	int n, m;
	List<int> list;
	List<int>::iterator itr = list.begin();
	
	cout << "How many people are playing Hot Potato?" << endl;
	cin >>  n;
	cout << "How many passes until someone is eliminated?" << endl;
	cin >> m;
	
	for(int i=0; i<n; i++){
		list.push_back(i+1);
	}
	list.loop();
	printCollection(list, cout);
	
	while(list.size()>1){
		for(int i=0; i<m; i++)
			itr++;
		list.erase(itr);
		printCollection(list, cout);
	}
	
	final = clock() - init;
	cout << (double) final << endl;
}
