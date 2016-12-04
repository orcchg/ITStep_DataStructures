#include <cstdio>
#include "tree.h"

/* Public */
// ------------------------
bool Tree::search(int x) {
	return search(x, root);
}

void Tree::insert(int x) {
	Node* node = insert(x, root);
	if (root == nullptr) root = node;
}

void Tree::remove(int x) {
	// TODO: implement
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
bool Tree::search(int x, Node* node) {
	if (node == nullptr) return false;
	if (node->data == x) return true;
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
			return left;
		} else {
			Node* right = insert(x, node->right);
			if (node->right == nullptr) node->right = right;
			return right;
		}
	}
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
















