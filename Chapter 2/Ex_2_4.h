/*
 * Ex_2_4.h
 *
 *  Created on: Aug 9, 2012
 *      Author: MiTKooK
 */

/*
 * You have two numbers represented by a linked list, where each node contains a single digit.
 * The digits are stored in reverse order, such that the 1's digit is at the head of the list.
 * Write a function that adds the two numbers and returns the sum as a linked list.
 * EXAMPLE
 * Input: (3->1->5)+(5->9->2)
 * Output: 8->0->8
 */

#ifndef EX_2_4_H_
#define EX_2_4_H_

#include <iostream>
#include "../My Lib/MyList.h"
using namespace std;

typedef MySinglyLinkedList<int> myList;

/*
 * O(n) time, O(n) space
 */
myList * add_list_func(myList * a, myList * b) {

	if (!a)
		return b;
	if (!b)
		return a;

	int sum = 0;
	int carry = 0;

	MyNode<int> * pa = a->begin();
	MyNode<int> * pb = b->begin();

	myList * result = new myList();

	while (pa || pb) {

		sum = carry;

		if (pa) {
			sum += pa->_data;
			pa = pa->_next;
		}
		if (pb) {
			sum += pb->_data;
			pb = pb->_next;
		}

		carry = sum >= 10 ? 1 : 0;
		sum = sum % 10;

		result->push_back(sum);
	}

	return result;

}

void test() {
	myList a;
	myList b;

	a.push_back(3);
	a.push_back(1);
	a.push_back(5);
	a.push_back(6);
	b.push_back(5);
	b.push_back(9);
	b.push_back(5);

	// (3->1->5->6) + (5->9->5)

	myList * result = add_list_func(&a, &b);
	MyNode<int> *p = result->begin();
	while (p) {
		cout << p->_data << "->";
		p = p->_next;
	}

}

#endif /* EX_2_4_H_ */
