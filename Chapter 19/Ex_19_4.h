/*
 * Ex_19_4.h
 *
 *  Created on: Oct 16, 2012
 *      Author: MiTKooK
 */

/*
 * Write a method which finds the maximum of two numbers. You should not use if-else
 * or any other comparison operator.
 *
 * EXAMPLE:
 * Input: 5, 10
 * Output: 10
 */

#ifndef EX_19_4_H_
#define EX_19_4_H_

#include<iostream>
using namespace std;

int max(int a, int b) {
	int c = a - b;
	int k = ( c >> 31 ) & 0x1;
	return a - k * c;
}

void test() {

	int a = 5, b= 10;
	cout<<"max("<<a<<","<<b<<") = "<<max(a,b)<<endl;

}


#endif /* EX_19_4_H_ */
