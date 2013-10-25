/*
 * Sorting.cpp
 *
 *  Created on: Sep 28, 2012
 *      Author: MiTKooK
 */

#include "MyAlgorithms.h"

/*
 * -------------------- Sorting Algorithms -----------------------------------
 *
 * Include:
 * - Bubble Sort
 * - Selection Sort, Heap Sort
 * - Insertion Sort,  Shell Sort (Diminishing Increment sort)
 * - Quick Sort,  Hoare Quick Sort
 * - Merge Sort
 * - Counting Sort (Bucket Sort / Bin Sort, Pigeon Hole Sort), Radix Sort
 * - Bitmap Sort
 *
 * Note:
 * - Assume input is array with integers
 * - "n" is the size of the array (e.g., a[])
 */

/*
 * do not use extra space to swap two integers
 */
void swap(int & a, int & b) {
	if (a != b) {
		/*
		 * binary method: only work for integers
		 * a ^= b ^= a ^= b; // may have warnings in certain compilers
		 */
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
		/*
		 * universal method:
		 * a = a + b; b = a - b; a = a - b;
		 */
	}
}

/*
 * Bubble Sort  O(n^2)
 *
 * Start at the beginning of an array and swap the first two elements if the first is bigger than the second.
 * Go to the next pair, etc, continuously making sweeps of the array until sorted.
 */

void bubble_sort(int a[], int n) {
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
		}
	}
}

/*
 * Selection Sort  O(n^2)
 *
 * Find the smallest element using a linear scan and move it to the front. Then, find the second smallest and
 * move it, again doing a linear scan. Continue doing this until all the elements are in place.
 */

void selection_sort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
}

/*
 * Heap Sort   O(nlogn)
 *
 * in place, not stable sort
 * It starts by building a heap from the initial array. Since the maximum element of the array is stored at the root,
 * a[0], it can be put into its correct final position by exchanging it with a[n-1].
 *
 */

// O(logn)
void heapify(int a[], int n, int i) {
	int current, left, right;
	int max = i;

	do {
		current = max;
		left = 2 * current + 1;
		right = 2 * current + 2;
		if (left < n && a[left] > a[current])
			max = left;
		if (right < n && a[right] > a[max])
			max = right;
		if (current != max)
			swap(a[current], a[max]);
	} while (current != max);
}

void heap_sort(int a[], int n) {

	// make heap  O(n)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);

	int size = n;
	while (size >= 1) {
		swap(a[0], a[--size]);
		heapify(a,size,0);
	}
}

/*
 * Insertion Sort  O(n^2)
 *
 * Every repetition of insertion sort removes an element from the input data, inserting it into
 * the correct position in the already-sorted list, until no input elements remain.
 */

void insertion_sort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int item = a[i];
		int j = i;
		while (j > 0 && a[j - 1] > item) {
			a[j] = a[j - 1];
			j--;
		}
		a[j] = item;
	}
}

/*
 * Shell Sort  O(n log^2 n)
 * - aka. diminishing increment sort
 * A variant of Insertion Sort. It generalizes an exchanging sort by starting the comparison and
 * exchange of elements with elements that are far apart before finishing with neighboring elements.
 * Starting with far apart elements can move some out-of-place elements into position faster than
 * a simple nearest neighbor exchange.
 */

// Ref: http://en.wikipedia.org/wiki/Shellsort
void shell_sort(int a[], int n) {
	int j, k, temp;
	int gap[] = { 1750, 701, 301, 132, 57, 23, 10, 4, 1 }; // using Marcin Ciura's gap sequence
	for (k = 0; gap[k] > n; k++)
		; // gap should less than the size of array
	for (; gap[k] > 0; k++)
		// Do an insertion sort for each gap size
		for (int i = gap[k]; i < n; i++) {
			temp = a[i];
			for (j = i; j >= gap[k] && a[j - gap[k]] > temp; j -= gap[k])
				a[j] = a[j - gap[k]];
			a[j] = temp;
		}
}

/*
 * Quick Sort    O(nlogn) expected, O(n^2) worst case
 *
 * Pick a random element and partition the array, such that all numbers that are less than it come before all
 * elements that are greater than it. Then do that for each half, then each quarter, etc.
 */

// CSLR edition QuickSort - partition
int partition(int a[], int left, int right) {
	int i = left - 1;
	for (int j = left; j <= right; j++) {
		if (a[j] <= a[right]) {
			i++;
			if (i != j)
				swap(a[i], a[j]);
		}
	}
	return i;
}

// CSLR edition QuickSort - sorting
void quick_sort(int a[], int left, int right) {
	if (left < right) {
		int pivot = partition(a, left, right);
		quick_sort(a, left, pivot - 1);
		quick_sort(a, pivot + 1, right);
	}
}

