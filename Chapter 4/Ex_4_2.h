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
 */
bool isReachable(int ** adjacencyMatrix, int size, int u, int v,
		stack<int> & path) {
	if (u < 0 || v < 0 || u >= size || v >= size) {
		cout << "No such vertex." << endl;
		return false;
	}

	if (adjacencyMatrix[u][v]) {
		path.push(v);
		return true;
	}

	bool check = false;

	for (int i = 0; i < size; i++) {
		if (adjacencyMatrix[u][i] == 1) {
			adjacencyMatrix[u][i] = -1;
			check = isReachable(adjacencyMatrix, size, i, v, path);
			if (check)
				path.push(i);
		} else if(adjacencyMatrix[u][i] == -1) {
			return false; // encounter a circle, get back
		}
	}

	return check;
}

void test() {

	MyGraph<int> *mg = new DirectedGraph<int>();
	stack<int> path;
	for (int i = 0; i < 5; i++)
		mg->addVertex(i);
	mg->addEdge(0, 1);
	mg->addEdge(1, 2);
	mg->addEdge(2, 3);
	mg->addEdge(3, 1); // create a circle
	mg->addEdge(2, 4);
	mg->printGraph();
	cout << "reachable? "<<isReachable(mg->getGraph(), mg->size(), 0, 4, path)<<endl;
	cout << "path: 0 -> ";
	while(!path.empty()) {
		cout<<path.top()<<" -> ";
		path.pop();
	}

}

#endif /* EX_4_2_H_ */
