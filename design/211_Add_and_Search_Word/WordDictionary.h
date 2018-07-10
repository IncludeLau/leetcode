/*
设计一个支持以下两种操作的数据结构：

void addWord(word)
bool search(word)

search(word) 可以搜索文字或正则表达式字符串，字符串只包含字母 . 或 a-z 。 . 可以表示任何一个字母。

示例:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
说明:
   你可以假设所有单词都是由小写字母 a-z 组成的。
*/

#ifndef LEETCODE_WORDDICTIONARY_H
#define LEETCODE_WORDDICTIONARY_H

#include <string>
#include <map>

using namespace std;

struct Node {
    char _c;
    bool _end;
    map<char, Node*> _next;
    explicit Node(char c): _c(c), _end(false), _next(map<char, Node*>()){}
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        _root = new Node('0');
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
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

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(std::move(word), _root);
    }

private:

    bool search(string&& word, Node* root) {
        if(word.empty()) return false;
        if(word.size() == 1) {
            char c = word[0];
            if(c == '.') {
                for(auto& iter: root->_next) {
                    if(iter.second->_end) return true;
                }
                return false;
            }else
                return root->_next.count(c) > 0 && root->_next[c]->_end && root->_next[c]->_c == c;
        }
        char c = word[0];
        if(c != '.') {
            if(!root->_next.count(c)) return false;
            return search(word.substr(1), root->_next[c]);
        }else {
            for(auto iter = (root->_next).cbegin(); iter != (root->_next).cend(); ++iter) {
                bool find = search(word.substr(1), iter->second);
                if(find) return true;
            }
        }
        return false;
    }

private:
    Node* _root;
};


#endif //LEETCODE_WORDDICTIONARY_H
