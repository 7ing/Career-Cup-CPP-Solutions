/*
 * Ex_10_4.h
 *
 *  Created on: Oct 12, 2012
 *      Author: MiTKooK
 */

/*
 * Write a method to implement *,-,/ operations. You should use only the + operator.
 */

#ifndef EX_10_4_H_
#define EX_10_4_H_

#include<iostream>
using namespace std;

// Absolute value
int abs(int a) {
	return a < 0 ? (~a + 1) : a;
}

// Subtract
int INT_minus(int a, int b) {
	return a + ~b + 1;
}

// Multiply a by b by adding a to itself b times
int INT_multiply(int a, int b) {
	if (a < b)
		return INT_multiply(b, a); // faster if b < a
	int sum = 0;
	for (int i = abs(b); i > 0; --i)
		sum += a;
	if (b < 0)
		sum = ~sum + 1;
	return sum;
}

/* Divide a by b by literally counting how many times does b go into
 * a. That is, count how many times you can subtract b from a until
 * you hit 0. */
int INT_divide(int a, int b) {
	if (b == 0) {
		cerr << "ERROR: Divide by zero." << endl;
		return 0;
	}
	int quotient = 0;
	int divisor = b < 0 ? b : (~b + 1);
	int divend; /* dividend */
	for (divend = abs(a); divend >= abs(divisor); divend += divisor)
		++quotient;

	if ((a < 0 && b > 0) || (a > 0 && b < 0))
		quotient = ~quotient + 1;
	return quotient;
}

void test() {
	cout<<INT_minus(10,5)<<endl;
	cout<<INT_minus(10,-5)<<endl;
	cout<<INT_minus(10,0)<<endl;
	cout<<INT_multiply(10,5)<<endl;
	cout<<INT_multiply(10,-5)<<endl;
	cout<<INT_multiply(10,0)<<endl;
	cout<<INT_divide(10,5)<<endl;
	cout<<INT_divide(10,-5)<<endl;
	cout<<INT_divide(10,0)<<endl;
}

#endif /* EX_10_4_H_ */
