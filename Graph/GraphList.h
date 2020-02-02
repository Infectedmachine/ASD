#ifndef GRAPHLIST_H_
#define GRAPHLIST_H_

#include "Graph.h"
#include "coda.h"

class GNode {
private:
	int nodeId;
public:
	GNode(int id) {
		nodeId = id;
	}
	GNode() {
		nodeId = 0;
	}
	int getId() {
		return nodeId;
	}
	void setId(int id) {
		nodeId = id;
	}
};

template<class P>
class InfoArc {
public:
	P weight;
	GNode _to;
};

template<class E, class P>
class InfoNode {
public:
	E label;
	bool empty;
	void * info;
	LinkedList<InfoArc<P>> arcs;

	InfoNode() {
		empty = true;
		info = 0;
	}
};

template<class E, class P>
class GraphList : public Graph<E,P, GNode> {
private:
	InfoNode<E,P> *matrix;
	int dim;
	int nodes;
	int arcs;
	bool getPathList(GNode, GNode, LinkedList<int> &, LinkedList<InfoArc<P>> &);

public:
	GraphList(int);
	~GraphList();

	bool empty() const;
	void insNode(GNode &);
	void insArc(GNode, GNode, P);
	void delNode(GNode);
	void delArc(GNode, GNode);
	LinkedList<GNode> Adjacent(GNode) const;
	LinkedList<GNode> nodeList() const;
	E readLabel(GNode) const;
	void writeLabel(GNode, E);
	P readWeight(GNode, GNode) const;
	void writeWeight(GNode, GNode, P);
	LinkedList<InfoArc<P>> pathList(GNode, GNode);

	int numNodes() {
		return this->nodes;
	}
	int numArcs() {
		return this->arcs;
	}

};

template<class E, class P>
GraphList<E,P>::GraphList(int dim) {
	this->dim = dim;
	this->nodes = 0;
	this->arcs = 0;
	this->matrix = new InfoNode<E,P>[dim];
}

template<class E, class P>
GraphList<E,P>::~GraphList() {
	delete [] matrix;
}

template<class E, class P>
bool GraphList<E, P>::empty() const {
	return (nodes == 0);
}

template<class E, class P>
void GraphList<E,P>::insNode(GNode &node) {
	int n = 0;
	if (this->nodes < this->dim) {
		while (this->matrix[n].empty == false)
			n++;
		this->nodes++;
		this->matrix[n].empty = false;
	}
	node.setId(n);
}

template<class E, class P>
void GraphList<E,P>::insArc(GNode node1, GNode node2, P weight) {
	InfoArc<P> info;
	info.weight = weight;
	info._to = node2;
	this->matrix[node1.getId()].arcs.insertEnd(info);
	this->arcs++;
}

template<class E, class P>
void GraphList<E, P>::delNode(GNode node) {
	bool del = true;
	int i;
	if (!matrix[node.getId()].arcs.isEmpty())
		del = false;
	for (i = 0; i < dim && del; i++) {
		if (!matrix[i].empty){
			int listLenght = matrix[i].arcs.listLenght();
			for (int j = 1; j <= listLenght; j++)
				if (matrix[i].arcs.readPosition(j)._to.getId() == node.getId())
					del = false;
		}
	}
	if (del){
		matrix[node.getId()].empty = true;
		this->nodes--;
	}

}

template<class E, class P>
void GraphList<E,P>::delArc(GNode node1, GNode node2) {
	if (!matrix[node1.getId()].empty && !matrix[node2.getId()].empty) {
		int listLenght = matrix[node1.getId()].arcs.listLenght();
		int found = false;
		for (int j = 1; j <= listLenght && !found; j++)
			if (matrix[node1.getId()].arcs.readPosition(j)._to.getId() == node2.getId()){
				found = true;
				matrix[node1.getId()].arcs.eraseInPosition(j);
				this->arcs--;
			}
	}
}

template<class E, class P>
LinkedList<GNode> GraphList<E,P>::Adjacent(GNode node) const{
	LinkedList<GNode> nodesList;
	if (!matrix[node.getId()].empty) {
		int listLenght = matrix[node.getId()].arcs.listLenght();
		for (int j = 1; j <= listLenght; j++) {
			GNode gnode = matrix[node.getId()].arcs.readPosition(j)._to;
			nodesList.insertEnd(gnode);
		}
	}
	return nodesList;
}

template<class E, class P>
LinkedList<GNode> GraphList<E,P>::nodeList() const {
	LinkedList<GNode> list;
	for (int i = 0; i < dim; i++)
		if (!matrix[i].empty){
			GNode newNode(i);
			list.insertEnd(newNode);
		}
	return list;
}

template<class E, class P>
void GraphList<E,P>::writeLabel(GNode node, E label) {
	if (!matrix[node.getId()].empty)
		this->matrix[node.getId()].label = label;
}

template<class E, class P>
E GraphList<E,P>::readLabel(GNode node) const {
	if (!matrix[node.getId()].empty)
		return this->matrix[node.getId()].label;
	return E();
}

template<class E, class P>
P GraphList<E,P>::readWeight(GNode node1, GNode node2) const {
	if (!matrix[node1.getId()].empty && !matrix[node2.getId()].empty) {
		int listLenght = matrix[node1.getId()].arcs.listLenght();
			for (int j = 1; j <= listLenght; j++) {
				if (matrix[node1.getId()].arcs.readPosition(j)._to.getId() == node2.getId())
					return matrix[node1.getId()].arcs.readPosition(j).weight;
			}
	}
	return P();
}

template<class E, class P>
void GraphList<E,P>::writeWeight(GNode node1, GNode node2, P weight) {
	if (!matrix[node1.getId()].empty && !matrix[node2.getId()].empty) {
			int listLenght = matrix[node1.getId()].arcs.listLenght();
				for (int j = 1; j <= listLenght; j++) {
					if (matrix[node1.getId()].arcs.readPosition(j)._to.getId() == node2.getId()) {
						InfoArc<P> info;
						info.weight = weight;
						info._to = node2;
						matrix[node1.getId()].arcs.eraseInPosition(j);
						matrix[node1.getId()].arcs.insertInPosition(info, j);
					}
				}
	}
}

template<class E, class P>
LinkedList<InfoArc<P>> GraphList<E,P>::pathList(GNode node1, GNode node2) {
	LinkedList<InfoArc<P>> list;
	LinkedList<int> visited;

	getPathList(node1, node2, visited, list);
	return list;
}

template<class E, class P>
bool GraphList<E,P>::getPathList(GNode node1, GNode node2, LinkedList<int> &visited, LinkedList<InfoArc<P>> &list) {
	visited.insertEnd(node1.getId());
	bool found = false;

	if (node1.getId() == node2.getId())
		return true;
	else {
		for (int i = 1; i <= matrix[node1.getId()].arcs.listLenght() && !found; i++)
			if (!visited.checkData(matrix[node1.getId()].arcs.readPosition(i)._to.getId())) {
				list.insertEnd(matrix[node1.getId()].arcs.readPosition(i));
				found = getPathList(matrix[node1.getId()].arcs.readPosition(i)._to, node2, visited, list);
			}
	}
	if (found)
		return true;
	else {
		list.eraseLast();
		return false;
	}
}

#endif /* GRAPHLIST_H_ */
