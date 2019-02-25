#ifndef BTREE_H_
#define BTREE_H_

#include <iostream>
#include <string>
#include "BTNode.h"

template<class T>
class BTree {
public:
	BTree();
	~BTree();
	BTNode<T> *insertRoot(const T &);
	BTNode<T> *insertLeft(BTNode<T> *, const T &);
	BTNode<T> *insertRight(BTNode<T> *, const T &);
	void destroyTree();
	void destroySubTree(BTNode<T> *);
	void destroyLeft(BTNode<T> *);
	void destroyRight(BTNode<T> *);
	bool isEmpty() const;
	int size() const;
	void print() const;
private:
	BTNode<T> *root;
	int treeSize;
	void print(const std::string &, const BTNode<T> *, bool) const;
	void destroyLeafs(BTNode<T> *);
};

template<class T>
BTree<T>::BTree() {
	this->root = nullptr;
	this->treeSize = 0;
}

template<class T>
BTree<T>::~BTree() {
	this->destroyTree();
	this->treeSize = 0;
}

template<class T>
BTNode<T> * BTree<T>::insertRoot(const T &value) {
	if (!this->root) {
		this->root = new BTNode<T>;
		this->root->setValue(value);
		this->treeSize++;
		return this->root;
	}
	return nullptr;
}

template<class T>
BTNode<T> * BTree<T>::insertLeft(BTNode<T> *node, const T &value) {
	if (node && this->root && !node->getLeft()) {
		BTNode<T> *newNode = new BTNode<T>;
		newNode->setValue(value);
		newNode->setParent(node);
		node->setLeft(newNode);
		this->treeSize++;
		return newNode;
	}
	return nullptr;
}

template<class T>
BTNode<T> * BTree<T>::insertRight(BTNode<T> *node, const T &value) {
	if (node && this->root && !node->getRight()) {
		BTNode<T> *newNode = new BTNode<T>;
		newNode->setValue(value);
		newNode->setParent(node);
		node->setRight(newNode);
		this->treeSize++;
		return newNode;
	}
	return nullptr;
}

template<class T>
bool BTree<T>::isEmpty() const {
	if (!this->root)
		return true;
	else
		return false;
}

template<class T>
int BTree<T>::size() const {
	return this->treeSize;
}

template<class T>
void BTree<T>::destroyTree() {
	this->destroyLeafs(this->root);
	delete this->root;
	this->root = nullptr;
	this->treeSize = 0;
}

template<class T>
void BTree<T>::destroySubTree(BTNode<T> *node) {
	if (node) {
		this->destroyLeft(node);
		this->destroyRight(node);
		BTNode<T> *father = node->getParent();
		if (father) {
			if (node == father->getLeft()) {
				father->setLeft(nullptr);
				delete node;
				this->treeSize--;
			} else if (node == father->getRight()) {
				father->setRight(nullptr);
				delete node;
				this->treeSize--;
			}
		} else
			this->destroyTree();
	}
}

template<class T>
void BTree<T>::destroyLeafs(BTNode<T> *node) {
	if (node) {
		this->destroyLeafs(node->getLeft());
		this->destroyLeafs(node->getRight());
		delete node;
		this->treeSize--;
	}
}

template<class T>
void BTree<T>::destroyLeft(BTNode<T> *node) {
	if (node) {
		this->destroyLeafs(node->getLeft());
		node->setLeft(nullptr);
	}
}

template<class T>
void BTree<T>::destroyRight(BTNode<T> *node) {
	if (node) {
		this->destroyLeafs(node->getRight());
		node->setRight(nullptr);
	}
}

template<class T>
void BTree<T>::print() const {
	if (this->root)
		this->print("", this->root, false);
	else
		std::cout << "[]" << std::endl;
}
template<class T>
void BTree<T>::print(const std::string &prefix, const BTNode<T> *leaf,
		bool isLeft) const {
	if (leaf) {
		std::cout << prefix;
		std::cout << (isLeft ? "|--" : "'--");
		std::cout << leaf->getValue() << std::endl;
		this->print(prefix + (isLeft ? "|   " : "   "), leaf->getLeft(), true);
		this->print(prefix + (isLeft ? "|   " : "   "), leaf->getRight(),
				false);
	}
}
#endif /* BTREE_H_ */
