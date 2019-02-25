#ifndef HASHMAP_H_
#define HASHMAP_H_

#include <iostream>
#include <string>
#include "HashNode.h"

template<class K>
struct KeyHash {
	unsigned long operator()(const K &key, int hashTableSize) const {
		return (unsigned long)key % hashTableSize;
	}
};

template <>
struct KeyHash<std::string> {
	unsigned long operator()(const std::string &key, int hashTableSize) const {
		unsigned long hashValue = 0;
		int length = (int) key.length();
		for (int i = 0; i < length; i++)
			hashValue = 5 * hashValue + (int)key.at(i);
		return (unsigned long)(hashValue) % hashTableSize;
	}
};

template<class K, class V>
class HashMap {
public:
	HashMap(const int);
	~HashMap();
	bool get(const K&, V&);
	void put(const K&, const V&);
	void remove(const K&);

private:
	HashNode<K, V> **table;
	KeyHash<K> hashFunction;
	int hashTableSize;
	int size;
};

template<class K, class V>
HashMap<K, V>::HashMap(const int tableSize) {
	this->size = 0;
	int defaultSize = 100;
	if (tableSize > 0)
		defaultSize = tableSize;
	this->table = new HashNode<K, V> *[defaultSize]();
	this->hashTableSize = defaultSize;
}

template<class K, class V>
HashMap<K, V>::~HashMap() {
	for (int i = 0; i < this->hashTableSize; i++) {
		HashNode<K, V> *pilot = this->table[i];
		while (pilot) {
			HashNode<K, V> *next = pilot->getNext();
			delete pilot;
			pilot = next;
		}
		table[i] = nullptr;
	}
	delete[] table;
}

template<class K, class V>
bool HashMap<K, V>::get(const K &key, V &value) {
	unsigned long hashValue = hashFunction(key, this->hashTableSize);
	HashNode<K, V> *pilot = table[hashValue];
	while (pilot) {
		if (pilot->getKey() == key) {
			value = pilot->getValue();
			return true;
		}
		pilot = pilot->getNext();
	}
	return false;
}

template<class K, class V>
void HashMap<K, V>::put(const K &key, const V &value) {
	unsigned long hashValue = hashFunction(key, this->hashTableSize);
	HashNode<K, V> *pilot = table[hashValue];
	HashNode<K, V> *prev = nullptr;
	if (!pilot)
		table[hashValue] = new HashNode<K, V>(key, value);
	else {
		while (pilot && pilot->getKey() != key) {
			prev = pilot;
			pilot = pilot->getNext();
		}
		if (!pilot)
			prev->setNext(new HashNode<K, V>(key, value));
		else
			pilot->setValue(value);
	}
}

template<class K, class V>
void HashMap<K, V>::remove(const K &key) {
	unsigned long hashValue = hashFunction(key, this->hashTableSize);
	HashNode<K, V> *pilot = table[hashValue];
	HashNode<K, V> *prev = nullptr;
	if (pilot) {
		while (pilot && pilot->getKey() != key) {
			prev = pilot;
			pilot = pilot->getNext();
		}
		if (pilot && prev) {
			prev->setNext(pilot->getNext());
			delete pilot;
		} else if (!prev) {
			table[hashValue] = nullptr;
			delete pilot;
		}
	}
}

#endif /* HASHMAP_H_ */
