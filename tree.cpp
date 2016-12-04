#include <cstdio>
#include <cstdlib>
#include "tree.h"

/* Public */
// ------------------------
bool Tree::search(int x) {
	return search(x, root) != nullptr;
}

void Tree::insert(int x) {
	Node* node = insert(x, root);
	if (root == nullptr) root = node;
}

void Tree::remove(int x) {
	remove(x, root);
}

void Tree::print() {
	traversePrint(root);
}

size_t Tree::size() {
	return m_size;
}

Tree::Tree() : root(nullptr), m_size(0) {
}

Tree::~Tree() {
	traverseDelete(root);
}

/* Private */
// ------------------------
Tree::Node* Tree::search(int x, Node* node) {
	if (node == nullptr) return nullptr;
	if (node->data == x) return node;
	if (node->data >= x) {
		return search(x, node->left);
	} else {
		return search(x, node->right);
	}
}

Tree::Node* Tree::insert(int x, Node* node) {
	if (node == nullptr) {
		++m_size;
		return new Node(x);
	} else {
		if (node->data >= x) {
			Node* left = insert(x, node->left);
			if (node->left == nullptr) node->left = left;
			left->parent = node;
			return left;
		} else {
			Node* right = insert(x, node->right);
			if (node->right == nullptr) node->right = right;
			right->parent = node;
			return right;
		}
	}
}

void Tree::remove(int x, Node* node) {
	if (node == nullptr) return;
	Node* found = search(x, node);
	if (found == nullptr) return;
	
	Node* parent = found->parent;
	if (parent == nullptr) {
		parent = root;
	}
	
	// zero child
	if (found->left == nullptr && found->right == nullptr) {
		if (parent->data <= found->data) {
			parent->right = nullptr;
		} else {
			parent->left = nullptr;
		}
		
		--m_size;  delete found;  found = nullptr;  return;
	}
	
	// single child
	if (found->left != nullptr && found->right == nullptr) {
		if (parent->data <= found->data) {
			parent->right = found->left;
		} else {
			parent->left = found->left;
		}
		
		--m_size;  delete found;  found = nullptr;  return;
	}
	if (found->left == nullptr && found->right != nullptr) {
		if (parent->data <= found->data) {
			parent->right = found->right;
		} else {
			parent->left = found->right;
		}
		
		--m_size;  delete found;  found = nullptr;  return;
	}
	
	// two childs
	if (found->left != nullptr && found->right != nullptr) {
		Node* key = nullptr;
		if (rand() % 2 == 0) {
			key = predecessor(found);
		} else {
			key = successor(found);
		}
		found->data = key->data;
		remove(key->data, key);
	}
}

Tree::Node* Tree::predecessor(Node* node) {
	if (node == nullptr || node->left == nullptr) return nullptr;
	Node* key = node->left;
	while (key->right != nullptr) {
		key = key->right;
	}
	return key;
}

Tree::Node* Tree::successor(Node* node) {
	if (node == nullptr || node->right == nullptr) return nullptr;
	Node* key = node->right;
	while (key->left != nullptr) {
		key = key->left;
	}
	return key;
}

void Tree::traversePrint(Node* node) {
	if (node == nullptr) return;
	
	traversePrint(node->left);
	printf("%i ", node->data);
	traversePrint(node->right);
}

void Tree::traverseDelete(Node* node) {
	if (node == nullptr) return;
	
	traverseDelete(node->left);
	traverseDelete(node->right);
	delete node;  node = nullptr;
}

/*void Tree::traverse(Node* node, FUNC func) {
	if (node == nullptr) return;
	
	traverse(node->left, func);
	traverse(node->right, func);
	func(node);
}*/

/*void Tree::printNode(Node* node) {
	if (node == nullptr) return;
	//std::cout << node->data << " ";
}

void Tree::deleteNode(Node* node) {
	delete node;  node = nullptr;
}
*/
















