#include <iostream>
#include "Trie.h"

using namespace std;

int main() {
    Trie trie;

    trie.insert("apple");
    assert(trie.search("apple"));
    assert(!trie.search("app"));
    assert(trie.startsWith("app"));
    assert(trie.startsWith("ap"));
    assert(trie.startsWith("a"));
    trie.insert("app");
    assert(trie.search("app"));

    assert(!trie.search("iphone"));
    std::cout << "All test pass!" << endl;
}