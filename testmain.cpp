#include "tDeque.h"
#include <vector>
#include <iostream>
#include <stdio.h>

int main(int argc, char **argv){
	/*
	 * Test:
	 * 		An element should be pushed to the front of the queue.
	 */
	try{
		Deque<int> *DQ 	=	new Deque<int>();

		DQ->push_front(4);

		if(DQ->pop_front() != 4){
			throw "It does not push elements to the front of the queue."
		}else{
			throw "It pushes elements to the front of the queue."
		}

		delete[] DQ;
	}catch(const char* s){
		feedback.push_back(s);
	}

	/*
	 * Test:
	 * 		An element should be pushed to the back of the queue.
	 */
	try{
		Deque<int> *DQ 	=	new Deque<int>();

		DQ->push_back(4);

		if(DQ->pop_back() != 4){
			throw "It does not push elements to the back of the queue."
		}else{
			throw "It pushes elements to the back of the queue."
		}

		delete[] DQ;
	}catch(const char* s){
		feedback.push_back(s);
	}

	/*
	 * Test:
	 * 		The queue should default to a capacity of 8.
	 */
	try{
		Deque<int> *DQ 	=	new Deque<int>();

		if(DQ->capacity() != 8){
			throw "The queue does not default to a capacity of 8";
		}else{
			throw "The queue defaults to a capacity of 8.";
		}

		delete[] DQ;
	}catch(const char* s){
		feedback.push_back(s);
	}

	/*
	 * Test:
	 * 		The queue should double in size when filled.
	 */
	try{
		Deque<int> *DQ 	=	new Deque<int>();
		int capacity, fill_size, new_capacity;

		capacity 	=	DQ->capacity();

		// Fill the queue and check the size
		for(int i = 0; i < capacity; i++){
			DQ->push_front(i);
		}

		fill_size 	=	DQ->size();

		if(fill_size != capacity && DQ->capacity() != capacity){
			throw "The queue is not filled.";
		}

		// Overflow it
		DQ->push_front(9);

		if(DQ->capacity() != capacity){
			throw "The queue does not double in size when filled".
		}else{
			throw "The queue doubles in size when filled."
		}

		delete[] DQ;
	}catch(const char* s){
		feedback.push_back(s);
	}

	/*
	 * Test:
	 * 		The queue should not try to remove an item from an empty queue
	 */
	try{
		Deque<int> *DQ 	=	new Deque<int>();

		try{
			int result 		=	DQ->pop_back();
			throw "The queue tries to remove an item from an empty queue.";
		}catch(runtime_error e){
			throw "The queue does not try to remove an item from an empty queue.";
		}

		delete[] DQ;
	}catch(const char* s){
		feedback.push_back(s);
	}

	/*
	 * Test:
	 * 		The queue should shrink when it is less than a quarter full
	 */
	try{
		Deque<int> *DQ 	=	new Deque<int>();
		int capacity;

		capacity 	=	DQ->capacity();

		// Overflow the queue (notice the <= operator)
		for(int i = 0; i <= capacity; i++){
			DQ->push_front(i);
		}

		while(DQ->size() >= DQ->capacity()/4){
			DQ->pop_front();
		}

		capacity 	=	DQ->capacity();
		DQ->pop_front();

		if(capacity != DQ->capacity()){
			throw "The queue shrinks when it is less than a quarter full.";
		}else{
			throw "The queue does shrink when it is less than a quarter full.";
		}

		delete[] DQ;
	}catch(const char* s){
		feedback.push_back(s);
	}

	for(std::vector<string>::const_iterator i = feedback.begin(); i != feedback.end(); ++i){
		std::cout << *i << '\n';
	}

	return 0;
}