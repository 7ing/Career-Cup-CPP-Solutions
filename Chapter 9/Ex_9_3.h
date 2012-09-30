/*
 * Ex_9_3.h
 *
 *  Created on: Sep 29, 2012
 *      Author: MiTKooK
 */

/*
 * Given a sorted array of n integers that has been rotated an unknown number of
 * times, give an O(log n) algorithm that finds an element in the array. You may
 * assume that the array was originally sorted in increasing order.
 * EXAMPLE:
 * Input: find 5 in array (15 16 19 20 25 1 3 4 5 7 10 14)
 * Output: 8 (the index of 5 in the array)
 */

#ifndef EX_9_3_H_
#define EX_9_3_H_

#include<iostream>
using namespace std;

// using quick sort - partition idea
int find(int a[], int start, int end, int num) {
	int mid;
	while (start <= end) {
		mid = (start + end) / 2;
		if (a[mid] == num) {
			return mid;
		} else if (a[start] <= a[mid]) {
			if (num < a[mid] && num >= a[start])
				end = mid - 1;
			else
				start = mid + 1;
		} else if (num > a[mid] && num <= a[end]) {
			start = mid + 1;
		} else
			end = mid - 1;
	}
	return -1;
}

void test() {
	int a[] = { 15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14 };
	cout << "find 5 in array: " << find(a, 0, 11, 5) << endl;
}

#endif /* EX_9_3_H_ */
