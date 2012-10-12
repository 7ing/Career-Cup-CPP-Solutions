/*
 * Ex_10_3.h
 *
 *  Created on: Oct 12, 2012
 *      Author: MiTKooK
 */

/*
 * Given two lines on a Cartesian plane, determine whether the two lines would intersect.
 *
 * PS: it is way too easy to solve this problem. Change the lines into "line segments" for this problem.
 * REF: CLRS Chap 33.1 | using cross product
 */

#ifndef EX_10_3_H_
#define EX_10_3_H_

#include<iostream>
using namespace std;

#define min(x,y) (x>y?y:x)
#define max(x,y) (x>y?x:y)

struct Point {
	Point(double x, double y) :
		x_(x), y_(y) {
	}
	double x_, y_;
};

/*
 * check pk on which side of segement (pi, pj)
 */
double direction(Point pi, Point pj, Point pk) {
	// return cross product of (pk - pi) and (pj - pi)
	return (pk.x_ - pi.x_) * (pj.y_ - pi.y_) - (pj.x_ - pi.x_)
			* (pk.y_ - pi.y_);
}

/*
 * ON-SEGMENT(pi, pj, pk)
 * 1  if min(xi, xj) ¡Ü xk ¡Ü max(xi, xj) and min(yi, yj) ¡Ü yk ¡Ü max(yi, yj)
 * 2     then return TRUE
 * 3     else return FALSE
 */
bool onSegment(Point pi, Point pj, Point pk) {
	if (min(pi.x_,pj.x_) <= pk.x_ && pk.x_ <= max(pi.x_,pj.x_)
			&& min(pi.y_,pj.y_) <= pk.y_ && pk.y_ <= max(pi.y_,pj.y_))
		return true;
	else
		return false;
}

bool isIntersect(Point p1, Point p2, Point p3, Point p4) {

	double d1 = direction(p3, p4, p1);
	double d2 = direction(p3, p4, p2);
	double d3 = direction(p1, p2, p3);
	double d4 = direction(p1, p2, p4);

	if (d1 * d2 < 0 && d3 * d4 < 0)
		return true;
	else if (d1 == 0 && onSegment(p3, p4, p1))
		return true;
	else if (d2 == 0 && onSegment(p3, p4, p2))
		return true;
	else if (d3 == 0 && onSegment(p1, p2, p3))
		return true;
	else if (d4 == 0 && onSegment(p1, p2, p4))
		return true;
	else
		return false;
}

void test() {
	Point a(0, 0), b(1, 0), c(1, 0), d(1, -1);
	cout << isIntersect(a, b, c, d)<<endl;
	Point aa(0, 0), bb(1, 0), cc(2, 0), dd(1, -1);
	cout << isIntersect(aa, bb, cc, dd);
}

#endif /* EX_10_3_H_ */
