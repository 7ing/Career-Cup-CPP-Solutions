/*
 * Ex_4_6.h
 *
 *  Created on: Aug 26, 2012
 *      Author: jliu
 */

/*
 * Design an algorithm and write code to find the first common ancestor of two nodes
 * in a binary tree. Avoid storing additional nodes in a data structure.
 * NOTE: This is not necessarily a binary search tree.
 *
 * PS:
 * Attempts 2 in the book does't cover a case -- two target nodes are identical, and, root is one of the node
 * Attempts 3 in the book could not handle the case --- two target nodes are identical
 *
 * In this solution, if root is one of the node, return NULL (root's parent)
 */

#ifndef EX_4_6_H_
#define EX_4_6_H_

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../My Lib/MyBST.h"
using namespace std;

/*
 * 1st approach: bottom to top
 * Suppose every tree node has a pointer to its parent
 * O(n) time : touch every node once
 */
template<class T>
TreeNode<T> * findCommonAncestor(TreeNode<T> * node1, TreeNode<T> * node2) {
	TreeNode<T> *result = node1;
	if (findNode(result, node2)) // true means node1 is node2's ancestor
		return result->_parent;
	// use parent pointer to avoid repeat searching on subtree of "result"
	TreeNode<T> * parent = result->_parent;
	while (parent) {
		if (parent == node2) // true means node2 is node1's ancestor
			return parent->_parent;
		else if ((parent->_left == result && findNode(parent->_right, node2))
				|| (parent->_right == result && findNode(parent->_left, node2))) {
			return parent;
		} else {
			result = parent;
			parent = result->_parent;
		}
	}
	return NULL;
}

/*
 * find the node in subtree of root
 * O(n) time : because it is not a binary search tree, either side will be searched
 */
template<class T>
bool findNode(TreeNode<T> * root, TreeNode<T> * node) {
	if (!root)
		return false;
	if (root == node)
		return true;

	return findNode(root->_left, node) || findNode(root->_right, node);
}

/*
 * 2nd approach: top to bottom
 * Suppose no pointer to the parent
 * O(n^2) time: touch a node multiple times due to findNodes()
 */
template<class T>
TreeNode<T> * findCommonAncestor(TreeNode<T> * root, TreeNode<T> * node1,
		TreeNode<T> * node2) {
	if (!root)
		return NULL;

	// in case node1 == node2
	if (node1 == node2 && (root->_left == node1 || root->_right == node1))
		return root;

	int left = findNodes(root->_left, node1, node2); // if node1 == node2, left = 2
	if (left == 2) {
		if (root->_left == node1 || root->_left == node2)
			return root;
		else
			return findCommonAncestor(root->_left, node1, node2);
	}

	int right = findNodes(root->_right, node1, node2); // if node2 == node1, right = 2
	if (right == 2) {
		if (root->_right == node1 || root->_right == node2)
			return root;
		else
			return findCommonAncestor(root->_right, node1, node2);
	}

	if (left == 1 && right == 1) {
		return root;
	}

	return NULL;
}

/*
 * find # of node1 and node2 in subtree of root
 * O(n) time: could search both sides of the tree
 */
template<class T>
int findNodes(TreeNode<T> * root, TreeNode<T> * node1, TreeNode<T> * node2) {
	if (!root)
		return 0;
	int num = 0;
	if (root == node1)
		num++;
	if (root == node2) // in case node1 == node2
		num++;
	num += findNodes(root->_left, node1, node2);
	if (num == 2)
		return 2;

	return num + findNodes(root->_right, node1, node2);
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

	cout << "in-order traversal the tree:" << endl;
	in_order_print<char>(tree->getRoot());
	cout << endl << "find common ancestor: " << endl;

	TreeNode<char> * result;
	srand((unsigned) time(NULL));
	for (int i = 0; i < 10; i++) {
		int index1 = rand() % 10;
		int index2 = rand() % 10;
		result = findCommonAncestor(tree->find('A' + index1),
				tree->find('A' + index2));
		cout << char('A' + index1) << " & " << char('A' + index2) << " : ";
		if (result)
			cout << result->_data << " , ";
		else
			cout << "NULL" << " , ";
		result = findCommonAncestor(tree->getRoot(), tree->find('A' + index1),
				tree->find('A' + index2));
		if (result)
			cout << result->_data << endl;
		else
			cout << "NULL" << endl;
	}
}

#endif /* EX_4_6_H_ */