// Hoare edition QuickSort
void quick_sort2(int a[], int left, int right) {
	int i = left, j = right;
	// here can choose the median of a[left], a[mid], and a[right]
	int pivot = a[(left + right) / 2];
	while (i < j) {
		while (a[i] < pivot)
			i++;
		while (a[j] > pivot)
			j--;
		if (i <= j)
			swap(a[i++], a[j--]);
	}
	if (left < j)
		quick_sort2(a, left, j);
	if (i < right)
		quick_sort2(a, i, right);
}

/*
 * Merge Sort    O(nlogn) expected, O(n^2) worst case
 *
 * Sort each pair of elements. Then sort every four elements by merging every two pairs. Then, sort every 8
 * elements, etc.
 */

// O(n) merge two sorted arrays
int * merge(int left[], int x, int right[], int y) {
	int *result = new int[x + y];
	int i = 0, j = 0, k = 0;
	while (i < x && j < y) {
		if (left[i] < right[j])
			result[k++] = left[i++];
		else
			result[k++] = right[j++];
	}
	while (i < x)
		result[k++] = left[i++];
	while (j < y)
		result[k++] = right[j++];

	return result;
}

// O(logn)
void merge_sort(int *a, int n) {
	if (n <= 1) // base case
		return;
	int x = n / 2;
	int y = n - x;
	int *left = new int[x];
	int *right = new int[y];

	int i = 0, k = 0;
	for (; i < x; i++)
		left[k++] = a[i];
	for (k = 0; i < n; i++)
		right[k++] = a[i];

	merge_sort(left, x);
	merge_sort(right, y);

	int * result = merge(left, x, right, y);
	for (int i = 0; i < n; i++)
		a[i] = result[i];

	delete result;
	delete[] left;
	delete[] right;
}

/*
 * Counting Sort   O(n+m), m is the # of distinct items
 *
 * - A variant of Bucket Sort (Bin Sort), Pigeon Hole Sort
 * - Partition the array into a finite number of buckets, and then sort each bucket individually.
 */

void counting_sort(int a[], int n) {
	int max = a[0], min = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}

	int range = max - min + 1;
	int *count = new int[range];

	for (int i = 0; i < range; i++)
		count[i] = 0;

	for (int i = 0; i < range; i++)
		count[a[i] - min]++;

	int index = 0;
	for (int i = min; i <= max; i++)
		for (int j = 0; j < count[i - min]; j++)
			a[index++] = i;

	delete[] count;
}

/*
 * Radix Sort  O(k¡¤n) for n keys which have k or fewer digits.
 *
 * Sorts data with integer keys by grouping keys by the individual digits which share the same significant position and value.
 */

// Ref: http://en.wikipedia.org/wiki/Radix_sort
void radix_sort(int a[], int n) {
	int i, max = a[0], radix = 1;
	// find max value
	for (i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];

	int *b = new int[n];

	while (max / radix > 0) {
		int bucket[10] = { 0 };
		for (i = 0; i < n; i++) // put values in the bucket base on LSD
			bucket[a[i] / radix % 10]++;
		for (i = 1; i < 10; i++) // calculate the start index in a[] for each bucket
			bucket[i] += bucket[i - 1];
		for (i = n - 1; i >= 0; i--) // bucket sort, stable
			b[--bucket[a[i] / radix % 10]] = a[i];
		for (i = 0; i < n; i++)
			a[i] = b[i];
		radix *= 10;
	}

	delete[] b;
}

/*
 * Bitmap Sort  O(n)
 *
 * only work for distinct integers, save space, typically design for small sets
 */

// Ref: http://blog.csdn.net/v_july_v/article/details/6685962
void bitmap_sort(int a[], int n) {

	int max = a[0], min = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}

	int range = max - min + 1;
	const int BufferLen = range / 8 + (range % 8 > 0 ? 1 : 0); // 1 Byte = 8 bits
	char *pBuffer = new char[BufferLen];

	memset(pBuffer, 0, BufferLen);

	int offset;
	for (int i = 0; i < n; i++) {
		//set corresponding bit to 1
		offset = a[i] - min;
		pBuffer[offset / 8] |= (0x01 << (offset % 8));
	}

	// sorting
	int k = 0;
	for (int i = 0; i < BufferLen; i++)//process every byte
	{
		for (int j = 0; j < 8; j++)//process every bit
		{
			if ((pBuffer[i] & (0x01 << j)) > 0) {
				a[k++] = i * 8 + j + min;
				if (k == n)
					return;
			}
		}
	}
}

/*
 * -------------------- End of Sorting Algorithms -----------------------------
 */
