/*
 * Ex_8_3.h
 *
 *  Created on: Sep 11, 2012
 *      Author: jliu
 */

/*
 * Write a method that returns all subsets of a set.
 */

#ifndef EX_8_3_H_
#define EX_8_3_H_

#include<iostream>
#include<vector>
#include<set>
using namespace std;

/*
 * 1st method:
 * recursive method
 */
template<class T>
void getSubsets(set<T> & s, vector<set<T> > & result, int index) {
	if ((unsigned int)index == s.size()) {
		set<T> empty_set;
		result.push_back(empty_set);
	} else {
		getSubsets(s, result, index + 1);
		typename set<T>::iterator it = s.begin();
		for (int i = 0; i < index; i++) {
			it++;
		}
		vector<set<T> > new_subsets;
		typename vector<set<T> >::iterator it2 = result.begin();
		while (it2 != result.end()) {
			set<T> new_subset = *it2;
			new_subset.insert(*it);
			new_subsets.push_back(new_subset);
			it2++;
		}
		result.insert(result.end(), new_subsets.begin(), new_subsets.end());
	}
}

/*
 * 2nd method:
 * the index of each set element can be regarded as the index of a binary number
 * 1 means this element will be presented in the subset, 0 means won't be there.
 * simply generate all numbers that are no grater than the number of subsets.
 */
template<class T>
void getSubsets_Binary(set<T> & s, vector<set<T> > & result) {
	if (s.size() > 32) {
		cout << "set is too big to be displayed";
		return;
	}
	int num_of_subsets = 1 << s.size();
	typename set<T>::iterator it;
	for (int i = 0; i < num_of_subsets; i++) {
		set<T> subset;
		int num = i;
		it = s.begin();
		while (num > 0) {
			if (num & 1)
				subset.insert(*it);
			it++;
			num >>= 1;
		}
		result.push_back(subset);
	}
}

void test() {

	set<int> set_;
	cout << "SET: { ";
	for (int i = 0; i < 3; i++) {
		set_.insert(i);
		cout << i << " ";
	}
	cout << "}" << endl;

	vector<set<int> > subset_recursive_method;
	getSubsets(set_, subset_recursive_method, 0);
	vector<set<int> >::iterator it = subset_recursive_method.begin();
	set<int>::iterator it2;
	cout << "ALL SUBSETS: ";
	while (it != subset_recursive_method.end()) {
		cout << "{ ";
		it2 = (*it).begin();
		while (it2 != (*it).end()) {
			cout << *it2 << " ";
			it2++;
		}
		cout << "} ";
		it++;
	}
	cout << endl;

	vector<set<int> > subset_binary_method;
	getSubsets_Binary(set_, subset_binary_method);
	it = subset_binary_method.begin();
	cout << "ALL SUBSETS: ";
	while (it != subset_binary_method.end()) {
		cout << "{ ";
		it2 = (*it).begin();
		while (it2 != (*it).end()) {
			cout << *it2 << " ";
			it2++;
		}
		cout << "} ";
		it++;
	}
}

#endif /* EX_8_3_H_ */
