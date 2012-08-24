/*
 * MyGraph.h
 *
 *  Created on: Aug 21, 2012
 *      Author: jliu
 */

/*
 * Graph Implementation using STL - list
 * reference: http://www.cs.bu.edu/teaching/c/graph/linked/
 */

#ifndef MYGRAPH_H_
#define MYGRAPH_H_

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <list>
#include <tr1/unordered_map>

using namespace std;

/*
 * Abstract Class
 */
template<class T>
class MyGraph {
public:
	virtual ~MyGraph<T>() = 0;
	virtual void addVertex(T label) = 0;
	virtual void addEdge(T u, T v, int weight = 0) = 0;
	virtual void removeVertex(T label) = 0;
	virtual void removeEdge(T u, T v) = 0;
	virtual bool isConnected(T u, T v) = 0;
	virtual int size() const = 0;
	virtual void printGraph() const = 0;
	virtual int ** getGraph() const = 0;
};

template<class T>
MyGraph<T>::~MyGraph<T>() {
}

/*
 * Directed Graph Implementation - Linked List
 * - Adjacency Matrix Expression
 */

// solution for mutual reference: pre-define
template<class T>
struct MyVertex;

template<class T>
struct MyEdge;

template<class T>
struct MyVertex {
	MyVertex<T>(T data) :
			_data(data), _isVisit(false), _neighbors() {
	}
	T _data;
	bool _isVisit;
	list<MyEdge<T> > _neighbors;
};

template<class T>
struct MyEdge {
	MyEdge<T>() :
			_weight(0), _connectsTo(NULL) {
	}
	MyEdge<T>(int w, MyVertex<T> * mv) :
			_weight(w), _connectsTo(mv) {
	}
	int _weight;
	MyVertex<T> * _connectsTo;
};

template<class T>
class DirectedGraph: public MyGraph<T> {
public:
	DirectedGraph<T>() :
			_size(0), _vertexes() {
	}
	~DirectedGraph<T>();
	void addVertex(T label);
	void addEdge(T u, T v, int weight = 0);
	void removeVertex(T label);
	void removeEdge(T u, T v);
	bool isConnected(T u, T v);
	int size() const;
	void printGraph() const;
	int ** getGraph() const;
private:
	int _size;
	list<MyVertex<T> > _vertexes;
	MyVertex<T> * getVertex(T label);
};

template<class T>
inline DirectedGraph<T>::~DirectedGraph<T>() {
	typename list<MyVertex<T> >::iterator it = _vertexes.begin();
	for (; it != _vertexes.end(); it++)
		(it->_neighbors).clear();
	_vertexes.clear();
	_size = 0;
}

template<class T>
inline void DirectedGraph<T>::addVertex(T label) {
	if (getVertex(label) == NULL) {
		MyVertex<T> *mv = new MyVertex<T>(label);
		_vertexes.push_back(*mv);
		_size++;
	} else
		cout << "Vertex \'" << label << "\' already exists." << endl;
}

template<class T>
inline void DirectedGraph<T>::addEdge(T u, T v, int weight) {
	MyVertex<T> * vertex_u = getVertex(u);
	MyVertex<T> * vertex_v = getVertex(v);
	if (vertex_u && vertex_v) {
		typename list<MyEdge<T> >::iterator it = vertex_u->_neighbors.begin();
		for (; it != vertex_u->_neighbors.end(); it++) {
			if (it->_connectsTo == vertex_v) {
				cout << "Add Error: Edge already exists." << endl;
				return;
			}
		}
		MyEdge<T> *me = new MyEdge<T>(weight, vertex_v);
		vertex_u->_neighbors.push_back(*me);
	} else
		cout << "Add Error: No such vertex." << endl;
}

