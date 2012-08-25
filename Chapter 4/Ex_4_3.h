/*
 * Ex_4_3.h
 *
 *  Created on: Aug 25, 2012
 *      Author: jliu
 */

/*
 * Given a sorted (increasing order) array, write an algorithm to create a binary tree
 * with minimal height.
 */

#ifndef EX_4_3_H_
#define EX_4_3_H_

#include<iostream>
#include<cstdlib>
#include"../My Lib/MyBST.h"
using namespace std;

/*
 * creat a BST for this array
 * pre-order traversal: O(n) time
 * return the root of this BST
 */
template<class T>
TreeNode<T> * orderedArrayToTree(TreeNode<T> * parent, int * array, int from,
		int to) {
	if (from > to)
		return NULL;
	else {
		int mid = (from + to) / 2;
		TreeNode<T> * node = new TreeNode<T>(array[mid]);
		node->_parent = parent;
		node->_left = orderedArrayToTree(node, array, from, mid - 1);
		node->_right = orderedArrayToTree(node, array, mid + 1, to);
		return node;
	}
}

template<class T>
void printBinaryTree(TreeNode<T> * root) {
	if (!root)
		return;
	cout << root->_data << " ";
	if (root->_left)
		printBinaryTree<T>(root->_left);
	if (root->_right)
		printBinaryTree<T>(root->_right);
}

void test() {
	int array[10];
	cout<<"array: ";
	for (int i = 0; i < 10; i++) {
		array[i] = i;
		cout<<i<<" ";
	}
	TreeNode<int> * root = orderedArrayToTree<int>(NULL, array, 0, 9);
	cout<<endl<<"after insert (pre-ordered traversal): "<<endl<<"Binary Tree: ";
	printBinaryTree<int>(root);
}

#endif /* EX_4_3_H_ */
