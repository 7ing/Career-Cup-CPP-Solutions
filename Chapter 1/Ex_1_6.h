/*
 * Ex_1_6.h
 *
 *  Created on: Aug 3, 2012
 *      Author: MiTKooK
 */

/*
 * Given an image represented by an N x N matrix, where each pixel in the image is 4 bytes,
 * write a method to rotate the image by 90 degrees. Can you do this in place?
 */

#ifndef EX_1_6_H_
#define EX_1_6_H_

#include <iostream>
using namespace std;

/*
 * O(N^2) time, O(1) space
 */
void img_r_rotate_func(int *a, int N) {

	if (N < 2)
		return;

	// a[i][j] -> a[j][N-i-1]
	for (int i = 0; i < N / 2; i++) {
		for (int j = i; j < N - i - 1; j++) {
			int temp = *(a + i * N + j); // save top
			*(a + i * N + j) = *(a + (N - j - 1) * N + i); // left -> top
			*(a + (N - j - 1) * N + i) = *(a + (N - i) * N - j - 1); // bottom -> left
			*(a + (N - i) * N - j - 1) = *(a + j * N + N - i - 1);// right -> bottom
			*(a + j * N + N - i - 1) = temp; // top -> right
		}
	}

}

void test() {

	int a[][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	img_r_rotate_func((int *) a, 3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}

}

#endif /* EX_1_6_H_ */
