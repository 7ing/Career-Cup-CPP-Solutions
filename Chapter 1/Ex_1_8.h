/*
 * Ex_1_8.h
 *
 *  Created on: Aug 4, 2012
 *      Author: MiTKooK
 */

/*
 * Assume you have a method isSubstring which checks if one word is a substring of another.
 * Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using
 * only one call to isSubstring (i.e., "waterbottle" is a rotation of "erbottlewat")
 */
#ifndef EX_1_8_H_
#define EX_1_8_H_

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

char result[2][6] = { "False", "True" };
/*
 * O(n^2) time, O(1) space
 * this is a brute force method for strstr()
 */
bool isSubstring(const char *s1, const char *s2) {

	if (!s1 || !s2)
		return false;

	int j, p;
	for (int i = 0; s1[i] != '\0'; i++) {
		if (s1[i] == s2[0]) {
			p = i + 1;
			j = 1;
			while (s1[p] != '\0' && s2[j] != '\0') {
				if (s1[p] == s2[j]) {
					p++;
					j++;
				} else
					break;
			}
			if (s2[j] == '\0') {
				return true;
			}
		}
	}

	return false;
}

/*
 * Method 1: O(n^2) time, O(1) space
 */
bool is_rotation_func(const char *s1, const char *s2) {

	int l = strlen(s1);

	if (l - strlen(s2))
		return false;

	int i, p1, p2;

	for (i = 0; s2[i] != '\0'; i++) {

		if (s2[i] == s1[0]) {
			p2 = i;
			p1 = l - i;
			while (s1[p1] != '\0' && p2 > 0) {
				if (s1[p1] == s2[i - p2]) {
					p1++;
					p2--;
				} else
					break;
			}
			if (p2 == 0)
				break;
		}
	}

	if (i == l)
		return false;

	return isSubstring(s1, s2 + i);
}

/*
 * Method 2: using string.h functions: O(n^2) time, O(n) space
 */
bool is_rotation_2_func(const char* s1, const char* s2) {
	int l = strlen(s1);

	if (l - strlen(s2))
		return false;

	char *temp = (char *) malloc(l * sizeof(char) * 2);
	strcpy(temp, s1);
	strcat(temp, s1);
	char *result = strstr(temp, s2);  // strstr == isSubstring
	free(temp);
	return (result == NULL) ? false : true;
}

#include <iostream>
using namespace std;

void test() {
	char s1[] = { "waterbottle" };
	char s2[] = { "erbottlewat" };
	char s3[] = { "erbotteewat" };

	cout << s1 << " vs. " << s2 << " : ";
	cout << result[is_rotation_2_func(s1, s2)] << endl;
	cout << s1 << " vs. " << s3 << " : ";
	cout << result[is_rotation_2_func(s1, s3)] << endl;

}

#endif /* EX_1_8_H_ */
