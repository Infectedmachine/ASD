#include <iostream>
#include <string>
#include "Tree.h"

int main() {
	Tree<int> tree;
	TNode<int> *node5, *node8, *node6, *node4, *node9, *find;

	node5 = tree.insertRoot(5);
	node8 = tree.addChild(node5, 8);
	node6 = tree.addChild(node5, 6);
	node4 = tree.addChild(node5, 4);
	node9 = tree.addChild(node5, 9);
	tree.addChild(node8, 1);
	tree.addChild(node8, 2);
	tree.addChild(node6, 3);
	tree.addChild(node4, 7);
	tree.addChild(node4, 10);
	tree.addChild(node9, 11);

	tree.print();

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

