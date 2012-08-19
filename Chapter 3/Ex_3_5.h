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

template <class T>
class MyQueue {
public:
	MyQueue<T>() {flag = false;}
	~MyQueue<T>();
	bool empty() const {return flag?push_stack.empty():pop_stack.empty();}
	int size() const { return flag?push_stack.size():pop_stack.size();}
	T& front() {if(!flag) {exchange_stack(flag);} return pop_stack.top();}
	T& back() {if(flag) {exchange_stack(flag);} return push_stack.top();}
	void push(const T& data) {if(flag) {exchange_stack(flag);} push_stack.push(data);}
	void pop() {if(!flag) {exchange_stack(flag);} pop_stack.pop();}
private:
	stack<T> push_stack;
	stack<T> pop_stack;
	void exchange_stack(bool fl);
	bool flag;
};

template <class T>
MyQueue<T>::~MyQueue<T>() {
	if(!flag) { // in push stack
		while(!push_stack.empty()) {
			push_stack.pop();
		}
	} else { // in pop stack
		while(!pop_stack.empty()) {
			pop_stack.pop();
		}
	}
}

template <class T>
void MyQueue<T>::exchange_stack(bool fl) {
	if(!fl) { // in push stack
		while(!push_stack.empty()) {
			pop_stack.push(push_stack.top());
			push_stack.pop();
		}
	} else { // in pop stack
		while(!pop_stack.empty()) {
			push_stack.push(pop_stack.top());
			pop_stack.pop();
		}
	}
	fl = !fl;
}


void test() {
	cout<<"queue using two stacks."<<endl;
	MyQueue<int> mq;
	cout<<"Enqueue: ";
	for(int i=0; i<5; i++) {
		mq.push(i);
		cout<<i<<" ";
	}
	cout<<endl<<"Dequeue: ";
	for(int i=0; i<5; i++) {
		cout<<mq.front()<<" ";
		mq.pop();
	}
}


#endif /* EX_3_5_H_ */
