#ifndef BTNODE_H_
#define BTNODE_H_

template<class T>
class BTNode {
public:
	BTNode();
	T getValue() const;
	BTNode<T> *getParent() const;
	BTNode<T> *getLeft() const;
	BTNode<T> *getRight() const;
	void setValue(const T &);
	void setParent(BTNode<T> *);
	void setLeft(BTNode<T> *);
	void setRight(BTNode<T> *);
	bool noLeafs() const;
private:
	T value;
	BTNode<T> *parent;
	BTNode<T> *left;
	BTNode<T> *right;
};

template<class T>
BTNode<T>::BTNode() {
	this->value = T();
	this->parent = nullptr;
	this->left = nullptr;
	this->right = nullptr;
}

template<class T>
T BTNode<T>::getValue() const {
	return this->value;
}

template<class T>
BTNode<T> * BTNode<T>::getParent() const {
	return this->parent;
}

template<class T>
BTNode<T> * BTNode<T>::getLeft() const {
	return this->left;
}

template<class T>
BTNode<T> * BTNode<T>::getRight() const {
	return this->right;
}

template<class T>
void BTNode<T>::setValue(const T &value) {
	this->value = value;
}

template<class T>
void BTNode<T>::setParent(BTNode<T> *parent) {
	this->parent = parent;
}

template<class T>
void BTNode<T>::setLeft(BTNode<T> *left) {
	this->left = left;
}

template<class T>
void BTNode<T>::setRight(BTNode<T> *right) {
	this->right = right;
}

template<class T>
bool BTNode<T>::noLeafs() const {
	if (!this->left && !this->right)
		return true;
	else return false;
}

#endif /* BTNODE_H_ */
