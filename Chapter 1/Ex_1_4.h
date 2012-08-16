/*
 * Ex_1_4.h
 *
 *  Created on: Aug 3, 2012
 *      Author: MiTKooK
 */

/*
 * Write a method to decide if two strings are anagrams or not.
 */

#ifndef EX_1_4_H_
#define EX_1_4_H_

#include <iostream>
#include <cstring>
using namespace std;

char result[2][6] = { "False", "True" };

/*
 * using additional space: O(n) time, O(1) space
 */
bool is_anagrams_func(char * str1, char * str2) {

	if (!str1 || !str2)
		return false;
	if (strlen(str1) != strlen(str2))
		return false;

	int ascii[256] = { 0 };

	for (int i = 0; str1[i] != '\0'; i++) {
		ascii[(int) str1[i]]++;
		ascii[(int) str2[i]]--;
	}

	for (int i = 0; i<256; i++) {
		if (ascii[i]!=0) return false;
	}
	return true;
}

void test() {
	char str[] = { "abcda" };
	char str1[] = { "adcba" };
	char str2[] = { "dcbea" };
	char str3[] = { "dcaaa" };

	cout << str << " vs. " << str1 << " : " << result[is_anagrams_func(str,
			str1)] << endl;
	cout << str << " vs. " << str2 << " : " << result[is_anagrams_func(str,
			str2)] << endl;
	cout << str << " vs. " << str3 << " : " << result[is_anagrams_func(str,
			str3)] << endl;
}

#endif /* EX_1_4_H_ */
