/*
 * Ex_16_5.h
 *
 *  Created on: Oct 6, 2012
 *      Author: MiTKooK
 */

/*
 * Write a program to find whether a machine is big endian or little andian.
 */

#ifndef EX_16_5_H_
#define EX_16_5_H_

#include<iostream>
using namespace std;

void test() {
	int a = 0x0001;
	char *b = (char *) &a;
	cout<<"This machine is ";
	cout<<(b[0]?"Little Endian":"Big Endian")<<endl;
}

#endif /* EX_16_5_H_ */
