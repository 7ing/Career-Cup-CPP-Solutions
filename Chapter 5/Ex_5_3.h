/*
 * Ex_5_3.h
 *
 *  Created on: Sep 2, 2012
 *      Author: jliu
 */

/*
 * Given an integer, print the next smallest and next largest number that have the same
 * number of 1 bits in their binary representation.
 */

#ifndef EX_5_3_H_
#define EX_5_3_H_

#include<iostream>
#include<bitset>
using namespace std;

bool getBit(int num, int pos) {
	return (num & (1 << pos)) > 0;
}

int setBit(int num, int pos, bool value) {
	if (value) {
		return num | (1 << pos); // set 1
	} else {
		return num & ~(1 << pos); // set 0
	}
}

/*
 * Note: only work for positive number
 *
 * 1.	 Traverse from right to left. Once we’ve passed a 1, turn on the next 0. We’ve now increased
 *       the number by 2^i. Yikes! Example: xxxxx011100 becomes xxxxx111100
 * 2.	 Set all the one to zero that’s to the right side of that. Remember the number of 1s to be turned.
 * 		 Example: xxxxx111100 becomes xxxxx100000 turned# = 3.
 * 3.	 Make the lowest turned#-1 position to be 1:
 * 		 Example: xxxxx100000 becomes xxxxx100011
 */
int getNext(int num) {
	if (num <= 0)
		return -1;

	int index = 0;
	int countOnes = 0;

	// Find first one.
	while (!getBit(num, index))
		index++;

	// Turn on next zero.
	while (getBit(num, index)) {
		index++;
		countOnes++;
	}
	num = setBit(num, index, true);

	countOnes--;

	// Set zeros
	for (int i = index - 1; i >= countOnes; i--) {
		num = setBit(num, i, false);
	}

	// Set ones
	for (int i = countOnes - 1; i >= 0; i--) {
		num = setBit(num, i, true);
	}

	return num;
}

/*
 * Note: only work for positive number
 *
 * 1.	 Traverse from right to left. Once we’ve passed a zero, turn off the next 1.
 * 		 Example: xxxxx100011 becomes xxxxx000011.
 * 2.	 Turn on the 0 that is directly to the right.
 * 		 Example: xxxxx000011 becomes xxxxx010011.
 * 3.	 Make the number as big as possible by shifting all the ones as far to the left as possible.
 * 		 Example: xxxxx010011 becomes xxxxx011100 .
 */
int getPrevious(int num) {
	if (num <= 0)
		return -1;

	int index = 0;
	int countZeros = 0;

	// Find first zero.
	while (getBit(num, index))
		index++;

	// Turn off next 1.
	while (!getBit(num, index)) {
		index++;
		countZeros++;
	}
	num = setBit(num, index, false);

	// Turn on previous zero
	index--;
	num = setBit(num, index, true);
	countZeros--;

	// Set ones
	for (int i = index - 1; i >= countZeros; i--) {
		num = setBit(num, i, true);
	}

	// Set zeros
	for (int i = countZeros - 1; i >= 0; i--) {
		num = setBit(num, i, false);
	}

	return num;
}

void test() {
	int a = 27;
	bitset<32> aa(a);
	cout << "Value:\t\t" << a << "\t" << aa.to_string() << endl;
	int b = getNext(a);
	bitset<32> bb(b);
	cout << "Next:\t\t" << b << "\t" << bb.to_string() << endl;
	int c = getPrevious(a);
	bitset<32> cc(c);
	cout << "Previous:\t" << c << "\t" << cc.to_string() << endl;
}

#endif /* EX_5_3_H_ */
