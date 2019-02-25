#ifndef NODE_H_
#define NODE_H_

template<class T>
class Node {
public:
	Node();
	T getValue() const;
	Node<T> *getLeft() const;
	Node<T> *getRight() const;
	void setValue(const T &);
	void setLeft(Node<T> *);
	void setRight(Node<T> *);
private:
	T value;
	Node<T> *left;
	Node<T> *right;
};

template<class T>
Node<T>::Node() {
	this->value = T();
	this->left = nullptr;
	this->right = nullptr;
}

template<class T>
T Node<T>::getValue() const {
	return this->value;
}

template<class T>
Node<T> * Node<T>::getLeft() const {
	return this->left;
}

template<class T>
Node<T> * Node<T>::getRight() const {
	return this->right;
}

template<class T>
void Node<T>::setValue(const T &value) {
	this->value = value;
}

template<class T>
void Node<T>::setLeft(Node<T> *left) {
	this->left = left;
}

template<class T>
void Node<T>::setRight(Node<T> *right) {
	this->right = right;
}
#endif /* NODE_H_ */
