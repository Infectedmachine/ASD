#ifndef TNODE_H_
#define TNODE_H_

#include <iostream>
#include "linkedList.h"

template<class T>
class TNode {
public:
	TNode();
	T getValue() const;
	TNode<T> *getParent() const;
	LinkedList<TNode<T> *> getChilds() const;
	TNode<T> *getChildByPos(const int) const;
	void setValue(const T &);
	void setParent(TNode<T> *);
	void addChild(TNode<T> *);
	bool noChilds() const;
	int getChildsSize() const;
	void eraseLastChild();
	void eraseChild(TNode<T> *);
private:
	T value;
	TNode<T> *parent;
	LinkedList<TNode<T> *> childs;
};

template<class T>
TNode<T>::TNode() {
	this->value = T();
	this->parent = nullptr;
}

template<class T>
T TNode<T>::getValue() const {
	return this->value;
}

template<class T>
TNode<T> * TNode<T>::getParent() const {
	return this->parent;
}

template<class T>
LinkedList<TNode<T> *> TNode<T>::getChilds() const {
	return this->childs;
}

template<class T>
void TNode<T>::setValue(const T &value) {
	this->value = value;
}

template<class T>
void TNode<T>::setParent(TNode<T> *parent) {
	this->parent = parent;
}

template<class T>
void TNode<T>::addChild(TNode<T> *child) {
	this->childs.insertEnd(child);
}

template<class T>
TNode<T> * TNode<T>::getChildByPos(const int pos) const {
	return this->childs.readPosition(pos);
}

template<class T>
bool TNode<T>::noChilds() const {
	return this->childs.isEmpty();
}

template<class T>
int TNode<T>::getChildsSize() const {
	return this->childs.listLenght();
}

template<class T>
void TNode<T>::eraseLastChild() {
	this->childs.eraseLast();
}

template<class T>
void TNode<T>::eraseChild(TNode<T> *child) {
	this->childs.eraseData(child);
}
#endif /* TNODE_H_ */
