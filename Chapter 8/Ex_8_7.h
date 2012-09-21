/*
 * Ex_8_7.h
 *
 *  Created on: Sep 21, 2012
 *      Author: MiTKooK
 */

/*
 * Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents) and
 * pennies (1 cent), write code to calculate the number of ways of representing n cents.
 */

#ifndef EX_8_7_H_
#define EX_8_7_H_

#include<iostream>
using namespace std;

int numOfRepN(int n, int coin) {
	int nextCoin = 0;
	switch (coin) {
	case 25:
		nextCoin = 10;
		break;
	case 10:
		nextCoin = 5;
		break;
	case 5:
		nextCoin = 1;
		break;
	case 1:
		return 1;
	}
	int num = 0;
	for (int i = 0; i * coin <= n; i++) {
		num += numOfRepN(n - i * coin, nextCoin);
	}
	return num;
}

void test() {
	for (int i = 0; i < 100; i++) {
		cout << "numOfRepN(" << i << ") = " << numOfRepN(i, 25) << endl;
	}
}

#endif /* EX_8_7_H_ */
