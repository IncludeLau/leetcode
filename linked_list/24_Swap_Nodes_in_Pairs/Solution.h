/*
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.

说明:

    你的算法只能使用常数的额外空间。
    你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
*/
#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include "../ListNode.h"
#include <vector>

using namespace std;


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return  head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy, *cur = head;
        while (cur && cur->next) {
            ListNode* next = cur->next;
            prev->next = next;
            cur->next = next->next;
            next->next = cur;
            prev = cur;
            cur = cur->next;
        }
        return dummy.next;
    }
};

#endif //LEETCODE_SOLUTION_H
