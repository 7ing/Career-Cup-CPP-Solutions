/*
 * Ex_5_5.h
 *
 *  Created on: Sep 3, 2012
 *      Author: jliu
 */

/*
 * Write a function to determine the number of bits required to convert integer A to integer B.
 * Input: 31, 14
 * Output: 2
 */

#ifndef EX_5_5_H_
#define EX_5_5_H_

#include<iostream>
using namespace std;

int bitsDistance(int a, int b) {
	int num = a ^ b; // cancel all identical bits
	int result = 0;
	while(num != 0) {
		if(num & 1)
			result++;
		num >>= 1;
	}
	return result;
}

void test() {

	int a = 31, b = 14;
	cout<<"Input: "<<a<<", "<<b<<endl;
	cout<<"Output:"<<bitsDistance(a,b);

}


#endif /* EX_5_5_H_ */
