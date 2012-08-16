/*
 * Ex_1_2.h
 *
 *  Created on: Aug 2, 2012
 *      Author: MiTKooK
 */

/*
 * Write code to reverse a C-Style String.
 * C-Style String means that "abcd" is represented as five characters, including the null character.
 */
#ifndef EX_1_2_H_
#define EX_1_2_H_

#include <iostream>
using namespace std;

/*
 * do not use "string.h", do not use strlen()
 */
void reverse_str_func(char * string) {

	char * end = string;
	char temp;
	if (string) {
		while (*end != '\0') {
			// point to the last char '\0'
			end++;
		}
		end--;
		while (string < end) {
			temp = *string;
			*string++ = *end;
			*end-- = temp;
		}
	}
}

void test() {
	char str0[] = { "abcd" };
	char str1[] = { "1234" };
	reverse_str_func(str0);
	reverse_str_func(str1);
	cout << "abcd" << " --> " << str0 << endl;
	cout << "1234" << " --> " << str1 << endl;
}
#endif /* EX_1_2_H_ */
