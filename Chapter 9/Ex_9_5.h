/*
 * Ex_9_5.h
 *
 *  Created on: Sep 29, 2012
 *      Author: MiTKooK
 */

/*
 * Given a sorted array of strings which is interspersed with empty strings, write a
 * method to find the location of a given string.
 * EXAMPLE: find "ball" in ["at","","","","ball","","","car","","","dad","",""] will return 4
 * EXAMPLE: find "ballcar" in ["at","","","","","ball","car","","","dad","",""] will return -1
 */

#ifndef EX_9_5_H_
#define EX_9_5_H_

#include <iostream>
#include <string>
using namespace std;

// binary search O(log n)
int search(string str[], string s, int start, int end) {
	while (start <= end) {
		// Ensure there is something at the end
		while (start <= end && str[end] == "") {
			--end;
		}
		if (end < start) {
			return -1; // this block was empty, so fail
		}
		int mid = (start + end) >> 1; // ( start + end ) / 2
		while (str[mid] == "") {
			++mid; // will always find one
		}
		if (str[mid] == s)
			return mid;
		if (str[mid] < s) {
			start = mid + 1;
		} else {
			end = mid - 1;
		}
	}
	return -1;
}

int find(string str[], int n, string s) {

	if (s == "") { // special case 2: empty target
		for (int i = 0; i < n; i++) {
			if (str[i] == "") {
				return i;
			}
		}
		return -1;
	}
	return search(str, s, 0, n - 1);
}

void test() {
	string str1[] = { "at", "", "", "", "ball", "", "", "car", "", "", "dad",
			"", "" };
	string str2[] = { "at", "", "", "", "", "ball", "car", "", "", "dad", "",
			"" };
	cout << find(str1, 13, "ball") << endl << find(str2, 12, "ballcar");
}

#endif /* EX_9_5_H_ */
