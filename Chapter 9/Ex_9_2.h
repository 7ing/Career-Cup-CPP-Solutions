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

// alphabetic order
bool isLarger(string a, string b) {
	unsigned int i = 0;
	unsigned int size = a.size();
	if (size > b.size())
		size = b.size();
	while (i < size) {
		if (a[i] > b[i])
			return true;
		else if (a[i] < b[i])
			return false;
		else
			i++;
	}

	if (a.size() > b.size())
		return true;
	else
		return false;
}

// using insertion sort to sort the array
void sort(string str[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (isLarger(sort_string(str[i]),sort_string(str[j])))
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
