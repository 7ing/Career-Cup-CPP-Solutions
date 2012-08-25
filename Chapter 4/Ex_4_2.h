/*
 * Ex_4_2.h
 *
 *  Created on: Aug 21, 2012
 *      Author: jliu
 */

/*
 * Given a directed graph, design an algorithm to find out
 * whether there is a route between two nodes.
 */

#ifndef EX_4_2_H_
#define EX_4_2_H_

#include<iostream>
#include<cstdlib>
#include<stack>
#include<queue>
#include"../My Lib/MyGraph.h"
using namespace std;

/*
 * DFS method
 * Matrix expression: O(n^2) time
 * using @path to store a path between u and v
 * NOTE: it will change adjacencyMatrix
 */
bool isReachable_DFS(int ** adjacencyMatrix, int size, int u, int v,
		stack<int> & path) {
	if (u < 0 || v < 0 || u >= size || v >= size) {
		cout << "No such vertex." << endl;
		return false;
	}

	if (adjacencyMatrix[u][v]) {
		path.push(v);
		return true;
	}

	for (int i = 0; i < size; i++) {
		if (adjacencyMatrix[u][i] == 1) { // for all unexplored adjacent vertex
			adjacencyMatrix[u][i] = -1; // mark visited
			if (isReachable_DFS(adjacencyMatrix, size, i, v, path)) {
				path.push(i);
				return true;
			}
		} else if (adjacencyMatrix[u][i] == -1)
			return false; // already visited, do not explore further node via this vertex
	}

	return false;
}

/*
 * BFS method
 * Linked List expression: O(n+e) time   -- e: # of edges
 */
template<class T>
bool isReachable_BFS(list<MyVertex<T> > vertexes, T u, T v) {
	typename list<MyVertex<T> >::iterator it_v = vertexes.begin();
	MyVertex<T> * vertex_u = NULL;
	MyVertex<T> * vertex_v = NULL;
	for (; it_v != vertexes.end(); it_v++) {
		if (it_v->_data == u)
			vertex_u = &(*it_v);
		if (it_v->_data == v)
			vertex_v = &(*it_v);
	}
	if (!vertex_u || !vertex_v) {
		cout << "No such vertex." << endl;
		return false;
	}

	queue<MyVertex<T> *> visit;
	visit.push(vertex_u);

	while (!visit.empty()) {
		vertex_u = visit.front();
		visit.pop();
		if (vertex_u->_isVisit)
			continue;
		else
			vertex_u->_isVisit = true;
		if (vertex_u->_data == vertex_v->_data)
			return true;
		typename list<MyEdge<T> >::iterator it_e =
				(vertex_u->_neighbors).begin();
		while (it_e != (vertex_u->_neighbors).end()) {
			if (it_e->_connectsTo->_isVisit == false)
				visit.push(it_e->_connectsTo);
			it_e++;
		}
	}

	return false;
}

void test() {

	MyGraph<char> *mg = new DirectedGraph<char>();
	stack<int> path;
	for (int i = 0; i < 6; i++)
		mg->addVertex('A' + i);
	mg->addEdge('A', 'B');
	mg->addEdge('B', 'C');
	mg->addEdge('C', 'D');
	mg->addEdge('D', 'B'); // create a circle
	mg->addEdge('B', 'E');
	mg->addEdge('E', 'D'); // create another circle
	mg->addEdge('E', 'F');
	mg->printGraph();
	cout << "reachable? DFS: "
			<< (isReachable_DFS(mg->getGraph(), mg->size(), 0, 5, path) == 1 ?
					"TRUE" : "FALSE") << endl;
	cout << "path: A -> ";
	while (!path.empty()) {
		cout << (char) ('A' + path.top()) << (path.size() > 1 ? " -> " : "");
		path.pop();
	}
	cout << endl;

	cout << "reachable? BFS: "
			<< (isReachable_BFS(
					dynamic_cast<DirectedGraph<char> *>(mg)->getGraphList(),
					'A', 'F') == 1 ? "TRUE" : "FALSE") << endl;

}

#endif /* EX_4_2_H_ */
