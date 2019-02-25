#include <iostream>
#include <string>
#include "TreeBin.h"

int main() {
	TreeBin<int> tree;
	tree.insert(8);
	tree.insert(5);
	tree.insert(10);
	tree.insert(2);
	tree.insert(6);
	tree.insert(9);
	tree.insert(11);
	std::cout << tree;
	tree.destroyTree();
	std::cout << tree;
	std::cout << "END" << std::endl;

	TreeBin<std::string> treeString;
	treeString.insert("root");
	treeString.insert("hello");
	treeString.insert("world");
	treeString.insert("from");
	treeString.insert("the");
	treeString.insert("other");
	treeString.insert("side");
	std::cout << treeString;
	std::cout << "END" << std::endl;
}

