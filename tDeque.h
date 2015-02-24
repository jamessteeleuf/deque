#ifndef TDEQUE_H_INCLUDED
#define TDEQUE_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdexcept>
#include <sstream>

template<class T> class Deque{
private:
	T* inner_array;
	int inner_size;
	int cap;
	int front;
	int back;
	std::ostringstream output;
	
	bool full(){
		return this->size() == this->cap;
	}
	
	bool too_big(){
		return !this->empty() && this->size() == this->cap/4;
	}

	void grow(){
		this->resize(this->cap * 2);
	}
	
	void shrink(){
		this->resize(this->cap / 2);
	}
	
	void resize(int){
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
		if(this->full()){
			this->grow();
		}

		if(this->front == 0){
			this->front 	=	this->cap - 1;
		}else{
			this->front--;
		}

		try{
			this->inner_array[this->front] 	=	item;
		}catch(std::bad_alloc){
			throw std::runtime_error("Out of memory, cannot add item to queue.");
		}
		this->inner_size++;
	}

	void push_back(T const item){
		if(this->full()){
			this->grow();
		}

		this->back 	=	(this->back + 1) % this->cap;
		
		try{
			this->inner_array[this->back] 	=	item;
		}catch(std::bad_alloc){
			throw std::runtime_error("Out of memory, cannot add item to queue.");
		}
		
		this->inner_size++;
	}
	
	T pop_front(){
		if(this->empty()){
			throw std::runtime_error("Queue is empty. Cannot remove item.");
		}

		T result	=	this->inner_array[this->front];
		this->front	=	(this->front + 1) % this->cap;
		this->inner_size--;

		if(this->too_big()){
			this->shrink();
		}

		return result;
	}
	
	T pop_back(){
		if(this->empty()){
			throw std::runtime_error("Queue is empty. Cannot remove item. hi");
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
		
		output << "outputting..." << std::endl;
		for(int i = 0; i < this->capacity(); i++){
			output << this->inner_array[i] << std::endl;
		}
		
		return output.str();
	}
};

#endif
