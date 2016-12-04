#ifndef TREE__H__
#define TREE__H__

class Tree {
public:
	bool search(int x);
	void insert(int x);
	void remove(int x);
	void print();
	size_t size();
	
	Tree();
	~Tree();
	
private:
	struct Node {
		Node(int x)
		  : data(x)
		  , left(nullptr)
		  , right(nullptr)
		  , parent(nullptr) {}
		
		int data;
		
		Node* left;
		Node* right;
		Node* parent;
	};
	
	Node* root;
	size_t m_size;
	
	bool search(int x, Node* node);
	Node* insert(int x, Node* node);
		
	//typedef void (*FUNC) (Node* node);
	//void traverse(Node* node, FUNC func);
	
	void traversePrint(Node* node);
	void traverseDelete(Node* node);
};

#endif  // TREE__H__
