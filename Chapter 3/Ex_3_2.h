/*
 * Ex_3_2.h
 *
 *  Created on: Aug 12, 2012
 *      Author: MiTKooK
 */

/*
 * How would you design a stack which, in addition to push and pop, also has a function min which returns the minimum element?
 * Push, pop and min should all operate in O(1) time.
 */

#ifndef EX_3_2_H_
#define EX_3_2_H_

#include <iostream>
#include "..\My Lib\MyStack.h"
using namespace std;

/*
 * use an extra stack to store min value of current stack
 * O(1) time for push/pop min, O(n) space
 */
template<class T>
class MinStack: public MyLinkedListStack<T> {
public:
	MinStack<T> () :
		MyLinkedListStack<T> () {
		_min = NULL;
	}
	~MinStack<T> ();
	T& min();
	const T& min() const;
	void push(const T& data);
	void pop();
private:
	MyStackNode<T> * _min;
};

template<class T>
MinStack<T>::~MinStack<T>() {
	MyStackNode<T> *p;
	while (_min) {
		p = _min;
		_min = _min->_next;
		delete p;
	}
}

template<class T>
T& MinStack<T>::min() {
	if(_min)
		return _min->_data;
	else {
		cout<<"No Element in the stack";
		exit(1);
	}
}

template<class T>
const T& MinStack<T>::min() const {
	if(_min)
		return _min->_data;
	else {
		cout<<"No Element in the stack";
		exit(1);
	}
}

template<class T>
void MinStack<T>::push(const T& data) {
	MyLinkedListStack<T>::push(data);
	if (_min == NULL || data <= _min->_data) {
		MyStackNode<T> *node = new MyStackNode<T> (data);
		if (!node)
			return;
		node->_next = _min;
		_min = node;
	}
}

template<class T>
void MinStack<T>::pop() {
	if (_min && MyLinkedListStack<T>::top() == _min->_data) {
		MyStackNode<T> * p = _min;
		_min = _min->_next;
		delete p;
	}
	MyLinkedListStack<T>::pop();
}

void test() {

	MinStack<int> *ms = new MinStack<int> ();
	for (int i = 0; i < 15; i++) {
		int value = rand()%10;
		ms->push(value);
		cout<<value<<", ";
	}
	cout<<endl;
	for (int i = 0; i < 15; i++) {
		cout<<"Popped "<<ms->top()<<" ; ";
		ms->pop();
		cout<<"New min is "<<ms->min()<<endl;
	}

}

#endif /* EX_3_2_H_ */
