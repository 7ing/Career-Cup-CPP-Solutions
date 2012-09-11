/*
 * Ex_8_4.h
 *
 *  Created on: Sep 11, 2012
 *      Author: jliu
 */

/*
 * Write a method to compute all permutations of a string.
 */

#ifndef EX_8_4_H_
#define EX_8_4_H_

#include<iostream>
#include<list>
#include<string>
using namespace std;

/*
 * recursive method
 */
void getPermutations(string s, list<string> & result) {
	if (s.size() != 0) {
		char ch = s[0]; // get the first character
		// remove the first character, get the reminder permutations
		getPermutations(s.substr(1, s.size()), result);
		list<string> new_result;
		list<string>::iterator it = result.begin();
		while(it != result.end()) {
			// insert "ch" to every possible position of an existing permutation
			int size = (*it).size();
			for(int i=0;i<=size;i++) {
				string new_s = (*it).substr(0,i)+ch+(*it).substr(i,size);
				new_result.push_back(new_s);
			}
			it++;
		}
		result = new_result;
		new_result.clear();
	} else {
		result.push_back(""); // base case
	}
}

void test() {
	list<string> result;
	getPermutations("abcde", result);
	cout << "There are " << result.size() << " permutations.";
	list<string>::iterator it = result.begin();
	while (it != result.end()) {
		cout << *it << endl;
		it++;
	}
}

#endif /* EX_8_4_H_ */
