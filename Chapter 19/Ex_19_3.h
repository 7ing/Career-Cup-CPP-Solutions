/*
 * Ex_19_3.h
 *
 *  Created on: Oct 16, 2012
 *      Author: MiTKooK
 */

/*
 * Write an algorithm which computes the number of trailing zeros in n factorial.
 *
 * aka., count how many 0 in n!
 */

#ifndef EX_19_3_H_
#define EX_19_3_H_

#include<iostream>
using namespace std;

// counting # of 5, since # of 2 always >= # of 5.
// O(n)
int numOfZeros(int n) {
	int num = 0;
	if (n >= 5)
		for (int i = 5; n >= i; i *= 5)
			num += n / i;
	return num;
}

long int factorial(int n) {
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	else
		return n * factorial(n - 1);
}

void test() {

	for (int i = 1; i < 12; i++)
		cout << i << "! (" << factorial(i) << ") has " << numOfZeros(i)
				<< " zeros " << endl;

}
#endif /* EX_19_3_H_ */
