#ifndef TREE_H_
#define TREE_H_

#include <iostream>
#include <string>
#include "TNode.h"
#include "Coda.h"

template<class T>
class Tree {
public:
	Tree();
	Tree(const Tree &);
	~Tree();
	TNode<T> *insertRoot(const T &);
	TNode<T> *addChild(TNode<T> *, const T &);
	TNode<T> *search(const T &);
	void destroyTree();
	void destroySubTree(TNode<T> *);
	void destroyLeafs(TNode<T> *);
	bool isEmpty() const;
	int size() const;
	void print() const;
	unsigned int depth() const;
	unsigned int width() const;

private:
	TNode<T> *root;
	int treeSize;
	TNode<T> *search(const T &, TNode<T> *);
	void print(const std::string &, const TNode<T> *, bool) const;
	unsigned int _depth(TNode<T> *, unsigned int) const;
	unsigned int _width(TNode<T> *, unsigned int) const;
};

template<class T>
Tree<T>::Tree() {
	this->root = nullptr;
	this->treeSize = 0;
}

template<class T>
Tree<T>::~Tree() {
	this->destroyTree();
	this->treeSize = 0;
}

template<class T>
TNode<T> * Tree<T>::insertRoot(const T &value) {
	if (!this->root) {
		this->root = new TNode<T>;
		root->setValue(value);
		this->treeSize++;
		return this->root;
	}
	return nullptr;
}

template<class T>
TNode<T> * Tree<T>::addChild(TNode<T> *node, const T &value) {
	if (node && this->root) {
		TNode<T> *newNode = new TNode<T>;
		newNode->setValue(value);
		newNode->setParent(node);
		node->addChild(newNode);
		this->treeSize++;
		return newNode;
	}
	return nullptr;
}

template<class T>
TNode<T> * Tree<T>::search(const T &value) {
	return search(value, this->root);
}

template<class T>
TNode<T> * Tree<T>::search(const T &value, TNode<T> *node) {
	if (node) {
		if (value == node->getValue())
			return node;
		else {
			if (!node->noChilds())
				for (int i = 0; i < node->getChildsSize(); i++) {
					TNode<T> *find = this->search(value,
							node->getChildByPos(i + 1));
					if (find)
						return find;
				}
			return nullptr;
		}
	} else
		return nullptr;
}

template<class T>
void Tree<T>::destroyTree() {
	this->destroyLeafs(this->root);
	delete this->root;
	this->root = nullptr;
	this->treeSize = 0;
}

template<class T>
void Tree<T>::destroySubTree(TNode<T> *node) {
	if (node) {
		if (!node->noChilds()) {
			this->destroyLeafs(node);
		}
		TNode<T> *father = node->getParent();
		if (father) {
			father->eraseChild(node);
			this->treeSize--;
		}
		else
			this->destroyTree();
	}
}

template<class T>
void Tree<T>::destroyLeafs(TNode<T> *node) {
	if (node) {
		if (!node->noChilds()) {
			for (int i = node->getChildsSize(); i > 0; i--) {
				this->destroyLeafs(node->getChildByPos(i));
				node->eraseLastChild();
				this->treeSize--;
			}
		}
	}
}

template<class T>
bool Tree<T>::isEmpty() const {
	if (this->treeSize)
		return false;
	else
		return true;
}

template<class T>
int Tree<T>::size() const {
	return this->treeSize;
}

template<class T>
void Tree<T>::print() const {
	if (this->root)
		this->print("", this->root, true);
	else
		std::cout << "[]" << std::endl;
}

template<class T>
void Tree<T>::print(const std::string &prefix, const TNode<T> *node,
		bool isLast) const {
	if (node) {
		std::cout << prefix;
		std::cout << (isLast ? "'--" : "|--");
		std::cout << node->getValue() << std::endl;
		if (!node->noChilds())
			for (int i = 0; i < node->getChildsSize(); i++) {
				if (i == node->getChildsSize() - 1)
					this->print(prefix + (isLast ? "   " : "|  "),
							node->getChildByPos(i + 1), true);
				else
					this->print(prefix + (isLast ? "   " : "|  "),
							node->getChildByPos(i + 1), false);
			}
	}
}

template<class T>
unsigned int Tree<T>::depth() const {
	if (this->isEmpty())
		return 0;
	else
		return _depth(this->root, 0) - 1;
}

template<class T>
unsigned int Tree<T>::_depth(TNode<T> *node, unsigned int d) const {
	unsigned int depth = d;

	for(int i = 1; i <= node->getChildsSize(); i++) {
		unsigned int childDepth = _depth(node->getChildByPos(i), d);
		if (childDepth > depth)
			depth = childDepth;
	}
	return depth + 1;
}

template<class T>
unsigned int Tree<T>::width() const {
	if (this->isEmpty())
		return 0;
	else
		return _width(this->root, 1);
}

template<class T>
unsigned int Tree<T>::_width(TNode<T> *node, unsigned int w) const {
	unsigned int width = w;

	Coda<TNode<T>*> queue(100);
	queue.push(node);

	while(!queue.isEmpty()) {
		unsigned int w1 = queue.sizeCoda();
		if (w1 > width)
			width = w1;

		unsigned int j = 0;
		while (j < w1) {
			for (int i = 1; i <= queue.readTop()->getChildsSize(); i++)
				queue.push(queue.readTop()->getChildByPos(i));
			queue.pull();
			j++;
		}
	}
	return width;
}
#endif /* TREE_H_ */
