/*
 * Ex_8_1.h
 *
 *  Created on: Sep 9, 2012
 *      Author: jliu
 */

/*
 * Write a method to generate the nth Fibonacci number
 *
 * ref: http://www.ics.uci.edu/~eppstein/161/960109.html
 */

#ifndef EX_8_1_H_
#define EX_8_1_H_

#include<iostream>
using namespace std;

// recursive method
// O(2n) time, O(n) space
int F(int n) {
	if (n < 0)
		return -1; // error index
	if (n == 0)
		return 0; // base case
	if (n == 1)
		return 1; // base case

	return F(n - 1) + F(n - 2);
}

// iterative method (DP)
// O(n) time, O(1) space
int Fi(int n) {
	if (n < 0)
		return -1; // error index
	if (n == 0)
		return 0; // special case
	int a = 1, b = 1;

	for (int i = 3; i <= n; i++) {
		int c = a + b;
		a = b;
		b = c;
	}

	return b;
}

// matrix method
// O(log n) time, O(1) space
/*
 * [ 1 1 ] n      [ F(n+1) F(n)   ]
 * [ 1 0 ]    =   [ F(n)   F(n-1) ]
 */

int Fib(int n) {
	int M[2][2] = { { 1, 1 }, { 1, 0 } };
	int temp[2][2];

	while (n > 0) {
		// M = M^2;
		temp[0][0] = M[0][0] * M[0][0] + M[0][1] * M[1][0];
		temp[0][1] = M[0][0] * M[0][1] + M[0][1] * M[1][1];
		temp[1][0] = M[1][0] * M[0][0] + M[1][1] * M[1][0];
		temp[1][1] = M[1][0] * M[0][1] + M[1][1] * M[1][1];
		M[0][0] = temp[0][0];
		M[0][1] = temp[0][1];
		M[1][0] = temp[1][0];
		M[1][1] = temp[1][1];

		n /= 2;

		if (n & 1) { // if n is odd
			// M = M * { { 1, 1 }, { 1, 0 } };
			temp[0][0] = M[0][0] + M[0][1];
			temp[0][1] = M[0][0];
			temp[1][0] = M[1][0] + M[1][1];
			temp[1][1] = M[1][0];
			M[0][0] = temp[0][0];
			M[0][1] = temp[0][1];
			M[1][0] = temp[1][0];
			M[1][1] = temp[1][1];
			n--;
		}

	}

	return M[0][1];
}

void test() {
	cout << F(17) << endl;
	cout << Fi(17) << endl;
	cout << Fib(17) << endl;
}

#endif /* EX_8_1_H_ */
