/*
 * Ex_12_4.h
 *
 *  Created on: Oct 3, 2012
 *      Author: MiTKooK
 */

/*
 * You have an array with all the numbers from 1 to N, where N is at most 32,000.
 * The array may have duplicate entries and you do not know what N is. With only
 * 4KB of memory available, how would you print all duplicate elements in the array?
 */

#ifndef EX_12_4_H_
#define EX_12_4_H_

#include<iostream>
#include<cstdlib>
using namespace std;

// use bitmap idea
void printDuplicate(int a[], int N) {
	int * bitmap = new int[1000]; // 32000/32
	for (int i = 0; i < 1000; i++)
		bitmap[i] = 0;
	int block, offset;
	for (int i = 0; i < N; i++) {
		block = (a[i] - 1) >> 5; // divide 32
		offset = (a[i] - 1) & 0x1F; // mod 32
		if (bitmap[block] & (1 << offset))
			cout << a[i] << endl;
		else
			bitmap[block] |= 1 << offset;
	}
}

void test() {

	const int N = 1000;
	int a[N];
	cout << "array size " << N <<": ";
	for (int i = 0; i < N; i++) {
		a[i] = rand() % 32000 + 1;
		//cout << a[i] << " ";
	}
	cout << endl << "duplicate: " << endl;
	printDuplicate(a, N);

}

#endif /* EX_12_4_H_ */
