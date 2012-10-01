/*
 * Ex_9_7.h
 *
 *  Created on: Sep 30, 2012
 *      Author: MiTKooK
 */

/*
 * A circus is designing a tower routine consisting of people standing atop one another¡¯s shoulders.
 * For practical and aesthetic reasons, each person must be both shorter and lighter than the person
 * below him or her. Given the heights and weights of each person in the circus, write a method to
 * compute the largest possible number of people in such a tower.
 * EXAMPLE:
 * Input (ht, wt): (65, 100) (70, 150) (56, 90) (75, 190) (60, 95) (68, 110)
 * Output: The longest tower is length 6 and includes from top to bottom: (56, 90) (60,95) (65,100) (68,110) (70,150) (75,190)
 */

#ifndef EX_9_7_H_
#define EX_9_7_H_

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class HtWt {
public:
	HtWt(int ht, int wt) :
		ht_(ht), wt_(wt) {
	}
	int getHt() {
		return ht_;
	}
	int getWt() {
		return wt_;
	}
	bool isAfter(HtWt previous) {
		if (ht_ > previous.ht_ && wt_ > previous.wt_) {
			return true;
		} else {
			return false;
		}
	}
private:
	int ht_;
	int wt_;
};

bool compare(HtWt a, HtWt b) {
	if (a.getHt() != b.getHt())
		return a.getHt() < b.getHt();
	else
		return a.getWt() < b.getWt();
}

// Fills next seq w decreased wts - returns index of 1st unfit item.
unsigned int fillNextSeq(vector<HtWt> & items, unsigned int startFrom, vector<
		HtWt> & seq) {
	unsigned int firstUnfitItem = startFrom;
	if (startFrom < items.size()) {
		for (unsigned int i = startFrom; i < items.size(); i++) {
			if (i == startFrom || items[i].isAfter(seq.back())) {
				seq.push_back(items[i]);
			} else {
				firstUnfitItem = i;
			}
		}
	}
	return firstUnfitItem;
}

// Find the maximum length sequence
vector<HtWt> findMaxSeq(vector<HtWt> items) {
	sort(items.begin(), items.end(), compare);
	vector<HtWt> maxSeq;

	unsigned int currentUnfit = 0, nextUnfit = 0;
	while (currentUnfit < items.size()) {
		vector<HtWt> nextSeq;
		nextUnfit = fillNextSeq(items, currentUnfit, nextSeq);
		if (maxSeq.size() < nextSeq.size())
			maxSeq = nextSeq;
		if (nextUnfit == currentUnfit)
			break;
		else
			currentUnfit = nextUnfit;
	}
	return maxSeq;
}

void test() {
	vector<HtWt> items;
	items.push_back(HtWt(65, 100));
	items.push_back(HtWt(70, 150));
	items.push_back(HtWt(56, 90));
	items.push_back(HtWt(75, 190));
	items.push_back(HtWt(60, 95));
	items.push_back(HtWt(68, 110));

	cout << "Input (ht,wt): ";
	vector<HtWt>::iterator it = items.begin();
	while (it != items.end()) {
		cout << "(" << it->getHt() << ", " << it->getWt() << ") ";
		it++;
	}
	cout << endl << "Output: ";

	vector<HtWt> maxSeq = findMaxSeq(items);
	it = maxSeq.begin();
	while (it != maxSeq.end()) {
		cout << "(" << it->getHt() << ", " << it->getWt() << ") ";
		it++;
	}
	cout << endl;
}

#endif /* EX_9_7_H_ */
