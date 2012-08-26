/*
 * Ex_4_5.h
 *
 *  Created on: Aug 25, 2012
 *      Author: jliu
 */

/*
 * Write an algorithm to find the 'next' node (i.e., in-order successor) of a given node
 * in a binary search tree where each node has a link to its parent.
 */

#ifndef EX_4_5_H_
#define EX_4_5_H_

#include<iostream>
#include<cstdlib>
#include"../My Lib/MyBST.h"
using namespace std;

/*
 * in-order successor: O(n) time
 */
template<class T>
TreeNode<T> * nextNode(TreeNode<T> * node) {

	if(!node)
		return NULL;

	TreeNode<T> * next;

	if(node->_right) { // if has right, find the smallest node in right subtree
		next = node->_right;
		while(next->_left)
			next = next->_left;
	} else { // if has no right subtree, find the first larger node in parents
		next = node->_parent;
		while(next->_data < node->_data)
			next = next->_parent;
	}

	return next;

}

template<class T>
void in_order_print(TreeNode<T> * root) {
	if (root) {
		if (root->_left)
			in_order_print(root->_left);
		cout << root->_data << " , ";
		if (root->_right)
			in_order_print(root->_right);
	}
}

void test() {
	MyBST<char> *tree = new MyBST<char>();
	char array[10];
	for (int i = 0; i < 10; i++)
		array[i] = char('A' + i);
	tree->addToTree(array, 0, 9);

	cout<<"in-order traversal the tree:"<<endl;
	in_order_print<char>(tree->getRoot());
	cout<<endl;

	cout<<"B's next node is: "<<nextNode<char>(tree->find('B'))->_data<<endl;
	cout<<"D's next node is: "<<nextNode<char>(tree->find('D'))->_data<<endl;
	cout<<"E's next node is: "<<nextNode<char>(tree->find('E'))->_data<<endl;
}

#endif /* EX_4_5_H_ */
