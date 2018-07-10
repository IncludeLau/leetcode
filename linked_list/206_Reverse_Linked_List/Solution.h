/*
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL

进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

 */

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include "../ListNode.h"

class Solution {
public:
    static ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* np = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return np;
    }

    static ListNode* reverseListv2(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode * pre = head;
        ListNode * cur = head->next;
        head->next = nullptr;
        while (cur) {
            ListNode* node = cur->next;
            cur->next = pre;
            pre = cur;
            cur = node;
        }
        return pre;
    }
};

#endif //LEETCODE_SOLUTION_H
