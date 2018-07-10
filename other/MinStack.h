
#ifndef LEETCODE_MINSTACK_H
#define LEETCODE_MINSTACK_H

#include <stack>

using std::stack;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int x) {
        s1.push(x);
        if (s2.empty()) {
            s2.push(x);
        }else{
            int top = s2.top();
            x = std::min(top, x);
            s2.push(x);
        }
    }

    void pop() {
        s1.pop();
        s2.pop();
    }

    int top() {
        s1.top();
    }

    int getMin() {
        s2.top();
    }

private:
    stack<int> s1;
    stack<int> s2;
};
#endif //LEETCODE_MINSTACK_H
