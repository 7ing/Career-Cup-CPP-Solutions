/*
 * Ex_10_7.h
 *
 *  Created on: Oct 15, 2012
 *      Author: MiTKooK
 */

/*
 * Design an algorithm to find the kth number such that the only prime factors are 3, 5, and 7.
 *
 * e.g., numbers are: 3, 5, 7, 9, 15 ...
 */

#ifndef EX_10_7_H_
#define EX_10_7_H_

#include<iostream>
#include<queue>
using namespace std;

#define min(x,y) (x<y?x:y)

int getKthNumber(int k) {
	if (k <= 0)
		return 0;
	int val = 1;
	queue<int> Q3, Q5, Q7;
	Q3.push(3);
	Q5.push(5);
	Q7.push(7);
	while(k-- > 0) { // 1st one should be 3
		val = min(Q3.front(), min(Q5.front(),Q7.front()));
		if (val == Q7.front()) {
			Q7.pop();
		} else {
			if (val == Q5.front()) {
				Q5.pop();
			} else { // must be from Q3
				Q3.pop();
				Q3.push(val * 3);
			}
			Q5.push(val * 5);
		}
		Q7.push(val * 7);
	}
	return val;
}

void test() {
	for (int i = 1; i < 14; i++) {
		cout << i << " : " << getKthNumber(i) << endl;
	}
}

#endif /* EX_10_7_H_ */
