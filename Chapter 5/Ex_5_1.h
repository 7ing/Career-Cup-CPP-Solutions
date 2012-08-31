/*
 * Ex_5_1.h
 *
 *  Created on: Aug 30, 2012
 *      Author: jliu
 */

/*
 * You are given two 32-bit numbers, N and M, and two bit positions, i and j.
 * Write a method to set all bits between i and j in N equal to M (e.g., M becomes
 * a substring of N located at i and starting at j).
 * EXAMPLE:
 * Input: N = 10000000000, M = 10101, i=2,j=6
 * Output:N = 10001010100
 */

#ifndef EX_5_1_H_
#define EX_5_1_H_

#include<iostream>
#include<bitset>
using namespace std;

void setBits(int & N, int M, int i, int j) {
	// produce mask number
	int mask = 0;
	for(;j>=i;j--)
		mask = (mask<<1) | 1;
	M = M & mask; // remove sign bit
	mask = ~(mask<<i);
	M = M<<i;
	N = (N & mask) | M;
}

void test() {

	int N = 1 << 10; // N = 10000000000
	bitset<32> N_bit(N);
	cout<<"N: "<<N_bit.to_string()<<endl;

	int M = 1 | 4 | 16; // M = 10101
	bitset<32> M_bit(M);
	cout<<"M: "<<M_bit.to_string()<<endl;

	int i = 2, j = 6;
	setBits(N, M, i, j);
	cout<<"set bits of N from i: "<<i<<" to j: "<<j<<" : "<<endl;
	bitset<32> result(N);
	cout<<"N: "<<result.to_string()<<endl;


}

#endif /* EX_5_1_H_ */
