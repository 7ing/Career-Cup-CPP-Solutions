/*
 * Ex_4_4.h
 *
 *  Created on: Aug 25, 2012
 *      Author: jliu
 */

/*
 * Given a binary search tree, design an algorithm which creates a linked list of all the
 * nodes at each depth (i.e., if you have a tree with depth D, you'll have D linked lists).
 */

#ifndef EX_4_4_H_
#define EX_4_4_H_

#include <iostream>
#include <vector>
#include <list>
#include "../My Lib/MyBST.h"
using namespace std;

/*
 * BFS method : O(n) time
 */
template<class T>
vector<list<TreeNode<T> *> > BST_levels(TreeNode<T> * root) {
	vector<list<TreeNode<T> *> > result;
	list<TreeNode<T> *> level_nodes;
	level_nodes.push_back(root);
	result.push_back(level_nodes);

	while (true) {
		level_nodes.clear();
		typename list<TreeNode<T> *>::iterator it = result.back().begin();
		while (it != result.back().end()) {
			if((*it)->_left)
				level_nodes.push_back((*it)->_left);
			if((*it)->_right)
				level_nodes.push_back((*it)->_right);
			it++;
		}
		if (!level_nodes.empty())
			result.push_back(level_nodes);
		else
			break;
	}

	return result;
}

void test() {

	MyBST<char> *tree = new MyBST<char>();
	char array[10];
	for (int i = 0; i < 10; i++)
		array[i] = char('A' + i);
	tree->addToTree(array, 0, 9);
	vector<list<TreeNode<char> *> > result = BST_levels<char>(tree->getRoot());

	// print out:
	int depth = 0;
	vector<list<TreeNode<char> *> >::iterator it_vector = result.begin();
	while(it_vector != result.end()) {
		list<TreeNode<char> *>::const_iterator it = (*it_vector).begin();
		cout<<"nodes in depth "<<depth++<<" are: ";
		while(it != (*it_vector).end()) {
			cout<<(*it)->_data<<" , ";
			it++;
		}
		cout<<endl;
		it_vector++;
	}

}

#endif /* EX_4_4_H_ */
