#ifndef TREE__H__
#define TREE__H__

class Tree {
public:
	bool search(int x);
	void insert(int x);
	void remove(int x);
	void print();
	
	~Tree();
	
private:
	struct Node {
		Node(int x) : data(x) {}
		
		int data;
		
		Node* left;
		Node* right;
		Node* parent;
	};
	
	Node* root;
	
	bool search(int x, Node* node);
	void insert(int x, Node* node);
		
	//typedef void (*FUNC) (Node* node);
	//void traverse(Node* node, FUNC func);
	
	void traversePrint(Node* node);
	void traverseDelete(Node* node);
};

#endif  // TREE__H__
