#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
#include "node.h"

template<class T> class LinkedList {
private:
	Node<T> *head;
	int lenght;
	Node<T> *newNode(const T data);
	Node<T> *getHead() const;
	void setHead(Node<T> *h);
	void incrementLenght();
	Node<T> *getLastNode() const;

public:
	LinkedList();
	LinkedList(const LinkedList<T>&);
	~LinkedList();
	void insertFirst(const T data);
	void insertEnd(const T data);
	void insertInPosition(const T data, int p);
	T readPosition(int p) const;
	T readFirst() const;
	T readLast() const;
	void eraseFirst();
	void eraseLast();
	void eraseInPosition(int p);
	void eraseData(const T);
	bool isEmpty() const;
	int listLenght() const;
	bool checkData(const T) const;
	int getDatasPosition(const T) const;
	void swap(LinkedList<T>&);
	void appendList(const LinkedList<T>&);

	template<class T1>
	friend std::ostream& operator<<(std::ostream&, const LinkedList<T1>&);
	LinkedList<T>& operator=(const LinkedList<T>&);
	bool operator==(const LinkedList<T>&);
	LinkedList<T> operator+(const LinkedList<T>&);
	LinkedList<T>& operator+=(const LinkedList<T>&);

};

template<class T>
LinkedList<T>::LinkedList() {
	this->head = nullptr;
	this->lenght = 0;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &list) {
	if (list.isEmpty()) {
		this->setHead(nullptr);
		this->lenght = 0;
	} else {
		this->setHead(this->newNode(list.readFirst()));
		Node<T> *pilotList = list.head;
		while (pilotList->getNext()) {
			pilotList = pilotList->getNext();
			this->insertEnd(pilotList->readData());
		}
	}
	this->lenght = list.listLenght();
}

template<class T>
LinkedList<T>::~LinkedList() {
	Node<T> *pilot = this->getHead();
	Node<T> *next = nullptr;
	while (pilot) {
		next = pilot->getNext();
		delete pilot;
		pilot = next;
	}
	this->setHead(nullptr);
	this->lenght = 0;
}

template<class T>
void LinkedList<T>::insertFirst(const T data) {
	Node<T> *node = newNode(data);
	if (this->isEmpty()) {
		this->setHead(node);
		this->incrementLenght();
	} else {
		node->setNext(this->getHead());
		this->getHead()->setPrev(node);
		this->setHead(node);
		this->incrementLenght();
	}
}

template<class T>
int LinkedList<T>::listLenght() const {
	return this->lenght;
}

template<class T>
void LinkedList<T>::setHead(Node<T> *h) {
	this->head = h;
}

template<class T>
Node<T> *LinkedList<T>::getHead() const {
	return this->head;
}

template<class T>
Node<T> *LinkedList<T>::getLastNode() const {
	if (this->isEmpty())
		return nullptr;
	else {
		Node<T> *pilot = this->getHead();
		while (pilot->getNext())
			pilot = pilot->getNext();
		return pilot;
	}
}

template<class T>
bool LinkedList<T>::isEmpty() const {
	if (this->listLenght())
		return false;
	else
		return true;
}

template<class T>
void LinkedList<T>::insertEnd(const T data) {
	Node<T> *node = newNode(data);

	if (this->isEmpty()) {
		this->setHead(node);
		this->incrementLenght();
	} else {
		Node<T> *pilot = this->getHead();
		while (pilot->getNext()) {
			pilot = pilot->getNext();
		}
		node->setPrev(pilot);
		pilot->setNext(node);
		this->incrementLenght();
	}
}

template<class T>
Node<T> *LinkedList<T>::newNode(const T data) {
	Node<T> *newNode = new Node<T>;
	newNode->writeData(data);
	return newNode;
}

template<class T>
T LinkedList<T>::readPosition(int pos) const {
	Node<T> *pilot = this->getHead();
	if (this->isEmpty() || pos > this->listLenght())
		return T();
	else {
		while (--pos > 0) {
			pilot = pilot->getNext();
		}
		return pilot->readData();
	}
}

template<class T>
void LinkedList<T>::insertInPosition(const T data, int pos) {
	if (this->isEmpty() || pos == 0)
		this->insertFirst(data);
	else {
		if (pos > this->listLenght())
			this->insertEnd(data);
		else {
			Node<T> *pilot = this->getHead();
			while (--pos > 0) {
				pilot = pilot->getNext();
			}
			Node<T> *node = newNode(data);
			node->setNext(pilot);
			node->setPrev(pilot->getPrev());
			Node<T> *prev = pilot->getPrev();
			prev->setNext(node);
			pilot->setPrev(node);
			this->incrementLenght();
		}
	}

}

template<class T>
void LinkedList<T>::incrementLenght() {
	this->lenght++;
}

