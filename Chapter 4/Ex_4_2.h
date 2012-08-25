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
#include<stack>
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
 * using @path to store a path between u and v
 */
template<class T>
bool isReachable_BFS(list<MyVertex<T> > *vertexes, T u, T v, stack<T> & path) {
	typename list<MyVertex<T> >::const_iterator it_v = vertexes->begin();
	MyVertex<T> * vertex_u;
	MyVertex<T> * vertex_v;
	for (; it_v != vertexes->end(); it_v++) {
		if(it_v->_data == u)
			MyVertex<T> * vertex_u = &(*it_v);
	}
	return false;
}

void test() {

	MyGraph<int> *mg = new DirectedGraph<int>();
	stack<int> path;
	for (int i = 0; i < 6; i++)
		mg->addVertex(i);
	mg->addEdge(0, 1);
	mg->addEdge(1, 2);
	mg->addEdge(2, 3);
	mg->addEdge(3, 1); // create a circle
	mg->addEdge(1, 4);
	mg->addEdge(4, 3); // create another circle
	mg->addEdge(4, 5);
	mg->printGraph();
	cout << "reachable? "
			<< (isReachable_DFS(mg->getGraph(), mg->size(), 0, 5, path) == 1 ?
					"TRUE" : "FALSE") << endl;
	cout << "path: 0 -> ";
	while (!path.empty()) {
		cout << path.top() << (path.size() > 1 ? " -> " : "");
		path.pop();
	}

}

#endif /* EX_4_2_H_ */
