#include <cstdio>
#include "hash_table.h"

template <typename T>
HashTable<T>::HashTable()
  : m_buckets(new Node*[M]) {
    for (int i = 0; i < M; ++i) {
		m_buckets[i] = nullptr;
	}
}

template <typename T>
HashTable<T>::~HashTable() {
	delete [] m_buckets;
}

template <typename T>
std::vector<T> HashTable<T>::search(int key) {
	size_t index = hash(key);
	
	std::vector<T> v;
	HashTable<T>::Node* head = m_buckets[index];
	while (head != nullptr) {
		v.push_back(head->data);
		head = head->next;
	}
	return v;
}

template <typename T>
void HashTable<T>::insert(int key, const T& value) {
	int index = hash(key);
	
	HashTable<T>::Node* node = m_buckets[index];
	if (node == nullptr) {
		node = new Node(value);
		m_buckets[index] = node;
	} else {
		HashTable<T>::Node* prev = node;
		while (node->next != nullptr) {
			prev = node;
			node = node->next;
		}
		node->next = new Node(value);
	}
}

template <typename T>
void HashTable<T>::remove(int key) {
	int index = hash(key);
	m_buckets[index] = nullptr;
}

template <typename T>
void HashTable<T>::print() {
	for (int i = 0; i < M; ++i) {
		HashTable<T>::Node* head = m_buckets[i];
		while (head != nullptr) {
			printf("%lf ", head->data);
			head = head->next;
		}
		printf("\n");
	}
}

// -----------------------------------
template <typename T>
int HashTable<T>::hash(int key) {
	return key % 2;
}
