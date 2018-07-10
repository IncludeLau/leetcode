#include <iostream>
#include "RandomizedCollection.h"

using namespace std;

int main() {
    RandomizedCollection randomizedCollection;

    assert(randomizedCollection.insert(1));
    assert(!randomizedCollection.insert(1));
    assert(!randomizedCollection.remove(2));
    assert(randomizedCollection.remove(1));
    assert(randomizedCollection.getRandom() == 1);
    cout << "DONE" << endl;
}