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
#include<climits>
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

long long INT_minus_Bo(long long a, long long b) {
	return a + ~b + 1;
}

/*O(lg n) time.*/
int INT_divide_Bo(int dividend, int divisor) {
	if(divisor == 0) {cout<<"(ERROR: Divide by zero.) "; return 0;}
	if(dividend==INT_MAX && divisor==INT_minus_Bo(0,1)) {/*quotient overflow*/}
	int sign = ((dividend>0 && divisor>0)||(dividend<0 && divisor<0))? 1:INT_minus_Bo(0,1);
	long long a = (dividend>0)? dividend : INT_minus_Bo(0,(long long)dividend);
	long long b = (divisor>0)? divisor : INT_minus_Bo(0,(long long)divisor);
	if(a<b) return 0;
	long long origB = b;
	long long q = 1;
	long long preB = b;
	long long preQ = q;
	while(INT_minus_Bo(a, b) > 0) {
		preB = b;
		preQ = q;
		b += b;
		q += q;
	}
	long long restQ = INT_divide_Bo( INT_minus_Bo(a, preB), origB);
	q = preQ + restQ;
	return (sign==1)? q : INT_minus_Bo(0, q);
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

	cout<<endl<<"Test cases for INT_divide_Bo(). O(lg n) time."<<endl;
	cout<<"(-2147483648)/(-2147483647) = "<<INT_divide_Bo(-2147483648,-2147483647)<<"\t(correct)"<<endl;
	cout<<"(-2147483648)/(2147483647) = "<<INT_divide_Bo(-2147483648,2147483647)<<"\t(correct)"<<endl;
	cout<<"2147483647/2147483647 = "<<INT_divide_Bo(2147483647,2147483647)<<"\t(correct)"<<endl;
	cout<<"(-2147483648)/(-1) = INT_MAX+1\t(overflow to "<<INT_divide_Bo(-2147483648,-1)<<")"<<endl;
	cout<<"(-2147483648)/2 = "<<INT_divide_Bo(-2147483648,2)<<"\t(correct)"<<endl;
	cout<<"(-2147483648)/(-3) = "<<INT_divide_Bo(-2147483648,-3)<<"\t(correct)"<<endl;
	cout<<"(-2147483647)/(-214748364) = "<<INT_divide_Bo(-2147483647,-214748364)<<"\t(correct)"<<endl;
	cout<<"(-2147483648)/1 = "<<INT_divide_Bo(-2147483648,1)<<"\t(correct)"<<endl;
	cout<<"2147483647/2 = "<<INT_divide_Bo(2147483647,2)<<"\t(correct)"<<endl;
	cout<<"(2147483647)/(-2147483648) = "<<INT_divide_Bo(2147483647,-2147483648)<<"\t(correct)"<<endl;
	cout<<"(-2147483648)/(-2147483648) = "<<INT_divide_Bo(-2147483648,-2147483648)<<"\t(correct)"<<endl;
	cout<<"0/(-2147483648) = "<<INT_divide_Bo(0,-2147483648)<<"\t\t(correct)"<<endl;

	cout<<endl<<"12 more test cases for INT_divide(). O(n) time."<<endl;
	cout<<"(-2147483648)/(-2147483647) = "<<INT_divide(-2147483648,-2147483647)<<"\t(should be 1)"<<endl;
	cout<<"(-2147483648)/(2147483647) = "<<INT_divide(-2147483648,2147483647)<<"\t(should be -1)"<<endl;
	cout<<"2147483647/2147483647 = "<<INT_divide(2147483647,2147483647)<<"\t(correct)"<<endl;
	cout<<"(-2147483648)/(-1) = "<<INT_divide(-2147483648,-1)<<"\t\t(overflow)"<<endl;
	cout<<"(-2147483648)/2 = "<<INT_divide(-2147483648,2)<<"\t\t(should be -1073741824)"<<endl;
	cout<<"(-2147483648)/(-3) = "<<INT_divide(-2147483648,-3)<<"\t\t(should be 715827882)"<<endl;
	cout<<"(-2147483647)/(-214748364) = "<<INT_divide(-2147483647,-214748364)<<"\t(correct)"<<endl;
	cout<<"(-2147483648)/1 = "<<INT_divide(-2147483648,1)<<"\t\t(should be -2147483648)"<<endl;
	cout<<endl<<"Calculating 2147483647/2, please wait."<<endl;
	cout<<"2147483647/2 = "<<INT_divide(2147483647,2)<<"\t(correct)"<<endl;
	cout<<endl<<"The following 3 test cases may encounter dead loops:"<<endl;
	cout<<"(2147483647)/(-2147483648)\n(-2147483648)/(-2147483648)\n0/(-2147483648)"<<endl;
	cout<<"(2147483647)/(-2147483648) = "<<INT_divide(2147483647,-2147483648)<<endl;
	cout<<"(-2147483648)/(-2147483648) = "<<INT_divide(-2147483648,-2147483648)<<endl;
	cout<<"0/(-2147483648) = "<<INT_divide(0,-2147483648)<<endl;
}

#endif /* EX_10_4_H_ */