template<class T>
inline void DirectedGraph<T>::removeVertex(T label) {
	if (getVertex(label) == NULL) {
		cout << "Remove Error: No such vertex" << endl;
		return;
	}
	typename list<MyVertex<T> >::iterator it_v = _vertexes.begin();
	typename list<MyEdge<T> >::iterator it_e;
	typename list<MyVertex<T> >::iterator it_to_be_removed;
	for (; it_v != _vertexes.end(); it_v++) {
		if (it_v->_data == label) {
			it_to_be_removed = it_v;
			continue;
		}

		it_e = (it_v->_neighbors).begin();
		for (; it_e != (it_v->_neighbors).end(); it_e++) {
			if (it_e->_connectsTo->_data == label) {
				it_e = (it_v->_neighbors).erase(it_e);
				it_e--;
			}
		}
	}
	_vertexes.erase(it_to_be_removed);
	_size--;
}

template<class T>
inline void DirectedGraph<T>::removeEdge(T u, T v) {
	MyVertex<T> * vertex_u = getVertex(u);
	MyVertex<T> * vertex_v = getVertex(v);
	if (vertex_u && vertex_v) {
		typename list<MyEdge<T> >::iterator it = vertex_u->_neighbors.begin();
		for (; it != vertex_u->_neighbors.end(); it++) {
			if (it->_connectsTo == vertex_v) {
				vertex_u->_neighbors.erase(it);
				return;
			}
		}
	} else
		cout << "Remove Error: No such vertex." << endl;
}

template<class T>
inline bool DirectedGraph<T>::isConnected(const T u, const T v) {
	MyVertex<T> * vertex_u = getVertex(u);
	MyVertex<T> * vertex_v = getVertex(v);
	if (vertex_u && vertex_v) {
		typename list<MyEdge<T> >::iterator it = vertex_u->_neighbors.begin();
		for (; it != vertex_u->_neighbors.end(); it++) {
			if (it->_connectsTo == vertex_v)
				return true;
		}
	} else {
		cout << "Error: No such vertex." << endl;
	}
	return false;
}

template<class T>
inline int DirectedGraph<T>::size() const {
	return _vertexes.size();
}

template<class T>
inline void DirectedGraph<T>::printGraph() const {
	int ** matrix = getGraph();
	typename list<MyVertex<T> >::const_iterator it_v = _vertexes.begin();
	std::tr1::unordered_map<T, int> vertex_map;

	for (int i = 0; it_v != _vertexes.end(); it_v++, i++) {
		vertex_map.insert(make_pair(it_v->_data, i));
	}

	cout << "  ";
	for (it_v = _vertexes.begin(); it_v != _vertexes.end(); it_v++)
		cout << it_v->_data << " ";
	cout << endl;
	it_v = _vertexes.begin();
	for (int i = 0; i < _size; i++) {
		cout << it_v->_data << " ";
		for (int j = 0; j < _size; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
		it_v++;
	}
}

template<class T>
inline int ** DirectedGraph<T>::getGraph() const {
	int **matrix = new T*[_size];
	matrix[0] = new T[_size * _size];
	for (int i = 1; i < _size; i++)
		matrix[i] = matrix[i - 1] + _size;
	memset(matrix[0], 0, sizeof(matrix[0]));
	typename list<MyVertex<T> >::const_iterator it_v = _vertexes.begin();
	typename list<MyEdge<T> >::const_iterator it_e;
	std::tr1::unordered_map<T, int> vertex_map;
	for (int i = 0; it_v != _vertexes.end(); it_v++, i++) {
		vertex_map.insert(make_pair(it_v->_data, i));
	}
	for (it_v = _vertexes.begin(); it_v != _vertexes.end(); it_v++) {
		for (it_e = it_v->_neighbors.begin(); it_e != it_v->_neighbors.end();
				it_e++) {
			int x = vertex_map.find(it_v->_data)->second;
			int y = vertex_map.find(it_e->_connectsTo->_data)->second;
			matrix[x][y] = 1;
		}
	}
	return matrix;
}

template<class T>
inline MyVertex<T> * DirectedGraph<T>::getVertex(T label) {
	typename list<MyVertex<T> >::iterator it = _vertexes.begin();
	for (; it != _vertexes.end(); it++) {
		if (it->_data == label)
			return &(*it);
	}
	return NULL;
}

#endif /* MYGRAPH_H_ */
