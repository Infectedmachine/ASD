#ifndef INSIEME_H_
#define INSIEME_H_

#include <iostream>
#include "linkedList.h"

template<class T> class Insieme {
private:
	LinkedList<T> list;
	int lenght;
	int maxSize;
	T readListPosition(int p) const;

public:
	Insieme();
	Insieme(int);
	Insieme(const Insieme<T>&);
	~Insieme();
	bool isEmpty() const;
	bool checkElement(const T) const;
	void insertElement(const T);
	void eraseElement(const T);
	Insieme<T>& Union(const Insieme<T>);
	Insieme<T>& Intersection(const Insieme<T>);
	Insieme<T>& Difference(const Insieme<T>);
	int sizeInsieme() const;

	template<class T1>
	friend std::ostream& operator<<(std::ostream&, Insieme<T1>&);
};

template<class T>
Insieme<T>::Insieme() {
	this->lenght = 0;
	this->maxSize = 0;
}

template<class T>
Insieme<T>::Insieme(int size) {
	this->lenght = 0;
	this->maxSize = size;
}

template<class T>
Insieme<T>::Insieme(const Insieme<T> &insieme) {
	this->maxSize = insieme.maxSize;
	this->lenght = 0;
	for (int i = 0; i < insieme.sizeInsieme(); i++) {
		this->list.insertEnd(insieme.readListPosition(i + 1));
	}
	this->lenght = insieme.lenght;
}

template<class T>
Insieme<T>::~Insieme() {
	this->list.~LinkedList();
	this->lenght = 0;
	this->maxSize = 0;
}

template<class T>
bool Insieme<T>::isEmpty() const {
	if (this->lenght)
		return false;
	else
		return true;
}

template<class T>
bool Insieme<T>::checkElement(const T data) const {
	return this->list.checkData(data);
}

template<class T>
void Insieme<T>::insertElement(const T data) {
	if (this->maxSize > this->lenght) {
		if (!this->checkElement(data)) {
			this->list.insertEnd(data);
			this->lenght++;
		}
	}
}

template<class T>
void Insieme<T>::eraseElement(const T data) {
	this->list.eraseData(data);
	this->lenght--;
}

template<class T>
int Insieme<T>::sizeInsieme() const {
	return this->lenght;
}

template<class T>
T Insieme<T>::readListPosition(int pos) const {
	return this->list.readPosition(pos);
}

template<class T>
Insieme<T>& Insieme<T>::Union(const Insieme<T> insieme) {
	Insieme<T> *newInsieme = new Insieme<T>(*this);
	for (int i = 0; i < insieme.sizeInsieme(); i++) {
		newInsieme->insertElement(insieme.readListPosition(i + 1));
	}
	return *newInsieme;
}

template<class T>
Insieme<T>& Insieme<T>::Difference(const Insieme<T> insieme) {
	Insieme<T> *newInsieme = new Insieme<T>(*this);
	for (int i = 0; i < insieme.sizeInsieme(); i++) {
		if (newInsieme->checkElement(insieme.readListPosition(i + 1)))
			newInsieme->eraseElement(insieme.readListPosition(i + 1));
	}
	return *newInsieme;
}

template<class T>
Insieme<T>& Insieme<T>::Intersection(const Insieme<T> insieme) {
	Insieme<T> *newInsieme = new Insieme<T>(100);
	for (int i = 0; i < insieme.sizeInsieme(); i++) {
		if (this->checkElement(insieme.readListPosition(i + 1)))
			newInsieme->insertElement(insieme.readListPosition(i + 1));
	}
	return *newInsieme;
}

template<class T>
std::ostream& operator<<(std::ostream& os, Insieme<T> &insieme) {
	std::cout << insieme.list;
	return os;
}
#endif /* INSIEME_H_ */
