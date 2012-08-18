/*
 * Ex_3_4.h
 *
 *  Created on: Aug 17, 2012
 *      Author: MiTKooK
 */

/*
 * In the classic problem of the Towers of Hanoi, you have 3 rods and N disks of different sizes which can slide onto any tower.
 * The puzzle starts with disks sorted in ascending order of size from top to bottom (e.g., each disk sits on top of an even larger one).
 * You have the following constraints:
 * (A) Only one disk can be moved at a time.
 * (B) A disk is slid off the top of one rod onto the next rod.
 * (C) A disk can only be placed on top of a larger disk.
 *  Write a program to move the disks from the first rod to the last using Stacks.
 */
#ifndef EX_3_4_H_
#define EX_3_4_H_

#include <iostream>
#include <stack>
using namespace std;

class HanoiTower {
public:
	HanoiTower() :
		N(5) {
	}
	HanoiTower(int num) :
		N(num) {
	}

	int getNumOfDisks() {
		return N;
	}
	void placeDisks(int index);
	void moveDisks(int num, int begin, int end);
private:
	int N; // # of disks
	stack<int> rods[3];
};

void HanoiTower::placeDisks(int index) {
	cout << "Rod " << index << ": |-";
	for (int i = N; i > 0; --i) {
		rods[index].push(i);
		cout << i << "-";
	}
	cout << endl;
}

void HanoiTower::moveDisks(int num, int begin, int end) {
	if (num <= 0)
		return;
	else if (num == 1) {
		int movedDisk = rods[begin].top();
		rods[begin].pop();
		rods[end].push(movedDisk);
		cout << "Move disk " << movedDisk << " from rod " << begin
				<< " to rod " << end << endl;
	} else {
		moveDisks(num - 1, begin, 3 - begin - end);
		moveDisks(1, begin, end);
		moveDisks(num - 1, 3 - begin - end, end);
	}
}

void test() {
	HanoiTower ht;
	ht.placeDisks(0);
	cout << "[Move disks from rod 0 to rod 2]" << endl;
	ht.moveDisks(ht.getNumOfDisks(), 0, 2);
}

#endif /* EX_3_4_H_ */
