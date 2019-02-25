#ifndef NODE_H_
#define NODE_H_

#include <iostream>

template<class T> class Node {

private:
	T data;
	Node<T> *next;
	Node<T> *prev;

public:
	Node();
	void writeData(T info);
	T readData();
	void setNext(Node<T> *n);
	void setPrev(Node<T> *p);
	Node<T> *getNext();
	Node<T> *getPrev();
	bool isEmpty();

};

template <class T>
bool Node<T>::isEmpty() {
	if (this->data == 0)
		return true;
	else
		return false;
}
template <class T>
Node<T>::Node() {
	this->data = T();
	this->next = nullptr;
	this->prev = nullptr;
}

template <class T>
void Node<T>::writeData(T info) {
	this->data = info;
}

template <class T>
T Node<T>::readData(){
	return this->data;
}

template <class T>
void Node<T>::setNext(Node<T> *n) {
	this->next = n;
}

template <class T>
Node<T> *Node<T>::getNext() {
	return this->next;
}

template <class T>
void Node<T>::setPrev(Node<T> *p) {
	this->prev = p;
}

template <class T>
Node<T> *Node<T>::getPrev() {
	return this->prev;
}

#endif /* NODE_H_ */
