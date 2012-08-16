/*
 * MyList.h
 *
 *  Created on: Aug 5, 2012
 *      Author: MiTKooK
 */

/*
 * Single Linked List Implementation
 */

#ifndef MYLIST_H_
#define MYLIST_H_

#include <cstdlib>

template<class T>
struct MyNode {
	MyNode(T data) : _data(data), _next(NULL) {}
	T _data;
	MyNode<T> * _next;
};

template<class T>
class MySinglyLinkedList {
public:
	MySinglyLinkedList<T> () {
		_head = NULL;
		_tail = NULL;
		_size = 0;
	}

	~MySinglyLinkedList<T> () {
		// clear();
	}

	MyNode<T> * begin() {return _head;}
	MyNode<T> * end() {return _tail;}
	MyNode<T> * const_begin() const {return _head;}
	MyNode<T> * const_end() const {return _tail;}
	bool empty() const {return _size==0;}
	int size() const {return _size;}
	MyNode<T> & front() {return *_head;}
	void push_front(const T& data);
	void push_back(const T& data);
	void pop_front();
	MyNode<T> * insert_after(MyNode<T> * position, const T& data);
	void insert_after(MyNode<T> * position, int n, const T& data);
	void erase_after(MyNode<T> * position);
	void clear();

private:
	MyNode<T> * _head;
	MyNode<T> * _tail;
	int _size;
};

template<class T>
void MySinglyLinkedList<T>::push_front(const T& data) {
	MyNode<T> * node = new MyNode<T>(data);
	node->_next = _head;
	if(_head == NULL) {
		_tail = node;
	}
	_head = node;
	_size++;
}

template<class T>
void MySinglyLinkedList<T>::push_back(const T& data) {
	if(_tail != NULL) {
		MyNode<T> * node = new MyNode<T>(data);
		_tail->_next = node;
		_tail = node;
		_size++;
	} else {
		push_front(data);
	}
}

template<class T>
void MySinglyLinkedList<T>::pop_front() {
	MyNode<T> * front = _head;
	_head = _head->_next;
	if(_head == NULL)
		_tail = NULL;
	_size--;
	delete front;
}

template<class T>
MyNode<T> * MySinglyLinkedList<T>::insert_after(MyNode<T> * position, const T& data) {

	if(position) {
		MyNode<T> * node = new MyNode<T>(data);
		node->_next = position->_next;
		position->_next = node;
		_size++;
		if(node->_next == NULL)
			_tail = node;
		return node;
	} else {
		push_front(data);
		return _head;
	}

}

template<class T>
void MySinglyLinkedList<T>::insert_after(MyNode<T> * position, int n, const T& data) {

	for(int i=0;i<n;i++) {
		insert_after(position, data);
	}

}

template<class T>
void MySinglyLinkedList<T>::erase_after(MyNode<T> * position) {
	MyNode<T> * node = position->_next;

	if(node) {
		position->_next = node->_next;
		_size--;
		if(position->_next == NULL)
			_tail = position;
	}

	delete node;
}

template<class T>
void MySinglyLinkedList<T>::clear() {
	while(_size != 0)
		pop_front();
}

#endif /* MYLIST_H_ */
