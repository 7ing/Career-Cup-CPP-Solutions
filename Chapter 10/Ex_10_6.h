/*
 * Ex_10_6.h
 *
 *  Created on: Oct 14, 2012
 *      Author: MiTKooK
 */

/*
 * Given a two dimensional graph with points on it, find a line which passes the most number points.
 */

#ifndef EX_10_6_H_
#define EX_10_6_H_

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<tr1/unordered_map>
using namespace std;

#define ABS(x) (x<0?-x:x)
#define EPSILON 0.0001

struct Point {
	Point() {
		x_ = 0;
		y_ = 0;
	}
	Point(double x, double y) :
		x_(x), y_(y) {
	}
	double x_, y_;
};

class Line {
public:
	Line(Point p, Point q) {
		if (p.x_ != q.x_) {
			slope = (p.y_ - q.y_) / (p.x_ - q.x_); // compute slope
			intercept = p.y_ - slope * p.x_; // y intercept from y = slope* x + intercept
		} else {
			infinite_slope = true;
			intercept = p.x_; // x-intercept, since slope is infinite
		}
	}

	double getSlope() const {
		return slope;
	}
	double getIntercept() const {
		return intercept;
	}
	bool isInfiniteSlope() const {
		return infinite_slope;
	}

	bool operator ==(const Line & rhs) const {
		if (this->infinite_slope && rhs.isInfiniteSlope()) {
			if (this->intercept == rhs.getIntercept())
				return true;
			else
				return false;
		} else if (!this->infinite_slope && !rhs.isInfiniteSlope()
				&& ABS(this->slope-rhs.getSlope()) < EPSILON
				&& ABS(this->intercept-rhs.getIntercept()) < EPSILON)
			return true;
		else
			return false;
	}

	bool operator <(const Line & rhs) const {
		if (this->infinite_slope && rhs.infinite_slope)
			if (this->intercept < rhs.intercept)
				return true;
			else
				return false;
		else if (!this->infinite_slope && !rhs.isInfiniteSlope() && this->slope
				< rhs.slope)
			return true;
		else
			return false;
	}

	void Print() {
		if (this->infinite_slope)
			cout << "x = " << intercept << endl;
		else
			cout << "y = " << slope << "x + " << intercept << endl;
	}

private:
	double slope;
	double intercept;
	bool infinite_slope = false;
};

struct hashfunction {
	size_t operator()(const Line & line) const {
		int sl = (int) (line.getSlope() * 1000);
		int in = (int) (line.getIntercept() * 1000);
		hash<int> ht;
		return ht(sl | in);
	}
};

Line findBestLine(Point points[], int n) {
	Line * bestLine = nullptr;
	Line * line = nullptr;
	std::tr1::unordered_map<Line, int, hashfunction> line_count;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			line = new Line(points[i], points[j]);
			if (line_count.find(*line) == line_count.end())
				line_count.insert(std::make_pair(*line, 0));
			line_count[*line]++;
			if (bestLine == nullptr || line_count[*line]
					> line_count[*bestLine]) {
				delete bestLine;
				bestLine = line;
			}
		}
	}
	return *bestLine;
}

void test() {
	int graph_size = 10;
	int n_points = 500;
	Point * points = new Point[n_points];
	srand(time(NULL));
	for (int i = 0; i < n_points; i++) {
		points[i].x_ = ((double) (rand() % graph_size));
		points[i].y_ = ((double) (rand() % graph_size));
	}
	Line line = findBestLine(points, n_points);
	line.Print();
}
#endif /* EX_10_6_H_ */
