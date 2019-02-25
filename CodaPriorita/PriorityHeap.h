#ifndef PRIORITYHEAP_H_
#define PRIORITYHEAP_H_

#include <iostream>

template<class T>
class PriorityHeap {
public:
	PriorityHeap();
	PriorityHeap(int &);
	~PriorityHeap();
	void insert(const T&);
	bool min(T &) const;
	void eraseMin();
	void print() const;
private:
	int maxSize;
	T *heap;
	int last;
	void fixUp();
	void fixDown(int, int);
};

template<class T>
PriorityHeap<T>::PriorityHeap() {
	this->maxSize = 100;
	this->heap = new T[100];
	this->last = 0;
}

template<class T>
PriorityHeap<T>::PriorityHeap(int &size) {
	this->maxSize = size;
	this->heap = new T[size];
	this->last = 0;
}

template<class T>
PriorityHeap<T>::~PriorityHeap() {
	this->last = 0;
	delete[] this->heap;
}

template<class T>
void PriorityHeap<T>::insert(const T &value) {
	if (this->last < this->maxSize) {
		heap[this->last] = value;
		this->last++;
		this->fixUp();
	}
}

template<class T>
bool PriorityHeap<T>::min(T &var) const {
	if (this->last) {
		var = this->heap[0];
		return true;
	} else
		return false;
}

template<class T>
void PriorityHeap<T>::eraseMin() {
	if (this->last) {
		this->heap[0] = this->heap[last - 1];
		this->last--;
		this->fixDown(1, this->last);
	}
}

template<class T>
void PriorityHeap<T>::fixUp() {
	int last = this->last;
	while (last > 1 && this->heap[last - 1] < this->heap[last / 2 - 1]) {
		T temp;
		temp = this->heap[last - 1];
		this->heap[last - 1] = this->heap[last / 2 - 1];
		this->heap[last / 2 - 1] = temp;
		last = last / 2;
	}
}

template<class T>
void PriorityHeap<T>::fixDown(int k, int last) {
	short int swap = 1;
	while (k <= last / 2 && swap) {
		int j = 2 * k;
		T temp;
		if (j < last && this->heap[j - 1] > this->heap[j])
			j++;
		if (this->heap[j - 1] < this->heap[k - 1]) {
			temp = this->heap[k - 1];
			this->heap[k - 1] = this->heap[j - 1];
			this->heap[j - 1] = temp;
			k = j;
			swap = 1;
		}
		else
			swap = 0;
	}
}

template<class T>
void PriorityHeap<T>::print() const {
	if (this->heap) {
		std::cout << "[";
		for (int i = 0; i < this->last; i++)
			std::cout << this->heap[i] << ", ";
		std::cout << "]" << std::endl;
	}
	else
		std::cout << "[]" << std::endl;
}

#endif /* PRIORITYHEAP_H_ */
