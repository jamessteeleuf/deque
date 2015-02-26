#ifndef TDEQUE_H_INCLUDED
#define TDEQUE_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdexcept>
#include <sstream>

template<class T> class Deque{
private:
	T* inner_array; // Where out data is stored
	int inner_size;
	int cap;
	int front;
	int back;
	std::ostringstream output;
	
	bool full(){
		return this->size() == this->cap; // Our array is full when its size is equal to its capacity
	}
	
	bool too_big(){
		return !this->empty() && this->size() == this->cap/4; // Our inner array is too big if it's less than a quarter full
	}

	void grow(){
		this->resize(this->cap * 2);
	}
	
	void shrink(){
		this->resize(this->cap / 2);
	}
	
	void resize(int){
		// We need to temporarily store our inner array, which we'll do in copied_array
		T* copied_array 	=	new T[cap];

		int current			=	this->front;

		// Just copy it over
		for(int i = 0; i < this->inner_size; i++){
			copied_array[i] 	=	this->inner_array[current];
			current 			=	(current + 1) % this->cap;
		}

		this->cap 	=	cap;

		delete[] this->inner_array; // NO MEMORY LEAKS
		this->inner_array 	=	copied_array; // And swap em
		this->front 		=	0; // Reset our indices
		this->back 			=	this->inner_size - 1;
	}

public:
	Deque(){
		this->cap			=	8;
		this->inner_size 	=	0;
		this->inner_array 	=	new T[this->cap];
		this->front 		=	0;
		this->back			=	this->cap - 1;
	}
	
	~Deque(){
		delete[] this->inner_array; // No memory leaks allowed
	}
	
	void push_front(T const item){
		// Grow our inner array if it's too small
		if(this->full()){
			this->grow();
		}

		// Wrap our index around if necessary
		if(this->front == 0){
			this->front 	=	this->cap - 1;
		}else{
			this->front--;
		}

		// There's a chance that we run out of memory, so we need to account for that
		try{
			this->inner_array[this->front] 	=	item;
		}catch(std::bad_alloc){
			throw std::runtime_error("Out of memory, cannot add item to queue.");
		}
		this->inner_size++;
	}

	void push_back(T const item){
		// Grow our inner array if it's too small
		if(this->full()){
			this->grow();
		}

		// Wrap our index around if necessary
		this->back 	=	(this->back + 1) % this->cap;
		
		// There's a chance that we run out of memory, so we need to account for that
		try{
			this->inner_array[this->back] 	=	item;
		}catch(std::bad_alloc){
			throw std::runtime_error("Out of memory, cannot add item to queue.");
		}
		
		this->inner_size++;
	}
	
	T pop_front(){
		// You can't pop an empty queue
		if(this->empty()){
			throw std::runtime_error("Queue is empty. Cannot remove item.");
		}

		// We return the frontmost element, so we need to save it before we pop it
		T result	=	this->inner_array[this->front];
		
		// Wrap the index around if we reach the end
		this->front	=	(this->front + 1) % this->cap;
		
		this->inner_size--;

		// Shrink the queue if it's too big to conserve memory
		if(this->too_big()){
			this->shrink();
		}

		return result;
	}
	
	T pop_back(){
		// You can't pop an empty queue
		if(this->empty()){
			throw std::runtime_error("Queue is empty. Cannot remove item.");
		}

		// We return the backmost element, so we need to save it before we pop it
		T result 	=	this->inner_array[this->back];

		// Wrap the index around if we reach the end
		if(this->back == 0){
			this->back 	=	this->cap - 1;
		}else{
			this->back--;
		}

		this->inner_size--;

		// Shrink the queue if it's too big to conserve memory
		if(this->too_big()){
			this->shrink();
		}

		return result;
	}
	
	int size(){
		return this->inner_size;
	}
	
	bool empty(){
		return this->size() == 0;
	}
	
	int capacity(){
		return this->cap;
	}
	
	std::string toStr(){
		output.str(""); // clear this bad boy
		
		// Stream all elements in the inner array
		for(int i = 0; i < this->capacity(); i++){
			output << this->inner_array[i] << std::endl;
		}
		
		return output.str();
	}
};

#endif
