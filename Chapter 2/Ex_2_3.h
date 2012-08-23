/*
 * Ex_2_3.h
 *
 *  Created on: Aug 9, 2012
 *      Author: MiTKooK
 */

/*
 * Implement an algorithm to delete a node in the middle of a single linked list,
 * given only access to that node.
 * EXAMPLE
 * Input: the node 'c' from the linked list a->b->c->d->e
 * Result: nothing is returned, but the new linked list looks like a->b->d->e
 */

#ifndef EX_2_3_H_
#define EX_2_3_H_

#include <iostream>
#include "../My Lib/MyList.h"
using namespace std;

/*
 * O(1) time, O(1) space
 */
template<class T>
void erase_func(MyNode<T> * position) {

	if (!position && !(position->_next)) // cannot solve: erase last node
		return;

	MyNode<T> * next = position->_next;

	position->_data = next->_data;
	position->_next = next->_next;
	delete next;
}

void test() {
	MySinglyLinkedList<int> lst;

	for (int i = 0; i < 10; i++)
		lst.push_back(i);

	MyNode<int> * p = lst.begin();

	erase_func(p->_next->_next->_next->_next);

	while(p) {
		cout<<p->_data<<"->";
		p = p->_next;
	}
}

#endif /* EX_2_3_H_ */
