#include "cell.h"
#ifndef CONTAINER_H
#define CONTAINER_H
template<class type>
class Container{
	private:
		Cell<type> *first;
		Cell<type> *last;
		int count;
	public:
		Container();
		Container(const type &new_element);
		~Container();
		void Enqueue(const type &new_element);
		type Dequeue();
		void Push(const type &new_element);
		type Pop();
		void Clear();
		int Size()const;
		bool IsEmpty()const;
		void Print();
		type &operator[](const int n);
		bool operator==(const Container<type> &a);
	
};

#include "container.cpp"
#endif
