/*
 * Ex_8_2.h
 *
 *  Created on: Sep 10, 2012
 *      Author: jliu
 */

/*
 * Imagine a robot sitting on the upper left hand corner of an NxN grid. The robot can
 * only move in two directions: right and down. How many possible paths are there for
 * the robot?
 * FOLLOW UP
 * Imagine certain squares are "off limits", such that the robot can not step on them.
 * Design an algorithm to get all possible paths for the robot.
 *
 * PS: End point for the path is lower right hand corner of the grid
 */

#ifndef EX_8_2_H_
#define EX_8_2_H_

#include<iostream>
#include<cstring>
#include<list>
#include<vector>
using namespace std;

struct Point {
	Point(int i, int j) :
			x(i), y(j) {
	}
	int x;
	int y;
};

/*
 * grid[i][j] <= 0 means "off limits"
 * N x M : grid
 */

void findPath(int **grid, int N, int M, int i, int j,
		list<vector<Point> > & path) {
	// reach the end point
	if (i == N - 1 && j == M - 1)
		return;
	int directions = 2;
	if (i >= N - 1 || grid[i + 1][j] <= 0)
		directions--;
	if (j >= M - 1 || grid[i][j + 1] <= 0)
		directions--;

	if (directions == 0) {
		// path cannot go through (i,j), delete every such path
		list<vector<Point> >::iterator it = path.begin();
		while (it != path.end()) {
			if (it->back().x == i && it->back().y == j) {
				path.erase(it);
				continue;
			}
			it++;
		}
		return;
	}

	// go down
	if (i < N - 1 && grid[i + 1][j] > 0) {
		// for each path end with (i,j), add (i+1, j)
		list<vector<Point> > secondPaths;
		list<vector<Point> >::iterator it = path.begin();
		while (it != path.end()) {
			if (it->back().x == i && it->back().y == j) {
				if (directions == 2)
					secondPaths.push_back(*it);
				Point *p = new Point(i + 1, j);
				it->push_back(*p);
			}
			it++;
		}
		if (directions == 2) {
			it = secondPaths.begin();
			while (it != secondPaths.end()) {
				path.push_back(*it);
				it++;
			}
		}
		secondPaths.clear();

		// recursive call findPath for point(i+1, j)
		findPath(grid, N, M, i + 1, j, path);
	}

	// go right
	if (j < M - 1 && grid[i][j + 1] > 0) {
		// for each path end with (i, j), add (i, j+1)
		list<vector<Point> >::iterator it = path.begin();
		while (it != path.end()) {
			if (it->back().x == i && it->back().y == j) {
				Point *p = new Point(i, j + 1);
				it->push_back(*p);
			}
			it++;
		}
		// recursive call findPath for point(i, j+1)
		findPath(grid, N, M, i, j + 1, path);
	}
}

void test() {

	int N = 4;
	int **grid = new int*[N];
	grid[0] = new int[N * N];
	for (int i = 1; i < N; i++)
		grid[i] = grid[i - 1] + N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			grid[i][j] = 1;
			if (i == 1 && j == 1)
				grid[i][j] = 0;
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}

	list<vector<Point> > paths;
	Point *start = new Point(0, 0);
	vector<Point> path;
	path.push_back(*start);
	paths.push_back(path);

	findPath(grid, N, N, 0, 0, paths);

	list<vector<Point> >::iterator it = paths.begin();
	int pathNum = 1;
	while (it != paths.end()) {
		cout << "path " << pathNum++ << " : ";
		vector<Point>::iterator it2 = it->begin();
		while (it2 != it->end()) {
			cout << "(" << it2->x << "," << it2->y << ")";
			it2++;
		}
		it++;
		cout << endl;
	}
}

#endif /* EX_8_2_H_ */
