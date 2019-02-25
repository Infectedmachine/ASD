#ifndef HASHNODE_H_
#define HASHNODE_H_

template<class K, class V>
class HashNode {
public:
	HashNode(const K &key, const V &value);
	K getKey() const;
	V getValue() const;
	void setKey(const K);
	void setValue(const V);
	HashNode<K, V> *getNext() const;
	void setNext(HashNode<K, V> *);
private:
	K key;
	V value;
	HashNode<K, V> *next;
};

template<class K, class V>
HashNode<K, V>::HashNode(const K &key, const V &value) {
	this->key = key;
	this->value = value;
	this->next = nullptr;
}

template<class K, class V>
K HashNode<K, V>::getKey() const {
	return this->key;
}

template<class K, class V>
V HashNode<K, V>::getValue() const {
	return this->value;
}

template<class K, class V>
void HashNode<K, V>::setKey(const K key) {
	this->key = key;
}

template<class K, class V>
void HashNode<K, V>::setValue(const V value) {
	this->value = value;
}

template<class K, class V>
HashNode<K, V>* HashNode<K, V>::getNext() const {
	return this->next;
}

template<class K, class V>
void HashNode<K, V>::setNext(HashNode<K, V> *next) {
	this->next = next;
}

#endif /* HASHNODE_H_ */
