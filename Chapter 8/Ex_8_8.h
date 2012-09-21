/*
 * Ex_8_8.h
 *
 *  Created on: Sep 21, 2012
 *      Author: MiTKooK
 */

/*
 * Write an algorithm to print all ways of arranging eight queens on a chess board so
 * that none of them share the same row, column or diagonal.
 */

#ifndef EX_8_8_H_
#define EX_8_8_H_

#include<iostream>
#include<cstdlib>
using namespace std;

void printBoard(int * colForRow) {
	cout<<"-----------------"<<endl;
	for(int i = 0; i < 8; i++){
		cout<<"|";
		for(int j = 0; j < 8; j++){
		    if (colForRow[i] == j)
		    	cout<<"Q|";
		    else
		    	cout<<" |";
		}
		cout<<endl<<"-----------------"<<endl;
	}
	cout<<endl;
}

void placeQueen(int * colForRow, int row) {
	if (row == 8) { // base case
		printBoard(colForRow);
		return;
	}

	for (int j = 0; j < 8; j++) {
		bool check = true;
		colForRow[row] = j;
		for (int i = 0; i < row; i++) {
			int diff = abs(colForRow[i] - colForRow[row]);
			if (diff == 0 || diff == row - i) // same column or same diagonal
				check = false;
		}
		if (check) {
			placeQueen(colForRow, row + 1);
		} // else check next column of this row
	}
}

void test() {

	int colForRow[8];
	placeQueen(colForRow, 0);

}

#endif /* EX_8_8_H_ */
