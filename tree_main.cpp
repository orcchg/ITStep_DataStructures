#include <cstdio>
#include "tree.h"

int main(int argc, char** argv) {
	
	Tree A;
	
	A.insert(3);  // insert(&A, 3);
	A.insert(1);
	A.insert(5);
	A.insert(2);
	A.insert(4);
	A.insert(7);
	A.insert(0);
	A.insert(6);
	A.insert(8);
	
	A.debug();
	
	printf("Tree size: %zu\n", A.size());
	A.print();  // 0 1 2 3 4 5 6 7 8
	printf("\n");
	
	A.remove(5);
	printf("Tree size: %zu\n", A.size());
	A.print();
	printf("\n");
}

