#ifndef PILE_H_
#define PILE_H_

#include <iostream>
#include "linkedList.h"

template<class T> class Pile {
private:
	LinkedList<T> list;
	int lenght;
	int maxSize;

public:
	Pile(int);
	~Pile();
	bool isEmpty();
	void push(const T data);
	T pull();
	T readTop();
	int pileSize();

	template<class T1>
	friend std::ostream& operator<<(std::ostream&, Pile<T1>&);
};

template<class T>
Pile<T>::Pile(int size) {
	this->lenght = 0;
	this->maxSize = size;
}

template<class T>
Pile<T>::~Pile() {
	this->list.~LinkedList();
	this->lenght = 0;
	this->maxSize = 0;
}

template<class T>
bool Pile<T>::isEmpty() {
	if (this->lenght)
		return false;
	else
		return true;
}

template<class T>
void Pile<T>::push(const T data) {
	if (this->maxSize > this->lenght) {
		this->list.insertEnd(data);
		this->lenght++;
	}
}

template<class T>
T Pile<T>::pull() {
	if (this->isEmpty())
		return T();
	else {
		T data = this->list.readLast();
		this->list.eraseLast();
		this->lenght--;
		return data;
	}
}

template<class T>
int Pile<T>::pileSize() {
	return this->lenght;
}

template<class T>
T Pile<T>::readTop() {
	return this->list.readLast();
}

template<class T>
std::ostream& operator<<(std::ostream& os, Pile<T> &pile) {
	std::cout << "[TOP]" << std::endl;
	while (pile.lenght)
		std::cout << pile.pull() << std::endl;
	std::cout << "[BOTTOM]" << std::endl;
	return os;
}

#endif /* PILE_H_ */
