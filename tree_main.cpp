#include "tree.h"

int main(int argc, char** argv) {
	
	Tree A;
	
	A.insert(3);
	A.insert(1);
	A.insert(5);
	A.insert(2);
	A.insert(4);
	A.insert(7);
	A.insert(0);
	
	A.print();  // 0 1 2 3 4 5 7
}

