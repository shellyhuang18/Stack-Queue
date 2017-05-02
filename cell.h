#include <stddef.h>
#ifndef CELL_H
#define CELL_H

template<class type>
class Cell{
	private: 
		Cell<type> *next;
		Cell<type> *prev;
		type content;
	public:		
		Cell(){ content = prev = next = NULL; }
		Cell(const type &elem){
			content = elem;
			next = prev = NULL;
		}	
		void setNext(Cell<type> *ptr){ next = ptr; }
		void setPrev(Cell<type> *ptr){ prev = ptr; }
		void setContent(const type elem){ content = elem; }
		Cell<type>* getNext() const{ return next; }
		Cell<type>* getPrev() const { return prev; }
		type &getContent() { return content; }
};
#endif

