/*
 * Ex_1_5.h
 *
 *  Created on: Aug 3, 2012
 *      Author: MiTKooK
 */

/*
 * Write a method to replace all spaces in a string with '%20'.
 * [Amazon Question]
 */
#ifndef EX_1_5_H_
#define EX_1_5_H_

#include <iostream>
using namespace std;

/*
 * O(n) time, O(1) space
 * this method may cause heap overflow!
 * to address this issue, simply allocates new memory to the string
 */
void space_to_unicode_func(char * str) {

	if (!str)
		return;
	int length = 0, space = 0;
	while (str[length] != '\0') {
		if (str[length] == ' ')
			space++;
		length++;
	}
	int new_length = length + 2 * space;
	length--;
	str[new_length--] = '\0';
	while (new_length > 0) {
		if(str[length]==' ') {
			str[new_length--] = '0';
			str[new_length--] = '2';
			str[new_length--] = '%';
			length--;
		} else {
			str[new_length--] = str[length--];
		}
	}

}

void test() {
	char str[] = { "Hello World  ! " };
	space_to_unicode_func(str);
	cout << "\"Hello World  ! \"" << " --> " << str << endl;

}

#endif /* EX_1_5_H_ */
