#ifndef HASH_TABLE__H__
#define HASH_TABLE__H__

#include <vector>

#define M 20  // size of hash table

template <typename T>
class HashTable {
public:
	HashTable();
	~HashTable();
	
	std::vector<T> search(int key);
	void insert(int key, const T& value);
	void remove(int key);
	void print();

private:
	struct Node {
		Node* next;
		T data;
		
		Node(const T& data)
		  : next(nullptr), data(data) {}
	};
	
	Node** m_buckets;
	
	int hash(int key);
};

#include "hash_table.cpp"

#endif  // HASH_TABLE__H__
