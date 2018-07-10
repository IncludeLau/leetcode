/*
实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。

示例:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // 返回 true
trie.search("app");     // 返回 false
trie.startsWith("app"); // 返回 true
trie.insert("app");
trie.search("app");     // 返回 true

说明:

    你可以假设所有的输入都是由小写字母 a-z 构成的。
    保证所有输入均为非空字符串。
*/

#ifndef LEETCODE_TRIE_H
#define LEETCODE_TRIE_H

#include <string>
#include <map>

using namespace std;

struct Node {
    char _c;
    bool _end;
    map<char, Node*> _next;
    explicit Node(char c): _c(c), _end(false), _next(map<char, Node*>()){}
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        _root = new Node('0');
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* root = _root;
        for(char& c: word) {
            if(root->_next.count(c)){
                root = root->_next[c];
            }else {
                auto* node = new Node(c);
                root->_next[c] = node;
                root = root->_next[c];
            }
        }
        root->_end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* root = _root;
        for(char& c: word) {
            if(!root->_next.count(c))return false;
            root = root->_next[c];
        }
        return root->_end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* root = _root;
        for(char& c: prefix) {
            if(!root->_next.count(c))return false;
            root = root->_next[c];
        }
        return true;
    }

private:
    Node* _root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
#endif //LEETCODE_TRIE_H
