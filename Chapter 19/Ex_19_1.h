/*
 * Ex_19_1.h
 *
 *  Created on: Oct 16, 2012
 *      Author: MiTKooK
 */

/*
 * Write a function to swap a number in place without temporary variables.
 */

#ifndef EX_19_1_H_
#define EX_19_1_H_
#include<iostream>
using namespace std;

template<class T>
void swapT(T & a, T & b) {
	a = a + b;
	b = a - b;
	a = a - b;
}

void swapInt(int & a, int & b) {
	a ^= b ^= a ^= b;
}

void test() {
	int a = 5, b = 0;
	cout<<a<<" "<<b<<endl;
	swapT(a, b);
	cout<<a<<" "<<b<<endl;
	swapInt(a, b);
	cout<<a<<" "<<b<<endl;

}


#endif /* EX_19_1_H_ */
