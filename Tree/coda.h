#ifndef CODA_H_
#define CODA_H_

#include <iostream>
#include "linkedList.h"

template<class T> class Coda {
private:
	LinkedList<T> list;
	int lenght;
	int maxSize;

public:
	Coda(int);
	~Coda();
	bool isEmpty();
	T pull();
	void push(const T data);
	T readTop();
	int sizeCoda();

	template<class T1>
	friend std::ostream& operator<<(std::ostream&, Coda<T1>&);
};

template<class T>
Coda<T>::Coda(int size) {
	this->lenght = 0;
	this->maxSize = size;
}

template<class T>
Coda<T>::~Coda() {
	this->list.~LinkedList();
	this->lenght = 0;
	this->maxSize = 0;
}

template<class T>
bool Coda<T>::isEmpty() {
	if (this->lenght)
		return false;
	else
		return true;
}

template<class T>
T Coda<T>::pull() {
	if (this->isEmpty())
		return T();
	else {
		T data = this->list.readFirst();
		this->list.eraseFirst();
		this->lenght--;
		return data;
	}
}

template<class T>
void Coda<T>::push(const T data) {
	if (this->maxSize > this->lenght) {
		this->list.insertEnd(data);
		this->lenght++;
	}
}

template<class T>
T Coda<T>::readTop() {
	return this->list.readFirst();
}

template<class T>
int Coda<T>::sizeCoda() {
	return this->lenght;
}

#endif /* CODA_H_ */
