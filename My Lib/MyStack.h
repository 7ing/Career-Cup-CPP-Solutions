/*
 * MyStack.h
 *
 *  Created on: Aug 9, 2012
 *      Author: MiTKooK
 */

/*
 * Stack:
 * 1. Linked List Implementation
 * 2. Array Implementation
 */

#ifndef MYSTACK_H_
#define MYSTACK_H_

#include <cstdlib>

template<class T>
struct MyStackNode {
	MyStackNode(T data) :
		_data(data), _next(NULL) {
	}
	T _data;
	MyStackNode * _next;
};

template<class T>
class MyStack {
public:
	virtual ~MyStack() = 0;
	virtual bool empty() const = 0;
	virtual int size() const = 0;
	virtual T& top() = 0;
	virtual const T& top() const = 0;
	virtual void push(const T& data) = 0;
	virtual void pop() = 0;
};

template<class T>
MyStack<T>::~MyStack<T>() {
}

template<class T>
class MyLinkedListStack: public MyStack<T> {
public:
	MyLinkedListStack<T> () {
		_top = NULL;
		_size = 0;
	}
	~MyLinkedListStack<T> ();
	bool empty() const {
		return _size == 0;
	}
	int size() const {
		return _size;
	}
	T& top();
	const T& top() const;
	void push(const T& data);
	void pop();
private:
	MyStackNode<T> * _top;
	int _size;
};

template<class T>
MyLinkedListStack<T>::~MyLinkedListStack<T>() {
	MyStackNode<T> *p;
	while (_top) {
		p = _top;
		_top = _top->_next;
		_size--;
		delete p;
	}
}

template<class T>
T& MyLinkedListStack<T>::top() {
	return _top->_data;
}

template<class T>
const T& MyLinkedListStack<T>::top() const {
	return _top->_data;
}

template<class T>
void MyLinkedListStack<T>::push(const T& data) {
	MyStackNode<T> *node = new MyStackNode<T> (data);
	if (!node)
		return;
	node->_next = _top;
	_top = node;
	_size++;
}

template<class T>
void MyLinkedListStack<T>::pop() {
	if (_top) {
		MyStackNode<T> * p = _top;
		_top = _top->_next;
		delete p;
		_size--;
	}
}

/*
 * Array Implementation
 */
template<class T>
class MyArrayStack: public MyStack<T> {
public:
	MyArrayStack<T> () {
		new (this)MyArrayStack<T>(30);
	}
	MyArrayStack<T> (int size) {
		STACKSIZE = size;
		_stack = new T[STACKSIZE];
		_top = NULL;
	}
	~MyArrayStack<T> ();
	bool empty() const {
		return _top == NULL;
	}
	int size() const {
		return _top == NULL ? 0 : _top - _stack + 1;
	}
	T& top();
	const T& top() const;
	void push(const T& data);
	void pop();
private:
	T *_stack;
	T * _top;
	int STACKSIZE;
};

template<class T>
MyArrayStack<T>::~MyArrayStack<T>() {
	_top = NULL;
	delete[] _stack;
}

template<class T>
T& MyArrayStack<T>::top() {
	return *_top;
}

template<class T>
const T& MyArrayStack<T>::top() const {
	return *_top;
}

template<class T>
void MyArrayStack<T>::push(const T& data) {
	if (_top == NULL) {
		_top = _stack;
		*_top = data;
	} else if (size() < STACKSIZE) {
		*(++_top) = data;
	} else
		std::cout << "Stack Overflow!" << std::endl;
}

template<class T>
void MyArrayStack<T>::pop() {
	if (_top > _stack) {
		_top--;
	} else if (_top == _stack) {
		_top = NULL;
	} else {
		std::cout << "Stack Underflow!" << std::endl;
	}
}

#endif /* MYSTACK_H_ */
