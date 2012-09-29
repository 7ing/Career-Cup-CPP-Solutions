/*
 * MyAlgorithms.h
 *
 *  Created on: Aug 22, 2012
 *      Author: jliu
 */

/*
 * Well-Known Algorithms Implementation
 */

#ifndef MYALGORITHMS_H_
#define MYALGORITHMS_H_

#include <cstring>  // using memset

/*
 * --------------------    Sorting Algorithms     -----------------------------
 * NOTE:
 * - Definition refers to "Sorting.cpp"
 * - Sorting in ascending order
 * - Assume input is array with integers
 * - "n" is the size of the array (e.g., a[])
 */

void bubble_sort(int a[], int n);  // O(n^2)
void selection_sort(int a[], int n); // O(n^2)
void heap_sort(int a[], int n); // O(nlogn)
void insertion_sort(int a[], int n); // O(n^2)
void shell_sort(int a[], int n); // O(n log^2 n)
void quick_sort(int a[], int left, int right); // CSLR version  O(nlogn)
void quick_sort2(int a[], int left, int right); // Hoare version  O(nlogn)
void merge_sort(int *a, int n); // O(nlogn)
void counting_sort(int a[], int n); // O(n+m)
void radix_sort(int a[], int n); // O(k¡¤n)
void bitmap_sort(int a[], int n); // O(n)

/*
 * -------------------- End of Sorting Algorithms -----------------------------
 */
#endif /* MYALGORITHMS_H_ */
