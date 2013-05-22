/*
 * Ex_3_1.h
 *
 *  Created on: Aug 11, 2012
 *      Author: MiTKooK
 */

/*
 * Describe how you could use a single array to implement three stacks.
 */

#ifndef EX_3_1_H_
#define EX_3_1_H_

#include <iostream>
#include <cstdlib>
#include <list>
using namespace std;

/*
 * Method 1: equally assign spaces for each stack
 * O(1) time for push and pop, O(1) space
 *
 */

template<class T>
class ThreeStacks {
public:
	ThreeStacks<T>() {
		ARRAYSIZE = 30;
		_array = new T[ARRAYSIZE];
		_stack[0] = NULL;
		_stack[1] = NULL;
		_stack[2] = NULL;
	}
	ThreeStacks<T>(int size) {
		ARRAYSIZE = size;
		_array = new T[ARRAYSIZE];
		_stack[0] = NULL;
		_stack[1] = NULL;
		_stack[2] = NULL;
	}
	bool empty(int stack_num) const {
		return _stack[stack_num] == NULL;
	}
	int size(int stack_num) const;
	T& top(int stack_num) {
		if (_stack[stack_num])
			return *_stack[stack_num];
		else {
			cout << "No Element in the stack!";
			exit(1);
		}
	}
	const T& top(int stack_num) const {
		if (_stack[stack_num])
			return *_stack[stack_num];
		else {
			cout << "No Element in the stack!";
			exit(1);
		}
	}
	void push(int stack_num, const T& data);
	void pop(int stack_num);

private:
	T *_array;
	T *_stack[3];
	int ARRAYSIZE;
};

template<class T>
int ThreeStacks<T>::size(int stack_num) const {
	if (_stack[stack_num] == NULL)
		return 0;
	else
		return _stack[stack_num] - _array - stack_num * ARRAYSIZE / 3 + 1;
}

template<class T>
void ThreeStacks<T>::push(int stack_num, const T& data) {
	if (_stack[stack_num] == NULL) {
		_stack[stack_num] = _array + stack_num * ARRAYSIZE / 3;
		*_stack[stack_num] = data;
	} else if (_stack[stack_num]
			< _array + (stack_num + 1) * ARRAYSIZE / 3 - 1) {
		*(++_stack[stack_num]) = data;
	} else {
		cout << " Stack Overflow!" << endl;
	}
}

template<class T>
void ThreeStacks<T>::pop(int stack_num) {
	if (_stack[stack_num]) {
		_stack[stack_num]--;
	}
	if (_stack[stack_num] == _array + stack_num * ARRAYSIZE / 3)
		_stack[stack_num] = NULL;
}

/*
 * Method 2: using extra list to store free spaces, based on linked list idea
 * O(1) time for push and pop, O(n) space: could maximize array usage
 */
template<class T>
struct StackNode {
	StackNode() :
			_data(0), _next(NULL) {
	}
	StackNode(T data) :
			_data(data), _next(NULL) {
	}
	T _data;
	StackNode<T> * _next;
};

template<class T>
class ThreeFlexStacks {
public:
	ThreeFlexStacks<T>() {
		_size = 30;
		_array = new StackNode<T> [30];
		_stack[0] = NULL;
		_stack[1] = NULL;
		_stack[2] = NULL;
	}
	ThreeFlexStacks<T>(int size) :
			_size(size) {
		_array = new StackNode<T> [size];
		_stack[0] = NULL;
		_stack[1] = NULL;
		_stack[2] = NULL;
		for (int i = 1; i < _size; i++) {
			_free.push_front(&_array[i]);
		}
	}

	bool empty(int stack_num) const {
		return _stack[stack_num] == NULL;
	}
	int size(int stack_num) const;
	T& top(int stack_num) {
		if (_stack[stack_num])
			return _stack[stack_num]->_data;
		else {
			cout << "No Element in the stack!";
			exit(1);
		}
	}
	const T& top(int stack_num) const {
		if (_stack[stack_num])
			return _stack[stack_num]->_data;
		else {
			cout << "No Element in the stack!";
			exit(1);
		}
	}
	void push(int stack_num, const T& data);
	void pop(int stack_num);

private:
	StackNode<T> *_array;
	list<StackNode<T> *> _free;
	StackNode<T> *_stack[3];
	int _size;
};

template<class T>
int ThreeFlexStacks<T>::size(int stack_num) const {
	if (_stack[stack_num] == NULL)
		return 0;
	else {
		int size = 0;
		StackNode<T> * p = _stack[stack_num];
		while (p) {
			size++;
			p = p->_next;
		}
		return size;
	}
}

template<class T>
void ThreeFlexStacks<T>::push(int stack_num, const T& data) {
	if (!_free.empty()) {
		StackNode<T> *top = _stack[stack_num];
		_stack[stack_num] = _free.front();
		_stack[stack_num]->_next = top;
		_stack[stack_num]->_data = data;
		_free.pop_front();
	} else
		cout << " Stack Overflow!" << endl;
}

template<class T>
void ThreeFlexStacks<T>::pop(int stack_num) {
	if (_stack[stack_num]) {
		StackNode<T> *free_node = _stack[stack_num];
		_stack[stack_num] = _stack[stack_num]->_next;
		_free.push_front(free_node);
	} else {
		cout << "Stack Underflow!" << endl;
	}
}

void test() {

	ThreeFlexStacks<int> *ts = new ThreeFlexStacks<int>();
	ts->push(2, 4);
	cout << ts->top(2) << endl;
	ts->push(1, 3);
	ts->push(1, 7);
	ts->push(1, 5);
	cout << ts->top(1) << endl;
	cout << "size of 0: " << ts->size(1) << endl;
	ts->pop(1);
	cout << ts->top(1) << endl;
	ts->pop(1);
	cout << ts->top(1) << endl;
	ts->pop(1);
//	cout << ts->top(1) << endl;
	ts->pop(0);
}

#endif /* EX_3_1_H_ */
