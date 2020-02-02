#include <iostream>
#include <string>
#include "Tree.h"

int main() {
	Tree<int> tree;
	TNode<int> *node5, *node8, *node6, *node4, *node9, *node11, *node1, *node15, *find;

	node5 = tree.insertRoot(5);
	node8 = tree.addChild(node5, 8);
	node6 = tree.addChild(node5, 6);
	node4 = tree.addChild(node5, 4);
	node9 = tree.addChild(node5, 9);
	node1 = tree.addChild(node8, 1);
	tree.addChild(node1, 13);
	tree.addChild(node8, 2);
	tree.addChild(node6, 3);
	tree.addChild(node4, 7);
	tree.addChild(node4, 10);
	node11 = tree.addChild(node9, 11);
	node15 = tree.addChild(node11, 15);
	tree.addChild(tree.addChild(node15, 14), 16);

	tree.print();
	std::cout << "\nTree Depth: " << tree.depth() << "\n";
	std::cout << "\nTree Width: " << tree.width() << "\n";

	std::cout << std::endl << "size: " << tree.size() << std::endl;
	tree.destroyLeafs(node4);
	tree.print();
	std::cout << std::endl << "size: " << tree.size() << std::endl;
	tree.destroySubTree(node4);
	tree.print();
	std::cout << std::endl << "size: " << tree.size() << std::endl;

	find = tree.search(9);
	tree.destroySubTree(find);
	tree.print();
	std::cout << std::endl << "size: " << tree.size() << std::endl;
	TNode<int> *node12 = tree.addChild(node8, 12);
	tree.addChild(node12, 14);
	tree.print();
	std::cout << std::endl << "size: " << tree.size() << std::endl;
	tree.destroySubTree(node8);
	tree.print();
	std::cout << std::endl << "size: " << tree.size() << std::endl;
	tree.destroyTree();
	tree.print();
	std::cout << std::endl << "size: " << tree.size() << std::endl;
	std::cout << std::endl << "END" << std::endl;
}

