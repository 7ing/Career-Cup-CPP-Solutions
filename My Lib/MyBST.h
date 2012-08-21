/*
 * MyBST.h
 *
 *  Created on: Aug 19, 2012
 *      Author: jliu
 */

/*
 * Binary Search Tree Implementation
 */

#ifndef MYBST_H_
#define MYBST_H_

#include <cstdlib>

template<class T>
struct TreeNode {
	TreeNode(T data) :
			_data(data), _left(NULL), _right(NULL), _parent(NULL) {
	}
	T _data;
	TreeNode<T> * _left;
	TreeNode<T> * _right;
	TreeNode<T> * _parent;
};

template<class T>
class MyBST {
public:
	MyBST<T>() :
			_root(NULL) {
	}
	~MyBST<T>() {
		removeTree(_root);
	}

	bool isBST() {
		return isBST(_root);
	}
	void insert(const T & data) {
		insert(_root, data);
	}
	int height() {
		return height(_root);
	}
	TreeNode<T> * find(const T & data) {
		return find(_root, data);
	}
	void addToTree(T *array, int from, int to) {
		addToTree(NULL, &_root, array, from, to);
	}

private:
	TreeNode<T> * _root;
	void removeTree(TreeNode<T> * tree_root); // pre-order traversal
	bool isBST(TreeNode<T> * current_node);
	void insert(TreeNode<T> * tree_root, const T & data);
	int height(TreeNode<T> * current_node);
	TreeNode<T> * find(TreeNode<T> * tree_root, const T & data);
	void addToTree(TreeNode<T> * parent, TreeNode<T> ** root, T * array,
			int from, int to);
};

template<class T>
void MyBST<T>::removeTree(TreeNode<T> * tree_root) {
	// pre-order traversal
	if (tree_root == NULL)
		return;
	TreeNode<T> * current_node = tree_root;
	TreeNode<T> * left_sub_tree = tree_root->_left;
	TreeNode<T> * right_sub_tree = tree_root->_right;
	delete current_node;
	removeTree(left_sub_tree);
	removeTree(right_sub_tree);
}

template<class T>
bool MyBST<T>::isBST(TreeNode<T> * current_node) {
	if (current_node->_left)
		if (current_node->_left->_data > current_node->_data
				|| !isBST(current_node->_left))
			return false;
	if (current_node->_right)
		if (current_node->_right->_data <= current_node->_data
				|| !isBST(current_node->_right))
			return false;
	return true;
}

template<class T>
void MyBST<T>::insert(TreeNode<T> * tree_node, const T & data) {
	if (!tree_node) {
		TreeNode<T> * node = new TreeNode<T>(data);
		_root = node;
	} else {
		if (data <= tree_node->_data) {
			if (tree_node->_left)
				insert(tree_node->_left, data);
			else {
				TreeNode<T> * node = new TreeNode<T>(data);
				tree_node->_left = node;
				node->_parent = tree_node;
			}
		} else {
			if (tree_node->_right)
				insert(tree_node->_right, data);
			else {
				TreeNode<T> * node = new TreeNode<T>(data);
				tree_node->_right = node;
				node->_parent = tree_node;
			}
		}
	}
}

template<class T>
int MyBST<T>::height(TreeNode<T> * current_node) {
	if (current_node == NULL)
		return 0;
	int left_height =
			current_node->_left == NULL ? 0 : height(current_node->_left);
	int right_height =
			current_node->_right == NULL ? 0 : height(current_node->_right);
	return left_height < right_height ? right_height + 1 : left_height + 1;
}

template<class T>
TreeNode<T> * MyBST<T>::find(TreeNode<T> * tree_root, const T & data) {
	if (tree_root->_data == data)
		return tree_root;
	else if (tree_root->_right && tree_root->_data < data)
		return find(tree_root->_right, data);
	else if (tree_root->_left && tree_root->_data > data)
		return find(tree_root->_left, data);
	else
		return NULL;
}

template<class T>
void MyBST<T>::addToTree(TreeNode<T> * parent, TreeNode<T> ** root, T * array,
		int from, int to) {
	if (from > to)
		return;

	TreeNode<T> *rt = new TreeNode<T>(array[(from + to) / 2]);
	rt->_parent = parent;
	*root = rt;

	if (from < to) {
		addToTree(rt, &(rt->_left), array, from, (from + to) / 2 - 1);
		addToTree(rt, &(rt->_right), array, (from + to) / 2 + 1, to);
	}
}

#endif /* MYBST_H_ */
