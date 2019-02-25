#include <iostream>
#include <string>
#include "BTree.h"

int main() {
	BTree<int> tree;
	BTNode<int> *root = tree.insertRoot(5);
	BTNode<int> *node8 = tree.insertLeft(root, 8);
	BTNode<int> *node6 = tree.insertRight(root, 6);
	BTNode<int> *node1 = tree.insertLeft(node8, 1);
	BTNode<int> *node2 = tree.insertRight(node8, 2);
	BTNode<int> *node3 = tree.insertLeft(node6, 3);
	tree.print();
	std::cout << std::endl << "size: " << tree.size() << std::endl;
	tree.destroySubTree(node8);
	tree.print();
	std::cout << std::endl << "size: " << tree.size() << std::endl;
	tree.destroyLeft(node6);
	tree.print();
	std::cout << std::endl << "size: " << tree.size() << std::endl;
	tree.destroyTree();
	tree.print();
	std::cout << std::endl << "size: " << tree.size() << std::endl;
	std::cout << std::endl << "END";
}

