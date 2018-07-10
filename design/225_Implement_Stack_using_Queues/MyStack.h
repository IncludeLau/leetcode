//
// Created by 刘新军 on 2018/6/25.
//

/*
使用队列实现栈的下列操作：

    push(x) -- 元素 x 入栈
    pop() -- 移除栈顶元素
    top() -- 获取栈顶元素
    empty() -- 返回栈是否为空

注意:

    你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty 这些操作是合法的。
    你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
    你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。
*/
#ifndef LEETCODE_MYSTACK_H
#define LEETCODE_MYSTACK_H

#include <queue>

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() = default;

    // 每次进行push操作后，将队列的中的元素除了最后一个刚插入的，依次重新插入队列，
    // 从而将刚插入的移动到最前面的位置
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; ++i){
            q.push(q.front());
            q.pop();
        }
    }

    // Removes the element on top of the stack.
    int pop() {
        int r = top();
        q.pop();
        return r;
    }

    // Get the top element.
    int top() {
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }

private:
    std::queue<int> q;
};


#endif //LEETCODE_MYSTACK_H