template<class T>
T LinkedList<T>::readFirst() const {
	if (this->isEmpty())
		return T();
	else
		return this->getHead()->readData();
}

template<class T>
T LinkedList<T>::readLast() const {
	Node<T> *pilot = this->getHead();
	if (this->isEmpty())
		return T();
	else {
		while (pilot->getNext())
			pilot = pilot->getNext();
		return pilot->readData();
	}
}

template<class T>
void LinkedList<T>::eraseFirst() {
	if (this->isEmpty()) {
	} else {
		Node<T> *pilot = this->getHead();
		Node<T> *next = pilot->getNext();
		if (next) {
			next->setPrev(nullptr);
			this->setHead(next);
		} else
			this->setHead(nullptr);

		delete pilot;
		this->lenght--;
	}
}

template<class T>
void LinkedList<T>::eraseLast() {
	if (this->isEmpty()) {
	} else {
		Node<T> *pilot = this->getLastNode();
		Node<T> *prev = pilot->getPrev();
		if (prev)
			prev->setNext(nullptr);
		else
			this->setHead(nullptr);
		delete pilot;
		this->lenght--;
	}
}

template<class T>
void LinkedList<T>::eraseInPosition(int pos) {
	if (this->isEmpty() || pos > this->listLenght() || pos == 0) {
	} else {
		if (pos == this->listLenght())
			this->eraseLast();
		else if (pos == 1)
			this->eraseFirst();
		else {
			Node<T> *pilot = this->getHead();
			while (--pos > 0) {
				pilot = pilot->getNext();
			}
			Node<T> *prev = pilot->getPrev();
			Node<T> *next = pilot->getNext();
			prev->setNext(next);
			next->setPrev(prev);
			delete pilot;
			this->lenght--;
		}
	}
}

template<class T>
int LinkedList<T>::getDatasPosition(const T data) const {
	int dataPosition = 0;
	if (this->checkData(data)) {
		Node<T> *pilot = this->getHead();
		bool found = false;
		while (pilot && !found) {
			dataPosition++;
			if (pilot->readData() == data)
				found = true;
			else
				pilot = pilot->getNext();
		}
		if (found)
			return dataPosition;
		else
			dataPosition = 0;
	}
	return dataPosition;
}

template<class T>
bool LinkedList<T>::checkData(const T data) const {
	if (this->isEmpty())
		return false;
	else {
		Node<T> *pilot = this->getHead();
		bool found = false;
		while (pilot && !found) {
			if (pilot->readData() == data)
				found = true;
			else
				pilot = pilot->getNext();
		}
		return found;
	}
}

template<class T>
void LinkedList<T>::eraseData(const T data) {
	if (this->checkData(data)) {
		int position = this->getDatasPosition(data);
		this->eraseInPosition(position);
	}
}

template<class T>
void LinkedList<T>::swap(LinkedList<T> &list) {
	Node<T> *headList = list.getHead();
	int listSize = list.lenght;
	list.setHead(this->getHead());
	this->setHead(headList);
	list.lenght = this->lenght;
	this->lenght = listSize;
}

template<class T>
void LinkedList<T>::appendList(const LinkedList<T> &list) {
	Node<T> *pilot = list.getHead();
	while (pilot) {
		this->insertEnd(pilot->readData());
		pilot = pilot->getNext();
	}
}

template<class T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T> &list) {
	Node<T> *pilot = list.getHead();

	std::cout << "[";
	while (pilot) {
		std::cout << pilot->readData();
		pilot = pilot->getNext();
		if (pilot)
			std::cout << ",";
	}
	std::cout << "]";
	std::cout << std::endl;

	return os;
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T> &list) {
	LinkedList<T> tmp(list);
	this->swap(tmp);
	return *this;
}

template<class T>
bool LinkedList<T>::operator==(const LinkedList<T> &list) {
	bool equals = true;
	Node<T> *pilot = list.getHead();
	Node<T> *pilotCurrentObj = this->getHead();
	if (this->isEmpty() || list.isEmpty())
		return false;
	else {
		while (equals && pilotCurrentObj && pilot) {
			if (pilotCurrentObj->readData() != pilot->readData())
				equals = false;
			else {
				pilotCurrentObj = pilotCurrentObj->getNext();
				pilot = pilot->getNext();
			}
		}
	}
	if (!pilotCurrentObj && !pilot) {
	} else
		equals = false;

	return equals;
}

template<class T>
LinkedList<T>& LinkedList<T>::operator+=(const LinkedList<T> &list) {
	Node<T> *pilot = list.getHead();
	while (pilot) {
		this->insertEnd(pilot->readData());
		pilot = pilot->getNext();
	}
	return *this;
}

template<class T>
LinkedList<T> LinkedList<T>::operator+(const LinkedList<T> &list) {
	LinkedList<T> tmp = *this;
	tmp += list;
	return tmp;

}
#endif /* LINKEDLIST_H_ */
