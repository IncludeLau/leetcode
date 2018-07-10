//
// Created by 刘新军 on 2018/6/25.
//

/*
Implement the following operations of a queue using stacks.

    push(x) -- Push element x to the back of queue.
    pop() -- Removes the element from in front of queue.
    peek() -- Get the front element.
    empty() -- Return whether the queue is empty.

Example:

MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);
queue.peek();  // returns 1
queue.pop();   // returns 1
queue.empty(); // returns false

Notes:

    You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
    Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
    You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
*/

#ifndef LEETCODE_MYQUEUE_H
#define LEETCODE_MYQUEUE_H

#include <stack>

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() = default;

    /** Push element x to the back of queue. */
    void push(int x) {
        s_push.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        moveElements();
        int r = s_pop.top();
        s_pop.pop();
        return r;
    }

    /** Get the front element. */
    int peek() {
        moveElements();
        return s_pop.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s_push.empty() && s_pop.empty();
    }

private:

    void moveElements() {
        if(!s_pop.empty()) return;
        if(s_push.empty()) return;
        while (!s_push.empty()) {
            s_pop.push(s_push.top());
            s_push.pop();
        }
    }
    std::stack<int> s_push;
    std::stack<int> s_pop;
};
#endif //LEETCODE_MYQUEUE_H
