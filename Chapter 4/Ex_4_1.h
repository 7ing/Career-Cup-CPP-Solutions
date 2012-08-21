/*
 * Ex_4_1.h
 *
 *  Created on: Aug 19, 2012
 *      Author: jliu
 */

/*
 * Implement a function to check if a tree is balanced. For the purpose of this question,
 * a balance tree is defined to be a tree such that no two leaf nodes differ in distance
 * from the root by more than one.
 */

#ifndef EX_4_1_H_
#define EX_4_1_H_

#include <iostream>
#include "../My Lib/MyBST.h"
using namespace std;

char result[2][6] = { "False", "True" };

/*
 * post traversal, O(n) time
 * solution for full definition of balance search tree:
 * 1. both left and right subtree is balance search tree
 * 2. height difference of left and right subtree <= 1
 */

template<class T>
bool isBalancedTree(TreeNode<T> * root) {
	int depth = 0;
	return isBalancedTree(root, &depth);
}

template<class T>
bool isBalancedTree(TreeNode<T> * root, int * depth) {
	if (!root) {
		*depth = 0;
		return true;
	}

	int left, right;
	if (isBalancedTree(root->_left, &left)
			&& isBalancedTree(root->_right, &right)) {
		int diff = left - right;
		if (diff <= 1 && diff >= -1) {
			*depth = 1 + (left > right ? left : right);
			return true;
		}
	}

	return false;

}

void test() {
	int a[10];
	for (int i = 0; i < 10; i++)
		a[i] = i;
	MyBST<int> bst;
	bst.addToTree(a, 0, 9);
	cout << result[isBalancedTree(bst.getRoot())] << endl;
	bst.insert(10);
	cout << result[isBalancedTree(bst.getRoot())] << endl;
	bst.insert(-1);
	cout << result[isBalancedTree(bst.getRoot())] << endl;
	bst.insert(5);
	bst.insert(8);
	cout << result[isBalancedTree(bst.getRoot())] << endl;
	bst.insert(-2);
	cout << result[isBalancedTree(bst.getRoot())] << endl;
}

#endif /* EX_4_1_H_ */
