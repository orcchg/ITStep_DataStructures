#include <cstdio>
#include "tree.h"

/* Public */
// ------------------------
bool Tree::search(int x) {
	return search(x, root);
}

void Tree::insert(int x) {
	insert(x, root);
}

void Tree::remove(int x) {
	// TODO: implement
}

void Tree::print() {
	traversePrint(root);
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

void Tree::insert(int x, Node* node) {
	if (node == nullptr) {
		node = new Node(x);
	} else {
		if (node->data >= x) {
			insert(x, node->left);
		} else {
			insert(x, node->right);
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
















