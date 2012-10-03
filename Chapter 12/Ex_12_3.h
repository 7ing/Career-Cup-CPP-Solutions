/*
 * Ex_12_3.h
 *
 *  Created on: Oct 2, 2012
 *      Author: MiTKooK
 */

/*
 * Given an input file with four billion integers, provide an algorithm to generate an integer
 * which is not contained in the file. Assume you have 1 GB of memory.
 * FOLLOW UP
 * What if you have only 10 MB of memory?
 */

#ifndef EX_12_3_H_
#define EX_12_3_H_

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<cstring>
using namespace std;

unsigned int findMissingInteger(char * filename) {
	char * bitmap = new char[0x1FFFFFFF]; // 0xFFFFFFFF / 8 = 0x1FFFFFFF

	ifstream myfile;
	myfile.open(filename);
	if (!myfile) {
		cerr << "error: unable to open output file : " << filename << endl;
		return 0;
	}

	char c[32];
	unsigned int n;

	while (myfile.getline(c, 32)) {
		n = static_cast<unsigned int> (strtoul(c, NULL, 10));
		bitmap[n / 8] |= 1 << (n % 8);
	}

	myfile.close();

	for (unsigned int i = 0; i < 0x1FFFFFFF; i++) {
		for (unsigned int j = 0; j < 8; j++) {
			if ((bitmap[i] & (1 << j)) == 0)
				return i * 8 + j;
		}
	}

	delete[] bitmap;
	return 0; // not found
}

unsigned int findMissingIntegerInBlocks(char * filename) {
	ifstream myfile;
	myfile.open(filename);
	if (!myfile) {
		cerr << "error: unable to open output file : " << filename << endl;
		return 0;
	}

	int bitsize = 1048576; // 2^20 bits
	int blockNum = 4096; // 2^12
	char * bitmap = new char[bitsize / 8];
	int * blocks = new int[blockNum];

	memset(blocks,0,blockNum);

	char c[32];
	unsigned int n;

	while (myfile.getline(c, 32)) {
		n = static_cast<unsigned int> (strtoul(c, NULL, 10));
		blocks[n / bitsize]++;
	}

	unsigned int missingBlock = 0;

	for (int i = 0; i < blockNum; i++) {
		if (blocks[i] < bitsize) {
			/* if value < 2^20, then at least 1 number is missing in
			 * that section. */
			missingBlock = i * bitsize;
			break;
		}
	}

	myfile.clear();
	myfile.seekg(0,ios_base::beg);

	while (myfile.getline(c, 32)) {
		n = static_cast<unsigned int> (strtoul(c, NULL, 10));
		/* If the number is inside the block that is missing numbers,
		 * we record it */
		if (n >= missingBlock && n < missingBlock + bitsize) {
			bitmap[(n - missingBlock) / 8] |= 1 << ((n - missingBlock) % 8);
		}
	}

	for (int i = 0; i < bitsize / 8; i++) {
		for (int j = 0; j < 8; j++) {
			/* Retrieves the individual bits of each byte. When 0 bit
			 * is found, finds the corresponding value. */
			if ((bitmap[i] & (1 << j)) == 0)
				return i * 8 + j + missingBlock;
		}
	}

	myfile.close();
	return 0;
}

void test() {

	char filename[] = "test.dat";

	ofstream myfile;
	myfile.open(filename);
	if (!myfile) {
		cerr << "error: unable to open output file : " << filename << endl;
		exit(1);
	}

	unsigned int i;
	for (i = 0; i < 99; i++) // missing 99
		myfile << i << endl;
	for (i = 100; i < 1000; i++) // change 1000 to 0xFFFFFFFF (4 billion)
		myfile << i << endl;

	myfile.close();

	cout << "The missing integer is: " << findMissingInteger(filename) << endl;
	cout << "The missing integer is: " << findMissingIntegerInBlocks(filename) << endl;

	// delete test file, if failed, please delete it manually
	if (remove(filename) != 0)
		cerr << "Error deleting file." << endl;
}

#endif /* EX_12_3_H_ */
