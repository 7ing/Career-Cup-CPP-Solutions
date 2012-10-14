/*
 * Ex_10_5.h
 *
 *  Created on: Oct 13, 2012
 *      Author: MiTKooK
 */

/*
 * Given two squares on a two dimensional plane, find a line that would cut these two squares in half.
 */

#ifndef EX_10_5_H_
#define EX_10_5_H_

#include <iostream>
using namespace std;

struct Point {
	Point(double x, double y) :
		x_(x), y_(y) {
	}
	double x_, y_;
};

struct Square {
	Square(Point ul, Point br) :
		upper_left(ul), bottom_right(br) {
	}
	Point upper_left, bottom_right;
};

/*
 * Idea:
 * Any line that goes through the center of a rectangle must cut it in half. Therefore,
 * if you drew a line connecting the centers of the two squares, it would cut both in half.
 */

void cut_half(Square s1, Square s2) {
	double s1_mid_x = (s1.upper_left.x_ + s1.bottom_right.x_) / 2;
	double s1_mid_y = (s1.upper_left.y_ + s1.bottom_right.y_) / 2;
	double s2_mid_x = (s2.upper_left.x_ + s2.bottom_right.x_) / 2;
	double s2_mid_y = (s2.upper_left.y_ + s2.bottom_right.y_) / 2;
	cout << "A cutting line is from point (";
	if (s1_mid_x == s2_mid_x && s1_mid_y == s2_mid_y) {
		cout << s1.upper_left.x_ << "," << s1.upper_left.y_ << ")";
		cout << " to point " << s1.bottom_right.x_ << "," << s1.bottom_right.y_
				<< ")" << endl;
	} else {
		cout << s1_mid_x << "," << s1_mid_y << ")";
		cout << " to point " << s2_mid_x << "," << s2_mid_y << ")" << endl;
	}
}

void test() {
	Square s1(Point(0,0),Point(1,1));
	Square s2(Point(1,1),Point(2,2));
	cut_half(s1,s2);
}

#endif /* EX_10_5_H_ */
