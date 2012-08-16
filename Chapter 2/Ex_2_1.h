/*
 * Ex_2_1.h
 *
 *  Created on: Aug 5, 2012
 *      Author: MiTKooK
 */

/*
 * Write code to remove duplicates from an unsorted linked list.
 * FOLLOW UP
 * How would you solve this problem if a temporary buffer is not allowed?
 */

#ifndef EX_2_1_H_
#define EX_2_1_H_

#include <iostream>
#include <tr1/unordered_map>
#include <list>
#include <cstdlib>
using namespace std;

/*
 * method 1: with buffer
 * O(n) time, O(n) space
 */
template<class T>
void rm_duplicates_func(list<T> &li) {

	if (li.empty())
		return;

	std::tr1::unordered_map<T, bool> buffer;
	typename list<T>::iterator i;
	bool flag;

	for (i = li.begin(); i != li.end(); i++) {
		flag = false;
		if (buffer.find(*i) != buffer.end()) {
			flag = true;
			i = li.erase(i);
			i--;
		}
		if (!flag)
			buffer.insert(make_pair(*i, true));
	}

}

/*
 * method 2: without buffer
 * O(n^2) time, O(1) space
 */
template<class T>
void rm_duplicates_no_buffer_func(list<T> &li) {

	if (li.empty())
		return;
	typename list<T>::iterator i;
	typename list<T>::iterator j;

	for (i = li.begin(); i != li.end(); i++) {
		for (j = li.begin(); j != i; j++) {
			if (*i == *j) {
				i = li.erase(i);
				i--;
				break;
			}
		}
	}

}

void test() {

	list<int> l;
	for (int i = 0; i < 10; i++) {
		l.push_back(i);
		cout << i << " ";
		if (rand() % 2) {
			l.push_back(i);
			cout << i << " ";
		}
	}

	cout << endl << "after remove duplicates:" << endl;

	rm_duplicates_func(l);
	//	rm_duplicates_no_buffer_func(l);

	list<int>::iterator it;
	for (it = l.begin(); it != l.end(); it++) {
		cout << *it << " ";
	}

}

#endif /* EX_2_1_H_ */
