/*
 * Ex_9_6.h
 *
 *  Created on: Sep 30, 2012
 *      Author: MiTKooK
 */

/*
 * Given a matrix in which each row and each column is sorted, write a method to
 * find an element in it.
 */

#ifndef EX_9_6_H_
#define EX_9_6_H_

#include<iostream>
using namespace std;

bool find(int **matrix, int M, int N, int num) {
	int row = 0;
	int col = N - 1;
	while (row < M && col >= 0) {
		if (matrix[row][col] == num) {
			return true;
		} else if (matrix[row][col] > num) {
			col--;
		} else {
			row++;
		}
	}
	return false;
}

void test() {
	int M = 5;
	int N = 10;
	int **matrix = new int*[M];
	matrix[0] = new int[M * N];
	for (int i = 1; i < M; i++)
		matrix[i] = matrix[i - 1] + N;
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < N; j++) {
			matrix[i - 1][j] = 10 * i + j;
			cout << matrix[i - 1][j] << " ";
		}
		cout << endl;
	}

	cout << "find 37: " << (find(matrix, M, N, 37) == false ? "False" : "True");

}

#endif /* EX_9_6_H_ */
