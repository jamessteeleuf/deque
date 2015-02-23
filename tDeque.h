#ifndef TDEQUE_H_INCLUDED
#define TDEQUE_H_INCLUDED

template<class T> class Deque{
private:
	T* inner_array;
	int inner_size;
	int cap;
	int front;
	int back;
	bool full();
	bool too_big();
	void grow();
	void shrink();
	void resize(int);

public:
	Deque();
	~Deque();
	void push_front(T const);
	void push_back(T const);
	T pop_front();
	T pop_back();
	int size();
	bool empty();
	std::string toString(); // not implemented
};

#endif