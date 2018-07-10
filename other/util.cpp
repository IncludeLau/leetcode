
#include <iostream>
#include <vector>

using std::vector;

template <class T>
void vector_print(vector<T> v) {
    for(T& it : v){
        std::cout << it <<  " ";
    }
    std::cout << std::endl;
}
