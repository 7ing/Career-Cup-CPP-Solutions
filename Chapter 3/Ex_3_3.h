/*
 * Ex_3_3.h
 *
 *  Created on: Aug 15, 2012
 *      Author: MiTKooK
 */

/*
 * Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
 * Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold.
 * Implement a data structure SetOfStacks that mimics this. SetOfStacks should be composed of several stacks,
 * and should create a new stack once the previous one exceeds capacity. SetOfStacks.push() and SetOfStacks.pop()
 * should behave identically to a single stack (that is, pop() should return the same values
 * as it would if there were just a single stack).
 * FOLLOW UP
 * Implement a function popAt(int index) which performs a pop operation on a specific sub-stack.
 */

#ifndef EX_3_3_H_
#define EX_3_3_H_

#include <iostream>
#include <list>
#include <stack>
using namespace std;

template<class T>
class NewStack {
public:
	NewStack<T> () {
		_capacity = 5;
	}
	NewStack<T> (unsigned int capacity) {
		_capacity = capacity;
	}
	~NewStack<T> () {
		while (!_stack.empty())
			_stack.pop();
		_capacity = 0;
	}
	bool empty() const {
		return _stack.empty();
	}
	unsigned int size() const {
		return _stack.size();
	}
	T& top() {
		return _stack.top();
	}
	const T& top() const {
		return _stack.top();
	}
	bool push(const T& data);
	void pop() {
		_stack.pop();
	}
private:
	stack<T> _stack;
	unsigned int _capacity;
};

template<class T>
inline bool NewStack<T>::push(const T& data) {
	if (_stack.size() >= _capacity)
		return false;
	else {
		_stack.push(data);
		return true;
	}
}

/*
 * use a list to store stacks' pointer, do not support roll over function
 * O(1) time for push/pop, O(n) time for popAt(), O(n) space
 */

template<class T>
class SetOfStacks {
public:
	SetOfStacks<T> () {
		_capacity_per_substack = 5;
	}
	SetOfStacks<T> (unsigned int capacity) {
		_capacity_per_substack = capacity;
	}
	~SetOfStacks<T> ();
	bool empty() const {return _stacks.empty();}
	unsigned int size() const;
	T& top() {return _stacks.back().top();}
	const T& top() const {return _stacks.back().top();}
	void push(const T& data);
	void pop();
	void popAt(int index);
private:
	list<NewStack<T> > _stacks;
	unsigned int _capacity_per_substack;
};

template<class T>
SetOfStacks<T>::~SetOfStacks<T>() {

}

template<class T>
inline unsigned int SetOfStacks<T>::size() const {
	return 0;
}

template<class T>
void SetOfStacks<T>::push(const T& data) {

	if(!_stacks.back().empty() && _stacks.back().size()<_capacity_per_substack)
		_stacks.back().push(data);
	else {
		NewStack<T> *new_stack = new NewStack<T>(_capacity_per_substack);
		new_stack->push(data);
		_stacks.push_back(*new_stack);
	}

}

template<class T>
void SetOfStacks<T>::pop() {
	_stacks.back().pop();
	if(_stacks.back().empty())
		_stacks.pop_back();
}

template<class T>
void SetOfStacks<T>::popAt(int index) {
	typename list<NewStack<T> >::iterator it = _stacks.begin();
	cout<<"popAt("<<index<<"):";
	while(index--) {
		it++;
	}
	cout<<(*it).top();
	cout<<endl;
	(*it).pop();
	if((*it).empty()) {
		_stacks.erase(it);
		cout<<"Stack erased"<<endl;
	}
}

void test() {
	SetOfStacks<int> *set = new SetOfStacks<int> (5);
	for (int i = 0; i < 34; i++) {
		set->push(i);
	}
	for (int i = 0; i < 10; i++) {
		cout << "Popped " << set->top() << endl;
		set->pop();
	}


	set->popAt(1);
	set->popAt(1);
	set->popAt(1);
	set->popAt(1);
	set->popAt(1);
	set->popAt(1);

}

#endif /* EX_3_3_H_ */
