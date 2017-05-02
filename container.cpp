#include "container.h"
#include <stddef.h>
#include <iostream>

template<class type>
Container<type>::Container(){
	first = last = NULL;
	count = 0;
}
template<class type>
Container<type>::Container(const type &new_element){
	Cell<type> *newCell = new Cell<type>(new_element);
	first = last = newCell;
	count = 1;
}
template<class type>
Container<type>::~Container(){
	count = 0;
	Cell<type> *temp;
	while(first != NULL){
		temp = first;
		first = first->getNext();
		delete temp;
	}
	first = last = NULL;
}
template<class type>
void Container<type>::Enqueue(const type &new_element){
	count++;
	Cell<type> *newCell = new Cell<type>(new_element);
	if(first != NULL){
		newCell->setPrev(last);
		last->setNext(newCell);
		last = newCell;
	}else{
		first = last = newCell;
	}
}
template<class type>
type Container<type>::Dequeue(){
	count--;
	if(first != NULL){
		Cell<type> *second = first->getNext();
		Cell<type> *firstCell = first;
		type content = first->getContent();
	
		second->setPrev(NULL);
		first = second;
	
		delete firstCell;
		return content;	
	}else{
		return 0;
	}
}

template<class type>
void Container<type>::Push(const type &new_element){
	count++;
	Cell<type> *newCell = new Cell<type>(new_element);
	
	if(first != NULL){
		newCell->setNext(first);
		first->setPrev(newCell);
		first = newCell;
	}else{
		first = last = newCell;
	}	
}
template<class type>
type Container<type>::Pop(){
	Dequeue();
}
template<class type>
void Container<type>::Clear(){
	count = 0;
	std::cout << " clearing";
	 Cell<type> *temp;
	 while(first != NULL){
	 	temp = first;
	 	first = first->getNext();
	 	delete temp;
	 }
	 first = last = NULL;
}
template<class type>
int Container<type>::Size()const{ return count; }

template<class type>
bool Container<type>::IsEmpty()const{
	if(first == NULL) return true;
	else return false;
}

template <class type>
void Container<type>::Print(){
	if(first == NULL){
		std::cout<< "Empty list";
		return;
	}
	Cell<type> *temp = first;
	while(temp != NULL){
		std::cout << temp->getContent() << " ";
		temp = temp->getNext();
	}
}
template <class type>
bool Container<type>::operator==(const Container &a){
	Cell<type> *b = a.first;
	
	while(first != NULL && a.first != NULL){
		if(first->getContent() == b->getContent()){
			first = first->getNext();
			b = b->getNext();
		}else{
			return false;
		}
	}
	return true;
}

template<class type>
type &Container<type>::operator[](const int n){
	Cell<type> *temp = first;
	for(int i = 0; i < n; i++){
		temp = temp->getNext();
	}
	return temp->getContent();
}















