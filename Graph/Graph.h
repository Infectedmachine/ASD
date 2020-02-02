#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include "linkedList.h"

template<class P, class N>
	class Arc {

public:
	N node1;
	N node2;
	P weight;
};

template<class T, class P, class N>
class Graph {
public:

	virtual bool empty() const = 0;
	virtual void insNode(N&) = 0;
	virtual void insArc(N, N, P) = 0;
	virtual void delNode(N) = 0;
	virtual void delArc(N, N) = 0;
	virtual LinkedList<N> Adjacent(N) const = 0;
	virtual LinkedList<N> nodeList() const = 0;
	virtual T readLabel(N) const = 0;
	virtual void writeLabel(N, T) = 0;
	virtual P readWeight(N,N) const = 0;
	virtual void writeWeight(N,N,P) = 0;

	virtual int numNodes() = 0;
	virtual int numArcs() = 0;

	virtual ~Graph(){};

};

#endif /* GRAPH_H_ */
