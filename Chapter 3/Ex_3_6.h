/*
 * Ex_3_6.h
 *
 *  Created on: Aug 18, 2012
 *      Author: jliu
 */

/*
 * Write a program to sort a stack in ascending order. You should not make any assumptions
 * about how the stack is implemented. The following are the only functions that should be
 * used to write this program:
 * push | pop | peek | isEmpty
 *
 * in C++ STL: push | pop | top | empty
 */

#ifndef EX_3_6_H_
#define EX_3_6_H_

#include <iostream>
#include <stack>
#include <cstdlib>
using namespace std;

/*
 * using insert sort idea
 * O(n^2) time, O(n) space
 */
template<class T>
stack<T> sort_stack_func(stack<T> &st) {
	stack<T> temp;
	while (!st.empty()) {
		T insert_val = st.top();
		st.pop();
		while (!temp.empty() && temp.top() > insert_val) {
			st.push(temp.top());
			temp.pop();
		}
		temp.push(insert_val);
	}
	return temp;
}

void test() {
	stack<int> st;
	cout << "stack from bottom to top: ";
	for (int i = 0; i < 10; i++) {
		int num = rand() % 100;
		st.push(num);
		cout << num << ", ";
	}
	cout << endl << "after sort, from top to bottom: ";
	st = sort_stack_func(st);
	while (!st.empty()) {
		cout << st.top() << ", ";
		st.pop();
	}

}

#endif /* EX_3_6_H_ */
