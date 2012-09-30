/*
 * Ex_9_2.h
 *
 *  Created on: Sep 29, 2012
 *      Author: MiTKooK
 */

/*
 * Write a method to sort an array of strings so that all the anagrams are next to each other.
 */

#ifndef EX_9_2_H_
#define EX_9_2_H_

#include<iostream>
#include<cstring>
#include<string>

using namespace std;

// using selection sort to sort a string
string sort_string(string str) {
	char s[str.size()];
	strcpy(s, str.data());
	for (unsigned int i = 0; i < str.size(); i++) {
		for (unsigned int j = i + 1; j < str.size(); j++) {
			if (s[i] > s[j]) {
				s[i] += s[j];
				s[j] = s[i] - s[j];
				s[i] -= s[j];
			}
		}
	}
	return string(s);
}


// using insertion sort to sort the array
void sort(string str[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (sort_string(str[i])>sort_string(str[j])) // alphabetic order
				str[i].swap(str[j]);
		}
	}
}

void test() {
	string str[10] = { "apple", "banana", "carrot", "ele", "duck", "papel",
			"tarroc", "cudk", "eel", "lee" };
	for (int i = 0; i < 10; i++)
		cout << str[i] << ", ";

	sort(str, 10);
	cout << endl;

	for (int i = 0; i < 10; i++)
		cout << str[i] << ", ";
}

#endif /* EX_9_2_H_ */
