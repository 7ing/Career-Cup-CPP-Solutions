/*
 * Ex_16.10.h
 *
 *  Created on: Oct 6, 2012
 *      Author: MiTKooK
 */

/*
 * Write a function called my2DAlloc which allocates a two dimensional array.
 * Minimize the number of calls to malloc and make sure that the memory is accessible by the notation arr[i][j].
 */

#ifndef EX_16_10_H_
#define EX_16_10_H_

#include<iostream>
#include<cstdlib>
using namespace std;

int ** my2DAlloc(int rows, int cols) {
	int **arr =
			(int **) malloc(rows * sizeof(int*) + rows * cols * sizeof(int));
	for (int i = 0; i < rows; i++)
		arr[i] = (int *)(arr + rows) + i * cols;
	return arr;
}

void test() {
	int **p = my2DAlloc(5, 6);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {
			p[i][j] = i + j;
			cout << p[i][j] << " ";
		}
		cout << endl;
	}
	free(p);
}

#endif /* EX_16_10_H_ */
