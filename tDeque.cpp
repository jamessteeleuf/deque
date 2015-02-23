#include "tDeque.h"
#include <stdio.h>

using namespace std;

Deque::Deque(){
	this->cap			=	8;
	this->inner_size 	=	0;
	this->inner_array 	=	new T[this->cap];
	this->front 		=	0;
	this->back			=	this->cap - 1;
}

Deque::~Deque(){
	delete[] this->inner_array; // No memory leaks allowed
}

int Deque::size(){
	return this->inner_size;
}

bool Deque::empty(){
	return this->size == 0;
}

bool Deque::full(){
	return this->size() == this->cap;
}

bool Deque::too_big(){
	return !this->empty() && this->size() == this->cap/4;
}

void Deque::push_front(const T item){
	if(this->full()){
		this->grow();
	}

	if(this->front == 0){
		this->front 	=	this->cap - 1;
	}else{
		this->front--;
	}

	this->inner_array[this->front] 	=	item;
	this->inner_size++;
}

void Deque::push_back(const T item){
	if(this->full()){
		this->grow();
	}

	this->back 						=	(this->back + 1) % this->cap;
	this->inner_array[this->back] 	=	item;
	this->inner_size++;
}

T Deque::pop_front(){
	if(this->empty()){
		throw "Queue is empty. Cannot remove item.";
	}

	T result	=	this->inner_array[this->front];
	this->front	=	(this->front + 1) % this->cap;
	this->inner_size--;

	if(this->too_big()){
		this->shrink();
	}

	return result;
}

T Deque::pop_back(){
	if(this->empty()){
		throw "Queue is empty. Cannot remove item.";
	}

	T result 	=	this->inner_array[this->back];

	if(this->back == 0){
		this->back 	=	this->cap - 1;
	}else{
		this->back--;
	}

	this->inner_size--;

	if(this->too_big()){
		this->shrink();
	}

	return result;
}

void Deque::resize(int cap){
	T* copied_array 	=	new T[cap];

	int current			=	this->front;

	for(int i = 0; i < this->inner_size; i++){
		copied_array[i] 	=	this->inner_array[current];
		current 			=	(current + 1) % this->cap;
	}

	this->cap 	=	cap;

	delete[] this->inner_array;
	this->inner_array 	=	copied_array;
	this->front 		=	0;
	this->back 			=	this->inner_size - 1;
}

void Deque::grow(){
	this->resize(this->cap * 2);
}

void Deque::shrink(){
	this->resize(this->cap / 2);
}

int Deque::capacity(){
	return this->cap;
}