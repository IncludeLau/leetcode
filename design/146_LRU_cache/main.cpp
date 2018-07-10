#include <iostream>
#include "LRUCache.h"
using namespace std;

int main() {
    LRUCache lruCache(3);

    lruCache.put(1,1);
    lruCache.put(2,2);
    lruCache.put(3,3);
    lruCache.put(4,4);
    cout << lruCache.get(4) << endl;
    cout << lruCache.get(3) << endl;
    cout << lruCache.get(2) << endl;
    cout << lruCache.get(1) << endl;
    lruCache.put(5,5);
    cout << lruCache.get(1) << endl;
    cout << lruCache.get(2) << endl;
    cout << lruCache.get(3) << endl;
    cout << lruCache.get(4) << endl;
    cout << lruCache.get(5) << endl;

    std::list<int> list1{1,2,3,4,5};

    cout << "done" << endl;
    auto iter = list1.begin();
    iter++;
    iter++;

    list1.splice(list1.begin(), list1, iter);

    for(auto i = list1.cbegin(); i != list1.cend(); ++i) {
        cout << *i << endl;
    }
    cout << "done" << endl;
}