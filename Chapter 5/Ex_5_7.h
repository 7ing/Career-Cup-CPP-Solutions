/*
 * Ex_5_7.h
 *
 *  Created on: Sep 3, 2012
 *      Author: jliu
 */

/*
 * Any array A[1...n] contains all the integers from 0 to n except for one number which is
 * missing. In this problem, we cannot access an entire integer in A with a single operation.
 * The elements of A are represented in binary, and the only operation we can use to access them
 * is "fetch the jth bit of A[i]", which takes constant time. Write code to find the missing integer.
 * Can you do it in O(n) time?
 */

#ifndef EX_5_7_H_
#define EX_5_7_H_

#include<iostream>
using namespace std;

// O(1) time
bool getBit(int *array, int i, int column) {
	return (*(array + i) & (1 << column)) > 0;
}

/*
 * 1st method:
 * O(n) time, O(n) space
 * idea: in each column of remain binary numbers, holds:
 * 1) if 0 is removed, # of 1's >= # of 0's
 * 2) if 1 is removed, # of 1's < # of 0's
 * then remove all binary numbers that least significant bit is not removed bit
 */
int findMissingInt(int *array, int n, int column) {
	if (column < 0 || column > 31) { // Base case and error condition
		return 0;
	}

	int zeroNum = 0, oneNum = 0;
	int *zero = new int[n / 2 + 1];
	int *one = new int[n / 2 + 1];
	for (int i = 0; i < n; i++) {
		if (getBit(array, i, column)) {
			one[oneNum++] = *(array + i);
		} else {
			zero[zeroNum++] = *(array + i);
		}
	}
	if (oneNum >= zeroNum) {
		delete[] one;
		return (findMissingInt(zero, zeroNum, column + 1)) << 1 | 0;
	} else {
		delete[] zero;
		return (findMissingInt(one, oneNum, column + 1)) << 1 | 1;
	}
}

/*
 * 2nd Method:
 * O(n) time, O(1) space
 * idea: given the size of array, we can determine # of 1's for each bit column
 * (n / 2^(i+1))*(2^i) + (((n % 2^(i+1)) - 2^i) > 0 ? (n % 2^(i+1)) - 2^i) : 0)
 *
 */
int findMissingInteger(int * array, int n) {
	if(n<=1) // do not work for n<=1
		return -1;

	int result = 0;
	int NumOfOne = n / 2;
	int column = 0;
	while (NumOfOne > 0) {

		for (int i = 0; i < n; i++)
			if (getBit(array, i, column))
				NumOfOne--;

		if (NumOfOne > 0) // missing 1
			result |= 1 << column;

		column++;
		// get # of 1's for next column
		NumOfOne = (n % (1 << (column + 1))) - (1 << column);
		if (NumOfOne < 0)
			NumOfOne = 0;
		NumOfOne += (n / (1 << (column + 1))) * (1 << column);

	}
	return result;
}

void test() {
	int a[10] = { 0, 1, 2, 3, 4, 6, 7, 8, 9, 10 }; // missing 5
	cout << "array: 0,1,2,3,4,6,7,8,9,10" << endl;
	cout << "missing: " << findMissingInt(a, 10, 0) << endl;
	cout << "missing: " << findMissingInteger(a, 10);
}

#endif /* EX_5_7_H_ */
