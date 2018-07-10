//
// Created by 刘新军 on 2018/6/25.
//

#ifndef LEETCODE_MINSTACK_H
#define LEETCODE_MINSTACK_H

#include <stack>

template <typename T>
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() = default;
    void push(T x) {
        _restore.push(x);
        if(_min.empty() || x < _min.top()) {
            _min.push(x);
        }else {
            _min.push(_min.top());
        }
    }

    void pop() {
        if(!_restore.empty()) {
            _restore.pop();
            _min.pop();
        }
    }

    T top() {
        return _restore.top();
    }

    T getMin() {
        return _min.top();
    }

private:
    std::stack<T> _restore;
    std::stack<T> _min;
};


#endif //LEETCODE_MINSTACK_H
