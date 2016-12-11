#include "hash_table.h"

int main(int argc, char** argv) {
	
	HashTable<double> table;
	table.insert(2, 2.71);
	table.insert(51, 3.14);
	table.insert(700, 8.91);
	table.insert(271, -1.11);
	table.insert(190, 0.05);
	
	table.print();
	
	return 0;
}
