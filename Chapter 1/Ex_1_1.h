/*
 * Ex_1_1.h
 *
 *  Created on: Aug 1, 2012
 *      Author: MiTKooK
 */

/*
 * Chapter 1 Arrays and Strings
 * 1.1 Implement an algorithm to determine if a string has all unique characters.
 * What if you can not use additional data structures?
 */

#ifndef EX_1_1_H_
#define EX_1_1_H_

#include <cstring>
#include <iostream>
#include <cstdlib>

using namespace std;

int partition_func(char * string, int left, int right, bool &flag);
void quick_sort_func(char * string, int left, int right, bool &flag);

/*
 * 1st method, using quick sort scheme, O(nlogn)time, O(n)space
 * can use for every chars
 */
bool is_unique_char_func_1(char * string) {

	bool result = true;
	char * temp = new char[strlen(string) + 1]; // + 1 is to avoid heap overflow
	strcpy(temp, string);
	if (!temp) {
		cerr << "Not Enough Memory\n";
		exit(1);
	}

	quick_sort_func(temp, 0, strlen(string) - 1, result);
	delete temp;
	return result;
}

/*
 * 2nd method, using bit shifting scheme, O(n)time, O(1)space
 * only for limited chars such as [0-9a-zA-Z]
 */
bool is_unique_char_func_2(char * string) {

	int check = 0;
	int i = 0;
	while (string[i] != '\0') {
		int pos = (int) string[i] - 'a';
		if ((check & (1 << pos)) > 0)
			return false;
		check |= 1 << pos;
		i++;
	}
	return true;
}

/*
 * 3rd method, using array, O(n) time, O(1) space
 * only for ASCII chars
 */
bool is_unique_char_func_3(char * string) {
	bool ascii[256] = {false};
	int i = 0;
	while (string[i]!='\0') {
		if(!ascii[(int)string[i]])
			ascii[(int)string[i]] = true;
		else
			return false;
		i++;
	}
	return true;
}

void test() {
	char str0[] =
			"0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char str1[] = "&^%^%$)@!";
	char str2[] = "9876543210ab";
	char * str[] = { str0, str1, str2 };
	for (int i = 0; i < 3; i++) {
		cout << str[i] << ": " << is_unique_char_func_1(str[i]);
		cout << ", " << is_unique_char_func_2(str[i]);
		cout << ", " << is_unique_char_func_3(str[i]) << endl;
	}

}

int partition_func(char * string, int left, int right, bool &flag) {
	int pt = left;
	char temp;
	for (int i = left; i <= right - 1; i++) {
		if (string[right] == string[i]) {
			flag = false;
			break;
		} else if (string[right] > string[i]) {
			temp = string[i];
			string[i] = string[pt];
			string[pt++] = temp;
		}
	}
	temp = string[pt];
	string[pt] = string[right];
	string[right] = temp;
	return pt;
}

void quick_sort_func(char * string, int left, int right, bool &flag) {
	if (left < right) {
		int i = partition_func(string, left, right, flag);
		if (flag) {
			quick_sort_func(string, left, i - 1, flag);
			quick_sort_func(string, i + 1, right, flag);
		}
	}
}

#endif /* EX_1_1_H_ */
