/*
 * MyHeap.h
 *
 *  Created on: Sep 28, 2012
 *      Author: MiTKooK
 */

#ifndef MYHEAP_H_
#define MYHEAP_H_

#include<cstdlib>
#include<vector>

template<class T>
class MyHeap {
public:
	~MyHeap();
	virtual bool isEmpty() = 0;
	virtual bool find(T data) = 0;
	virtual void push_heap(T data) = 0;
	virtual T pop_heap() = 0;
	virtual void make_heap(vector<T> & v) = 0;
protected:
	void swap(T & x, T & y);
};

template<class T>
MyHeap<T>::~MyHeap() {
}

template<class T>
void MyHeap<T>::swap(T & x, T & y) {
	x = x + y;
	y = x - y;
	x = x - y;
}

// max heap implementation
template<class T>
class MaxHeap: public MyHeap<T> {

public:
	MaxHeap();
	~MaxHeap();
	bool isEmpty();
	bool find(T data);
	void push_heap(T data);
	T pop_heap();
	void make_heap(vector<T> & v);

private:
	vector<T> heap_;
	void reheapify_down(int i);
	void reheapify_up();
	int parent(int i) {
		return (i - 1) / 2;
	}
	int left_child(int i) {
		return 2 * i + 1;
	}
	int right_child(int i) {
		return 2 * i + 2;
	}
};

template<class T> inline MaxHeap<T>::MaxHeap() {
	// do nothing
}

template<class T> inline MaxHeap<T>::~MaxHeap() {
	heap_.clear();
}

template<class T> inline bool MaxHeap<T>::isEmpty() {
	return heap_.empty();
}

template<class T> inline bool MaxHeap<T>::find(T data) {
	int size = heap_.size();
	for (int i = 0; i < size; i++) {
		if (heap_[i] == data)
			return true;
	}
	return false;
}

template<class T> inline void MaxHeap<T>::push_heap(T data) {
	heap_.push_back(data);
	reheapify_up();
}

template<class T> inline T MaxHeap<T>::pop_heap() {
	T root = heap_.front();
	heap_[0] = heap_.back();
	heap_.pop_back();
	reheapify_down(0);
	return root;
}

template<class T> inline void MaxHeap<T>::make_heap(vector<T> & v) {
	if (heap_.size() != 0)
		heap_.clear();
	heap_ = v;

	// start with last parent, and reheapify_down back to root
	for (int i = parent(v.size() - 1); i >= 0; i--)
		reheapify_down(i);

	v = heap_;
}

template<class T> inline void MaxHeap<T>::reheapify_down(int i) {
	if (heap_.empty())
		return;

	int current = i, max = i;
	int left = 1, right = 2;
	int size = heap_.size();

	do {
		current = max;
		left = left_child(current);
		right = right_child(current);
		if (left < size && heap_[left] > heap_[current])
			max = left;
		if (right < size && heap_[right] > heap_[max])
			max = right;
		if (max != current)
			swap(heap_[current], heap_[max]);
	} while (max != current);
}

template<class T> inline void MaxHeap<T>::reheapify_up() {
	int current = heap_.size() - 1;
	int cur_parent = parent(current);

	while (current > 0 && heap_[current] > heap_[cur_parent]) {
		swap(heap_[current], heap_[cur_parent]);
		current = cur_parent;
		cur_parent = parent(current);
	}
}

// min heap implementation
template<class T>
class MinHeap: public MyHeap<T> {

public:
	MinHeap();
	~MinHeap();
	bool isEmpty();
	bool find(T data);
	void push_heap(T data);
	T pop_heap();
	void make_heap(vector<T> & v);

private:
	vector<T> heap_;
	void reheapify_down(int i);
	void reheapify_up();
	int parent(int i) {
		return (i - 1) / 2;
	}
	int left_child(int i) {
		return 2 * i + 1;
	}
	int right_child(int i) {
		return 2 * i + 2;
	}
};

template<class T> inline MinHeap<T>::MinHeap() {
	// do nothing
}

template<class T> inline MinHeap<T>::~MinHeap() {
	heap_.clear();
}

template<class T> inline bool MinHeap<T>::isEmpty() {
	return heap_.empty();
}

template<class T> inline bool MinHeap<T>::find(T data) {
	int size = heap_.size();
	for (int i = 0; i < size; i++) {
		if (heap_[i] == data)
			return true;
	}
	return false;
}

template<class T> inline void MinHeap<T>::push_heap(T data) {
	heap_.push_back(data);
	reheapify_up();
}

template<class T> inline T MinHeap<T>::pop_heap() {
	T root = heap_.front();
	heap_[0] = heap_.back();
	heap_.pop_back();
	reheapify_down(0);
	return root;
}

template<class T> inline void MinHeap<T>::make_heap(vector<T> & v) {
	if (heap_.size() != 0)
		heap_.clear();
	heap_ = v;
	// start with last parent, and reheapify_down back to root
	for (int i = parent(v.size() - 1); i >= 0; i--)
		reheapify_down(i);
}

template<class T> inline void MinHeap<T>::reheapify_down(int i) {
	if (heap_.empty())
		return;

	int current = i, min = i;
	int left = 1, right = 2;
	int size = heap_.size();

	do {
		current = min;
		left = left_child(current);
		right = right_child(current);
		if (left < size && heap_[left] < heap_[current])
			min = left;
		if (right < size && heap_[right] < heap_[min])
			min = right;
		if (min != current)
			swap(heap_[current], heap_[min]);
	} while (min != current);

}

template<class T> inline void MinHeap<T>::reheapify_up() {
	int current = heap_.size() - 1;
	int cur_parent = parent(current);

	while (current > 0 && heap_[current] < heap_[cur_parent]) {
		swap(heap_[current], heap_[cur_parent]);
		current = cur_parent;
		cur_parent = parent(current);
	}
}

#endif /* MYHEAP_H_ */
