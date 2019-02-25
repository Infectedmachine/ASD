#ifndef TREEBIN_H_
#define TREEBIN_H_

#include <iostream>
#include <string>
#include "Node.h"

template<class T>
class TreeBin {
public:
	TreeBin();
	~TreeBin();
	void insert(const T &);
	Node<T> *search(const T &);
	void destroyTree();
	void print() const;

	template<class T1>
	friend std::ostream& operator<<(std::ostream&, const TreeBin<T1>&);
private:
	Node<T> *root;
	int nodeNumbers;
	void insert(const T &, Node<T> *);
	Node<T> *search(const T &, Node<T> *);
	void destroyTree(Node<T> *);
	void print(const std::string &, const Node<T> *, bool) const;
};

template<class T>
TreeBin<T>::TreeBin() {
	this->root = nullptr;
	this->nodeNumbers = 0;
}

template<class T>
TreeBin<T>::~TreeBin() {
	this->destroyTree();
}

template<class T>
void TreeBin<T>::insert(const T &value) {
	if (this->root)
		this->insert(value, this->root);
	else {
		this->root = new Node<T>;
		this->root->setValue(value);
	}
}

template<class T>
void TreeBin<T>::insert(const T &value, Node<T> *leaf) {
	if (value < leaf->getValue()) {
		if (leaf->getLeft())
			this->insert(value, leaf->getLeft());
		else {
			Node<T> *node = new Node<T>;
			node->setValue(value);
			leaf->setLeft(node);
		}
	} else if (value > leaf->getValue()) {
		if (leaf->getRight())
			insert(value, leaf->getRight());
		else {
			Node<T> *node = new Node<T>;
			node->setValue(value);
			leaf->setRight(node);
		}
	}
}

template<class T>
Node<T> * TreeBin<T>::search(const T &value) {
	return search(value, this->root);
}

template<class T>
Node<T> * TreeBin<T>::search(const T &value, Node<T> *leaf) {
	if (leaf) {
		if (value == leaf->getValue())
			return leaf;
		if (value < leaf->getValue())
			return search(value, leaf->getLeft());
		else
			return search(value, leaf->getRight());
	} else
		return nullptr;
}

template<class T>
void TreeBin<T>::destroyTree() {
	this->destroyTree(this->root);
	this->root = nullptr;
}

template<class T>
void TreeBin<T>::destroyTree(Node<T> *leaf) {
	if (leaf) {
		this->destroyTree(leaf->getLeft());
		this->destroyTree(leaf->getRight());
		delete leaf;
	}
}

template<class T>
void TreeBin<T>::print() const{
	this->print("", this->root, false);
}
template<class T>
void TreeBin<T>::print(const std::string &prefix, const Node<T> *leaf, bool isLeft) const{
	if (leaf) {
		std::cout << prefix;
		std::cout << (isLeft ? "|--" : "'--" );
		std::cout << leaf->getValue() << std::endl;
		this->print( prefix + (isLeft ? "|   " : "   " ), leaf->getLeft(), true);
		this->print( prefix + (isLeft ? "|   " : "   " ), leaf->getRight(), false);
	}
}
template<class T>
std::ostream& operator<<(std::ostream& os, const TreeBin<T> &tree) {
	tree.print();
	return os;
}
#endif /* TREEBIN_H_ */
