/*
 * Ex_3_5.h
 *
 *  Created on: Aug 18, 2012
 *      Author: jliu
 */

/*
 * Implement a MyQueue class which implements a queue using two stacks.
 *
 * Microsoft Interview Question
 */
#ifndef EX_3_5_H_
#define EX_3_5_H_

#include <iostream>
#include <stack>
using namespace std;

/*
 * O(n) time, O(n) space
 */
template<class T>
class MyQueue {
public:
	MyQueue<T>() {
	}
	~MyQueue<T>();
	bool empty() const {
		return push_stack.empty() && pop_stack.empty();
	}
	int size() const {
		return push_stack.size() + pop_stack.size();
	}
	T& front() {
		if (pop_stack.empty()) {
			while (!push_stack.empty()) {
				pop_stack.push(push_stack.top());
				push_stack.pop();
			}
		}
		return pop_stack.top();
	}
	void push(const T& data) {
		push_stack.push(data);
	}
	void pop() {
		if (pop_stack.empty()) {
			while (!push_stack.empty()) {
				pop_stack.push(push_stack.top());
				push_stack.pop();
			}
		}
		pop_stack.pop();
	}
private:
	stack<T> push_stack;
	stack<T> pop_stack;
};

template<class T>
MyQueue<T>::~MyQueue<T>() {
	while (!push_stack.empty())
		push_stack.pop();
	while (!pop_stack.empty())
		pop_stack.pop();
}

void test() {
	cout << "queue using two stacks." << endl;
	MyQueue<int> mq;
	cout << "Enqueue: ";
	for (int i = 0; i < 5; i++) {
		mq.push(i);
		cout << i << " ";
	}
	cout << endl << "Dequeue: ";
	for (int i = 0; i < 5; i++) {
		cout << mq.front() << " ";
		mq.pop();
	}
}

#endif /* EX_3_5_H_ */
