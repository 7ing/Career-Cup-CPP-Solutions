/*
 * Ex_1_7.h
 *
 *  Created on: Aug 4, 2012
 *      Author: MiTKooK
 */

/*
 * Write an algorithm such that if an element in an M * N matrix is 0,
 * its entire row and column is set to 0;
 */
#ifndef EX_1_7_H_
#define EX_1_7_H_

#include <iostream>
#include <cstdlib>

using namespace std;

void print_matrix(int **a, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

/*
 * O(n) time, O(1) space
 * use the first row and first col to mark "0"
 */
void zero_in_matrix_func(int **a, int row, int col) {

	if (row < 1 || col < 1)
		return;

	bool first_row = false;
	bool first_col = false;

	for (int i = 0; i < row; i++)
		if (a[i][0] == 0)
			first_col = true;

	for (int j = 0; j < col; j++)
		if (a[0][j] == 0)
			first_row = true;

	for (int i = 1; i < row; i++) {
		for (int j = 1; j < col; j++) {
			if (a[i][j] == 0) {
				a[i][0] = 0;
				a[0][j] = 0;
			}
		}
	}

	for (int i = 1; i < row; i++) {
		for (int j = 1; j < col; j++) {
			if (a[i][0] == 0 || a[0][j] == 0)
				a[i][j] = 0;
		}
	}

	if (first_col) {
		for (int i = 0; i < row; i++)
			a[i][0] = 0;
	}

	if (first_row) {
		for (int j = 0; j < col; j++)
			a[0][j] = 0;
	}

}

void test() {

	int **a;
	int M = 5, N = 10;
	a = (int **) malloc(sizeof(int *) * M);
	a[0] = (int *) malloc(sizeof(int) * M * N);
	for (int i = 1; i < M; i++)
		a[i] = a[i - 1] + N;

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			a[i][j] = rand() % N;

	print_matrix(a, M, N);

	zero_in_matrix_func(a, M, N);

	print_matrix(a, M, N);

}

#endif /* EX_1_7_H_ */
