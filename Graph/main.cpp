#include "GraphList.h"
#include <string>

using namespace std;

int main() {
	GraphList<string, double> graph(10);
	GNode n1, n2, n3, n4, n5, n6;

	graph.insNode(n1);
	graph.writeLabel(n1, "a");
	graph.insNode(n2);
	graph.writeLabel(n2, "b");
	graph.insNode(n3);
	graph.writeLabel(n3, "c");
	graph.insNode(n4);
	graph.writeLabel(n4, "d");
	graph.insNode(n5);
	graph.writeLabel(n5, "e");
	graph.insNode(n6);
	graph.writeLabel(n6, "f");

	graph.insArc(n1,n2, 1.0);
	graph.insArc(n1,n3, 2.0);
	graph.insArc(n1,n5, 3.0);
	graph.insArc(n2,n4, 4.0);
	graph.insArc(n2, n6, 5.0);
	graph.insArc(n3, n4, 1.0);
	graph.insArc(n3, n6, 2.0);
	graph.insArc(n4, n1, 3.0);
	graph.insArc(n5, n2, 4.0);
	graph.insArc(n5, n3, 5.0);
	graph.insArc(n6, n4, 1.0);

	cout << "\nNumNodes: " << graph.numNodes();
	cout << "\nNumArcs: "  << graph.numArcs();

	graph.delNode(n6);
	cout << "\nNumNodes: " << graph.numNodes();
	cout << "\nID n2, n3, n4: " << n2.getId() << " " << n3.getId() << " " << n4.getId();

	cout << "\n Adjacent of: " << graph.readLabel(n1) << " --> ";
	LinkedList<GNode> list = graph.Adjacent(n1);
	for (int i = 1; i <= list.listLenght(); i++)
		cout << graph.readLabel(list.readPosition(i)) << " ";
	LinkedList<InfoArc<double>> path = graph.pathList(n1,n4);
	if (path.listLenght()) {
		cout << "\n Path Exist: ";
		for (int i = 1; i <= path.listLenght(); i++)
			cout << "\n" << "Peso: " << path.readPosition(i).weight << " to: " << path.readPosition(i)._to.getId()+1;
	}
}


