#include <iostream>
#include "WordDictionary.h"

using namespace std;

int main() {
    WordDictionary wordDictionary;

    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");
    wordDictionary.addWord("apple");
    assert(!wordDictionary.search("pad"));
    assert(wordDictionary.search("bad"));
    assert(wordDictionary.search(".ad"));
    assert(wordDictionary.search("b.."));
    assert(!wordDictionary.search("app"));

    cout << "DONE" << endl;
    cout << "All test passed!" << endl;
}