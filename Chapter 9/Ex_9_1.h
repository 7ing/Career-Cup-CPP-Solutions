/*
 * Ex_9_1.h
 *
 *  Created on: Sep 29, 2012
 *      Author: MiTKooK
 */

/*
 * You are given two sorted arrays, A and B, and A has a large enough buffer at the end
 * to hold B. Write a method to merge B into A in sorted order.
 */

#ifndef EX_9_1_H_
#define EX_9_1_H_

#include<iostream>
#include<vector>

using namespace std;

// A, B are sorted arrays
// merge sort O(nlogn)
void merge(vector<int> & A, vector<int> & B) {
	int pa = A.size() - 1;
	int pb = B.size() - 1;
	int size = B.size();
	while (size-- != 0) // padding to A
		A.push_back(-1);

	int p = A.size() - 1;

	while (pa >= 0 && pb >= 0) {
		if (A[pa] > B[pb])
			A[p--] = A[pa--];
		else
			A[p--] = B[pb--];
	}

	// if pa >= 0, no need to sort the rest sorted elements in A

	if (pb >= 0)
		A[p--] = B[pb--];
}

void test() {
	vector<int> A, B;
	cout << "A: ";
	for (int i = 0; i < 10; i += 2) {
		A.push_back(i);
		cout << i << " ";
	}
	cout << "\nB: ";
	for (int i = 1; i < 10; i += 2) {
		B.push_back(i);
		cout << i << " ";
	}
	cout << "\nAfter merge: ";
	merge(A, B);
	int size = A.size();
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
}

#endif /* EX_9_1_H_ */
