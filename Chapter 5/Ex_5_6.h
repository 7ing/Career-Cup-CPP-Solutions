/*
 * Ex_5_6.h
 *
 *  Created on: Sep 3, 2012
 *      Author: jliu
 */

/*
 * Write a program to swap odd and even bits in an integer with as few instructions as
 * possible (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, etc).
 */

#ifndef EX_5_6_H_
#define EX_5_6_H_

#include<iostream>
#include<bitset>
using namespace std;

/*
 * Mask all odd bits with 10101010 in binary (which is 0xAA), then shift them left to put them in
 * the even bits. Then, perform a similar operation for even bits. This takes a total 5 instructions.
 */
int swapOddEvenBits(int x) {
	return ((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1);
}

void test() {
	bitset<32> x(103217);
	cout<<x.to_string()<<endl;
	bitset<32> y(swapOddEvenBits(103217));
	cout<<y.to_string()<<endl;
}


#endif /* EX_5_6_H_ */
