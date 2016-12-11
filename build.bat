g++ -std=c++11 -c -ggdb3 -O0 tree.cpp
g++ -shared tree.o -o libtree.dll
g++ -std=c++11 -ggdb3 -O0 tree_main.cpp -o tree_main -ltree -L.
