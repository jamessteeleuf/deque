# tDeque.h
#### Written by James Steele

## Table of Contents

1. About
2. Use
3. Testing
4. Methods
5. Specification
6. Limitations

## About

tDeque.h is a generic implementation of double-ended queues in C++.

## Use

To build sDeque and run the packaged main file, run the makefile and the resultant executable.

    $ make & ./tDeque

To begin using sDeque in your own project, simply create an instance of the Deque class.

    Deque<T> *DQ = new Deque<T>();

## Testing

Tests can be accessed by running the following command:

    $ make & ./tests

After initiating the tests, you will be prompted for an operation, represented by a number from 0 to 5.

| opcode | operation  |
|--------|------------|
| 0      | push\_front |
| 1      | push\_back  |
| 2      | pop\_front  |
| 3      | pop\_back   |
| 4      | print      |
| 5      | exit       |

After inputting the operator, you will be asked for an argument if necessary.

After some tests, you may be prompted to confirm that a result is correct. Simply respond `y` if it is or `n` if it is not.

If everything goes correctly, the test suite should print

    It checks if the array is empty.
    It pushes a string to the front of the queue and then returns the same string when popped.
    It pushes a string to the back of the queue and then returns the same string when popped.
    It responds correctly to sample input.
    It checks the size of the deque

## Methods

### class pop_front()

Removes and returns the item at the front of the queue.

### class pop_back()

Removes and returns the item at the back of the queue.

### void push_front(class item)

Adds the item to the front of the queue.

### void push_back(class item)

Adds the item to the back of the queue.

### int size()

Returns the size of the queue.

### bool empty()

Checks if the queue is empty.

### std::string toStr()

Returns the queue in string format, delimited by new lines.

## Specification

### General

* The default capacity should be 8

### push_front/push_back

* An element should be pushed to the front/back of the queue.
* The queue should double in size when filled


### pop_front/pop_back

* The front/back element should be returned
* An error should be thrown if the queue is empty
* The queue should shrink if it is less than a quarter full


## Limitations

* All classes must have overloaded the `<<` stream operator to return a string