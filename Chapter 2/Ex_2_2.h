/*
 * Ex_2_2.h
 *
 *  Created on: Aug 8, 2012
 *      Author: MiTKooK
 */

/*
 * Implement an algorithm to find the nth to last element of a singly linked list
 */

#ifndef EX_2_2_H_
#define EX_2_2_H_

#include <iostream>
#include "../My Lib/MyList.h"
#include <cstdlib>
using namespace std;

template<class T>
T * nth_to_last_func(MySinglyLinkedList<T> const& lst, int n) {
	if (n <= 0 || lst.empty()) {
		return NULL;
	}

	MyNode<T> * p1 = lst.const_begin();
	MyNode<T> * p2 = p1;

	for(int i=0;i<n-1;i++) {
		p2 = p2->_next;
		if(!p2)
			return NULL;
	}

	while(p2->_next) {
		p1 = p1->_next;
		p2 = p2->_next;

	}

	return &(p1->_data);

}

void test() {

	MySinglyLinkedList<int> lst;

	int n = 10;

	for (int i = 0; i < 10; i++)
		lst.push_back(i);

	cout << "The " << n << "th to the last element is: "
			<< *nth_to_last_func(lst, n) << endl;

}

#endif /* EX_2_2_H_ */
