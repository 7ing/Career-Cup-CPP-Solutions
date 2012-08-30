/*
 * Ex_4_8.h
 *
 *  Created on: Aug 28, 2012
 *      Author: jliu
 */

/*
 * You are given a binary tree in which each node contains a value. Design an algorithm
 * to print all paths which sum up to that value. Note that it can be any path in the tree
 * -- it does not have to start at the root.
 */

/*
 * solution assume the path does not include child->parent direction
 */

#ifndef EX_4_8_H_
#define EX_4_8_H_

#include<iostream>
#include<vector>
#include"../My Lib/MyBST.h"
using namespace std;

/*
 * O(nlogn) time, O(nlogn) space
 */
void findSum(TreeNode<int> * root, int sum, vector<int> path, int level) {
	if (!root)
		return;
	int temp = sum;
	path.push_back(root->_data);
	for (int i = level; i >= 0; i--) {
		temp -= path[i];
		if (temp == 0) { // find a path: sum = path[i] + .. + path[level]
			cout<<"path: ";
			for(int j = i; j< level; j++)
				cout<<path[j]<<" -> ";
			cout<<path[level]<<endl;
		}
	}
	findSum(root->_left, sum, path, level + 1);
	findSum(root->_right, sum, path, level + 1);
}

void test() {

	int array[7] = {4, 3, 8, 5, 2, 1, 6};
	MyBST<int> mb;
	mb.addToTree(array, 0 , 6);
	vector<int> path;
	findSum(mb.getRoot(),8, path, 0);
}

#endif /* EX_4_8_H_ */
