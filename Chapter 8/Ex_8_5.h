/*
 * Ex_8_5.h
 *
 *  Created on: Sep 21, 2012
 *      Author: MiTKooK
 */

/*
 * Implement an algorithm to print all valid (e.g., properly opened and closed)
 * combinations of n-pairs of parentheses.
 * EXAMPLE:
 * input: 3 (e.g., 3 pairs of parentheses)
 * output: ()()(),()(()),(())(),(()()),((()))
 */

#ifndef EX_8_5_H_
#define EX_8_5_H_

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// recursive method
vector<string> getAllParentheses(int left, int right) {
	vector < string > result;

	if (right < left) {
		cout << "Error for pairs of parentheses" << endl;
		return result;
	}

	if (left == 0 && right == 0) { // base case
		result.push_back("");
	} else if (left == 0) { // only right parentheses are left
		string right_paren = "";
		for (int i = 0; i < right; i++)
			right_paren += ')';
		result.push_back(right_paren);
	} else { // left != 0 && right != 0
		vector < string > temp = getAllParentheses(left - 1, right);
		vector<string>::iterator it = temp.begin();
		while (it != temp.end()) {
			result.push_back('(' + (*it));
			it++;
		}
		if (right > left) { // may possible add right parentheses
			temp = getAllParentheses(left, right - 1);
			it = temp.begin();
			while (it != temp.end()) {
				result.push_back(')' + (*it));
				it++;
			}
		}
	}

	return result;
}

vector<string> getAllParentheses(int n) {
	return getAllParentheses(n, n);
}

void test() {
	vector < string > result = getAllParentheses(4);
	cout<<"Total number of pairs:"<<result.size()<<endl;
	vector<string>::iterator it = result.begin();
	while (it != result.end()) {
		cout << *it << endl;
		it++;
	}
}

#endif /* EX_8_5_H_ */
