/*
 * Ex_1_3.h
 *
 *  Created on: Aug 2, 2012
 *      Author: MiTKooK
 */

/*
 * Design an algorithm and write code to remove the duplicate characters in a string
 * without using any additional buffer. NOTE: One or two additional variables are fine.
 * An extra copy of the array is not.
 * FOLLOW UP
 * Write the test cases for this method.
 */
#ifndef EX_1_3_H_
#define EX_1_3_H_

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

/*
 * Without additional space: O(n^2) time, O(1) space
 */
void rm_duplicate_char_func(char * str) {

	if (!str)
		return;
	if (strlen(str) < 2)
		return;
	int j, end = 1;

	for (int i = 1; str[i] != '\0'; i++) {

		for (j = 0; j < end; j++)
			if (str[i] == str[j])
				break;
		if (j == end)
			str[end++] = str[i];
	}
	str[end] = '\0';

}

/*
 * With additional space: O(n) time, O(1) space
 */
void rm_duplicate_char_as_func(char * str) {

	if(!str) return;

	bool ascii[256] = {false};

	int end = 0;

	for (int i = 0; str[i]!='\0'; i++) {
		if(ascii[(int)str[i]])
			continue;
		else {
			ascii[(int)str[i]] = true;
			str[end++] = str[i];
		}
	}

	str[end]='\0';

}

void test() {
	char str[] = { "@abcd@efgh@" };
	char str1[] = {""};
	char str2[] = {"00"};
	char str3[] = {"1aa11a"};
	char str4[1];
	rm_duplicate_char_as_func(str);
	rm_duplicate_char_as_func(str1);
	rm_duplicate_char_as_func(str2);
	rm_duplicate_char_as_func(str3);
	rm_duplicate_char_as_func(str4);
	cout << "@abcd@efgh@" << " --> " << str << endl;
	cout << "" << " --> " << str1 << endl;
	cout << "00" << " --> " << str2 << endl;
	cout << "1aa11a" << " --> " << str3 << endl;
	cout << "NULL" << " --> " << str4 << endl;
}

#endif /* EX_1_3_H_ */
