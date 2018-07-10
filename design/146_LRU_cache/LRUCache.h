//
// Created by 刘新军 on 2018/6/25.
//

/*
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。

获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。

进阶:

你是否可以在 O(1) 时间复杂度内完成这两种操作？

示例:

LRUCache cache = new LRUCache( 2);

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回  1
cache.put(3, 3);    // 该操作会使得密钥 2 作废
cache.get(2);       // 返回 -1 (未找到)
cache.put(4, 4);    // 该操作会使得密钥 1 作废
cache.get(1);       // 返回 -1 (未找到)
cache.get(3);       // 返回  3
cache.get(4);       // 返回  4

*/
#ifndef LEETCODE_LRUCACHE_H
#define LEETCODE_LRUCACHE_H

#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    explicit LRUCache(int capacity):capacity_(capacity) {}

    int get(int key) {
        auto iter = m_.find(key);
        if(iter==m_.end()) return -1;

        cache_.splice(cache_.begin(),cache_,iter->second);
        return iter->second->second;
    }

    void put(int key, int value) {
        auto iter = m_.find(key);
        if(iter != m_.end())
        {
            iter->second->second = value;
            cache_.splice(cache_.begin(), cache_, iter->second);
            return;
        }

        if(cache_.size() == capacity_)
        {
            auto delPair = cache_.back();
            m_.erase(delPair.first);
            cache_.pop_back();
        }

        cache_.emplace_front(key,value);
        auto front = cache_.begin();
        m_[key] = front;
    }
private:
    int capacity_;
    list<pair<int,int>> cache_;
    unordered_map<int,list<pair<int,int>>::iterator> m_;
};

#endif //LEETCODE_LRUCACHE_H
