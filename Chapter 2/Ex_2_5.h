/*
 * Ex_2_5.h
 *
 *  Created on: Aug 9, 2012
 *      Author: MiTKooK
 */

/*
 * Given a circular linked list, implement an algorithm which returns nodes
 * at the beginning of the loop.
 * DEFINITION
 * Circular linked list: A (corrupt) linked list in which a node's next pointer points
 * to an earlier node, so as to make a loop in the linked list.
 * EXAMPLE
 * input: A->B->C->D->E->C [the same C as earlier]
 * output: C
 */
#ifndef EX_2_5_H_
#define EX_2_5_H_

#include <iostream>
#include <cstdlib>
#include "..\My Lib\MyList.h"
using namespace std;

/*
 * If we move two pointers, one with speed 1 and another with speed 2, they will end up meeting if the linked list has a loop. Why? Think about two cars driving on a track¡ªthe faster car will always pass the slower one!
 The tricky part here is finding the start of the loop. Imagine, as an analogy, two people racing around a track, one running twice as fast as the other. If they start off at the same place, when will they next meet? They will next meet at the start of the next lap.
 Now, let¡¯s suppose Fast Runner had a head start of k meters on an n step lap. When will they next meet? They will meet k meters before the start of the next lap. (Why? Fast Runner would have made k + 2(n - k) steps, including its head start, and Slow Runner would have made n - k steps. Both will be k steps before the start of the loop.)
 Now, going back to the problem, when Fast Runner (n2) and Slow Runner (n1) are moving around our circular linked list, n2 will have a head start on the loop when n1 enters. Specifically, it will have a head start of k, where k is the number of nodes before the loop. Since n2 has a head start of k nodes, n1 and n2 will meet k nodes before the start of the loop.
 So, we now know the following:
 1. Head is k nodes from LoopStart (by definition).
 2. MeetingPoint for n1 and n2 is k nodes from LoopStart (as shown above).
 Thus, if we move n1 back to Head and keep n2 at MeetingPoint, and move them both at the same pace, they will meet at LoopStart.
 */
template<class T>
MyNode<T> * find_loop_func(MyNode<T> * head) {
	if (!head)
		return NULL;

	MyNode<T> *p1 = head;
	MyNode<T> *p2 = head;

	while (p2) {
		p1 = p1->_next; //p1++
		p2 = p2->_next; //p2++
		if (p2)
			p2 = p2->_next; //p2++
		else
			return NULL;
		if(p1==p2)
			break;
	}

	p1 = head;
	while (p1 != p2) {
		p1 = p1->_next; //p1++
		p2 = p2->_next; //p2++
	}

	return p1;
}

void test() {
	// A->B->C->D->E->F->C
	MyNode<char> A('A'), B('B'), C('C'), D('D'), E('E'), F('F');
	A._next = &B;
	B._next = &C;
	C._next = &D;
	D._next = &E;
	E._next = &F;
	F._next = &C;

	cout << "A->B->C->D->E->F->C" << endl;
	cout << find_loop_func(&A)->_data << endl;

}

#endif /* EX_2_5_H_ */
