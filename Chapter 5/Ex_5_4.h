/*
 * Ex_5_4.h
 *
 *  Created on: Sep 3, 2012
 *      Author: jliu
 */

/*
 * Explain what the following code does: ((n&(n-1))==0).
 */

#ifndef EX_5_4_H_
#define EX_5_4_H_

#include<iostream>
#include<bitset>
using namespace std;

void test() {
	cout << "Explain what the following code does: ((n&(n-1))==0)" << endl;
	int n = 4;
	bitset<8> nb(n);
	cout << "n = " << n << " : " << nb.to_string() << endl;
	int m = n - 1;
	bitset<8> mb(m);
	cout << "m = " << m << " : " << mb.to_string() << endl;
	m = n & m;
	bitset<8> mm(m);
	cout << "n&(n-1):" << mm.to_string() << endl << endl;

	n = 5;
	bitset<8> nnb(n);
	cout << "n = " << n << " : " << nnb.to_string() << endl;
	m = n - 1;
	bitset<8> mmb(m);
	cout << "m = " << m << " : " << mmb.to_string() << endl;
	m = n & m;
	bitset<8> mmm(m);
	cout << "n&(n-1):" << mmm.to_string() << endl << endl;
	cout << "Test if n is a power of 2 (or 0)";

}

#endif /* EX_5_4_H_ */
