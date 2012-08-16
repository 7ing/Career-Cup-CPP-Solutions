/*
 * MyQueue.h
 *
 *  Created on: Aug 10, 2012
 *      Author: MiTKooK
 */

/*
 * Queue:
 * 1. LinkedList Implementation
 * 2. Circular Array Implementation
 */
#ifndef MYQUEUE_H_
#define MYQUEUE_H_

#include <cstdlib>

template<class T>
struct MyQueueNode {
	MyQueueNode(T data) :
		_data(data), _next(NULL) {
	}
	T _data;
	MyQueueNode * _next;
};

template<class T>
class MyQueue {
public:
	virtual ~MyQueue() = 0;
	virtual bool empty() const = 0;
	virtual int size() const = 0;
	virtual T& front() = 0;
	virtual const T& front() const = 0;
	virtual T& back() = 0;
	virtual const T& back() const = 0;
	virtual void push(const T& data) = 0;
	virtual void pop() = 0;
};

template<class T>
MyQueue<T>::~MyQueue<T>() {
}

/*
 * LinkedList Implementation
 */

template<class T>
class MyLinkedListQueue: public MyQueue<T> {
public:
	MyLinkedListQueue<T> () {
		_head = NULL;
		_tail = NULL;
		_size = 0;
	}
	~MyLinkedListQueue<T> ();
	bool empty() const {
		return _head == NULL;
	}
	int size() const {
		return _size;
	}
	T& front() {
		return _head->_data;
	}
	const T& front() const {
		return _head->_data;
	}
	T& back() {
		return _tail->_data;
	}
	const T& back() const {
		return _tail->_data;
	}
	void push(const T& data);
	void pop();
private:
	MyQueueNode<T> * _head;
	MyQueueNode<T> * _tail;
	int _size;
};

template<class T>
MyLinkedListQueue<T>::~MyLinkedListQueue<T>() {
	while (_head != _tail) {
		MyQueueNode<T> * node = _head;
		_head = _head->_next;
		delete node;
		_size--;
	}
	if (_head && _tail) {
		delete _head;
		_head = NULL;
		_tail = NULL;
		_size--;
	}
}

template<class T>
void MyLinkedListQueue<T>::push(const T& data) {
	MyQueueNode<T> *node = new MyQueueNode<T> (data);
	if (_tail) {
		_tail->_next = node;
		_tail = node;
	} else {
		_head = node;
		_tail = node;
	}
	_size++;
}

template<class T>
void MyLinkedListQueue<T>::pop() {
	MyQueueNode<T> * node = _head;
	if (_head)
		_head = _head->_next;
	if (_head == NULL)
		_tail = NULL;
	delete node;
	_size--;
}

/*
 * Circular Array Implementation
 */
template<class T>
class MyArrayQueue: public MyQueue<T> {
public:
	MyArrayQueue<T> () {
		_head = NULL;
		_tail = NULL;
		QUEUESIZE = 10;
	}
	MyArrayQueue<T> (int size) {
		_head = NULL;
		_tail = NULL;
		QUEUESIZE = size;
		_queue = new T[QUEUESIZE];
	}
	~MyArrayQueue<T> ();
	bool empty() const {
		return _head == NULL;
	}
	int size() const;
	T& front() {
		return *_head;
	}
	const T& front() const {
		return *_head;
	}
	T& back() {
		return *_tail;
	}
	const T& back() const {
		return *_tail;
	}
	void push(const T& data);
	void pop();

private:
	T * _queue;
	T * _head;
	T * _tail;
	int QUEUESIZE;
};

template<class T>
MyArrayQueue<T>::~MyArrayQueue<T>() {
	_head = NULL;
	_tail = NULL;
	delete[] _queue;
}

template<class T>
int MyArrayQueue<T>::size() const {
	if (_head == NULL)
		return 0;
	if (_head <= _tail)
		return _tail - _head + 1;
	else
		return QUEUESIZE - (_head - _tail) + 1;
}

template<class T>
void MyArrayQueue<T>::push(const T& data) {
	if (_head && (_tail + 1 - _queue) % QUEUESIZE != _head - _queue) {
		_tail = (_tail + 1 - _queue) % QUEUESIZE + _queue;
		*_tail = data;
	} else if (_head == NULL) {
		_queue[0] = data;
		_head = _queue;
		_tail = _queue;
	} else
		cout << "Queue Overflow!" << endl;
}

template<class T>
void MyArrayQueue<T>::pop() {
	if (_head != _tail) {
		_head = (_head + 1 - _queue) % QUEUESIZE + _queue;
	} else {
		_head = NULL;
		_tail = NULL;
	}

}

#endif /* MYQUEUE_H_ */
