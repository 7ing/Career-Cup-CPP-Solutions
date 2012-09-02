/*
 * Ex_5_2.h
 *
 *  Created on: Aug 30, 2012
 *      Author: jliu
 */

/*
 *	Given a (decimal - e.g., 3.72) number that is passed in as a string, print the binary
 *	representation. If the number can not be represented accurately in binary, print "ERROR".
 *
 *	ref: http://en.wikipedia.org/wiki/Computer_number_format
 */

#ifndef EX_5_2_H_
#define EX_5_2_H_

#include <iostream>
#include <string>
using namespace std;

/*
 * use fix-point representation
 * 32 bits : 1 bit <sign> + 15 bits <integer bits> + 16 <fractional bits>
 */
void toFixPointBinary(char * str) {

	if (!str || *str == '\0') { // empty check
		cout << "Empty String or Pointer. " << endl;
		return;
	}
	int sign = 0;
	if (*str == '-') { // negative check
		sign = 1;
		str++;
	}

	int integerPart = 0;
	while (*str != '\0' && *str != '.') { // char to integer (atoi)
		if (*str >= '0' && *str <= '9') { // digital check
			integerPart = 10 * integerPart + static_cast<int>(*str - '0');
			str++;
		} else {
			cout << "Invalid Digit String. " << endl;
			return;
		}
	}

	str++; // pass '.'

	float fractionalPart = 0;
	if (*str != '\0') {
		while (*str != '\0') { // points to the end
			if (*str >= '0' && *str <= '9') // digital check
				str++;
			else {
				cout << "Invalid Digit String. " << endl;
				return;
			}
		}
		str--; // points to the last digit
		while (*str != '.') { // traversal back to the '.'
			fractionalPart = fractionalPart / 10 + static_cast<int>(*str - '0');
			str--;
		}
		fractionalPart /= 10;
	}

	// to binary string

	string result = "";
	while (integerPart != 0) {
		result = char((integerPart & 1) + '0') + result;
		integerPart >>= 1;
	}
	int length = result.length();

	if (length > 15) {
		cout << "ERROR" << endl;
		return;
	} else {
		while (length++ != 15) {
			result = "0" + result;
		}
	}

	result = char(sign + '0') + result + "."; // <sign> + <integer bits> + .

	while (fractionalPart != 0) {
		fractionalPart *= 2;
		result += fractionalPart >= 1 ? "1" : "0";
		if (fractionalPart >= 1)
			fractionalPart -= 1;
		if (result.length() > 33) {
			cout << "ERROR" << endl;
			return;
		}
	}
	length = result.length();
	while (length++ != 33) { // <sign> + <integer bits> + . + <fractional bits>
		result += "0";
	}

	cout << result << endl;

}

/*
 * use floating-point representation (IEEE 745)
 * <sign> × (1 . <fractional significand>) × 2 ^ (<exponent> - 127)
 * 32-bits single-precision floating-point:
 * 1 bit <sign> + 8 bits <exponent> + 23 bits <fractional significand>
 */
void toFloatingPointBinary(char * str) {
	if (!str || *str == '\0') { // empty check
		cout << "Empty String or Pointer. " << endl;
		return;
	}

	int sign = 0;
	if (*str == '-') { // negative check
		sign = 1;
		str++;
	}

	int integerPart = 0;
	while (*str != '\0' && *str != '.') { // char to integer (atoi)
		if (*str >= '0' && *str <= '9') { // digital check
			integerPart = 10 * integerPart + static_cast<int>(*str - '0');
			str++;
		} else {
			cout << "Invalid Digit String. " << endl;
			return;
		}
	}

	str++; // pass '.'

	float fractionalPart = 0;
	if (*str != '\0') {
		while (*str != '\0') { // points to the end
			if (*str >= '0' && *str <= '9') // digital check
				str++;
			else {
				cout << "Invalid Digit String. " << endl;
				return;
			}
		}
		str--; // points to the last digit
		while (*str != '.') { // traversal back to the '.'
			fractionalPart = fractionalPart / 10 + static_cast<int>(*str - '0');
			str--;
		}
		fractionalPart /= 10;
	}

	// to binary string

	string result = "";
	while (integerPart != 0) {
		result = char((integerPart & 1) + '0') + result;
		integerPart >>= 1;
	}

	int exponent = result.length();

	if (exponent > 128) { // will remove default 1 later, so 127 + 1
		cout << "ERROR" << endl;
		return;
	}

	// find the exponent value
	if (exponent > 0 && exponent <= 128) { // integer part >= 1
		exponent += 126; //  = exponent - 1 + 127
		result.erase(result.begin()); // remove the default 1
	} else { // integer part == 0, result == ""
		while (fractionalPart > 0 && fractionalPart < 1) {
			fractionalPart *= 2;
			exponent++;
		}
		if (exponent > 126) {
			cout << "ERROR" << endl;
			return;
		}
		exponent = 127 - exponent; // get the bias exponent value

		if (fractionalPart >= 1)
			fractionalPart -= 1; // remove the default 1
	}

	// add exponent part prior to the fractional part
	for (int i = 0; i < 8; i++) {
		result = char((exponent & 1) + '0') + result;
		exponent >>= 1;
	}

	result = char(sign + '0') + result; // 1 bit <sign> + 8 bits <exponent> + integer part (except the 1st bits)

	// 1 bit <sign> + 8 bits <exponent> + 23 bits <fractional significand>
	while (fractionalPart != 0) {
		fractionalPart *= 2;
		result += fractionalPart >= 1 ? "1" : "0";
		if (fractionalPart >= 1)
			fractionalPart -= 1;
		if (result.length() > 32) {
			cout << "ERROR" << endl;
			return;
		}
	}
	exponent = result.length();
	while (exponent++ != 32)
		result += "0";

	cout << result << endl;

}

void test() {

	char num[][10] = { "1.25", "-1.25", "0", "-0", "0.26", "", "OxFFFF" };

	for (int i = 0; i < 7; i++) {
		cout << num[i] << endl;
		cout << "fix-point:\t";
		toFixPointBinary(num[i]);
		cout << "floating-point:\t";
		toFloatingPointBinary(num[i]);
		cout << endl;
	}

}

#endif /* EX_5_2_H_ */
