/*
 * Ex_4_7.h
 *
 *  Created on: Aug 28, 2012
 *      Author: jliu
 */

/*
 * You have two very large binary trees: T1, with millions of nodes, and T2, with hundreds of nodes.
 * Create an algorithm to decide if T2 is a subtree of T1.
 */

/*
 * Discuss: using suffix tree to verify substring --> will consume too much memory space
 * We could create a string representing the in-order and pre-order traversals. If T2’s pre-order traversal
 * is a substring of T1’s pre-order traversal, and T2’s in-order traversal is a substring of T1’s in-order traversal,
 * then T2 is a substring of T1
 */

#ifndef EX_4_7_H_
#define EX_4_7_H_

#include <iostream>
#include "../My Lib/MyBST.h"
using namespace std;

/*
 * O(n + k* m) time, n= sizeof(T2), m= sizeof(T1), k = # of nodes in T1 that node.key == T2's root.key
 * Worst case O(n*m) time, O(1) space
 * idea:
 * find a possible root in T1, say it is T3, which will cost O(m) time,
 * then verify if T2 is T3's subtree, where T2's root.key == T3's root.key
 */

// O(n) time
template<class T>
bool matchTree(TreeNode<T> * T1, TreeNode<T> * T2) {

	if (!T1 && !T2) // both nothing left
		return true;

	if (!T1 || !T2) // less nodes
		return false;

	if (T1->_data == T2->_data)
		return matchTree(T1->_left, T2->_left)
				&& matchTree(T1->_right, T2->_right);
	else
		return false; // does not match
}

template<class T>
bool isSubTree(TreeNode<T> * T1, TreeNode<T> * T2) {
	if (!T2)
		return true;
	if (!T1)
		return false;
	if (T1->_data == T2->_data) {
		if (matchTree(T1, T2))
			return true;
	}

	return isSubTree(T1->_left, T2) || isSubTree(T1->_right, T2);
}

void test() {
	// t2 is a subtree of t1
	int array1[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
	int array2[6] = {1, 2, 3, 4, 5, 6};

	MyBST<int> T1, T2, T3;

	T1.addToTree(array1,0,12);
	T2.addToTree(array2,0,5);

	if (isSubTree(T1.getRoot(), T2.getRoot()))
		cout<<"t2 is a subtree of t1";
	else
		cout<<"t2 is not a subtree of t1";

	cout<<endl;

	// t3 is not a subtree of t1
	int array3[3] = {1, 2, 3};
	T3.addToTree(array3,0,2);

	if (isSubTree(T1.getRoot(), T3.getRoot()))
		cout<<"t3 is a subtree of t1";
	else
		cout<<"t3 is not a subtree of t1";
}

#endif /* EX_4_7_H_ */
