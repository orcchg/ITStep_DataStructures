g++ -std=c++11 -c hash_table.cpp
g++ -shared hash_table.o -o libhash.dll
g++ -std=c++11 hash_main.cpp -o hash_main -lhash -L.
