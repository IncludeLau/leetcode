/*
给出一个链表，每 k 个节点一组进行翻转，并返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么将最后剩余节点保持原有顺序。

示例 :

给定这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5

说明 :

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
    static ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int c = k;
        while (--c && temp) {
            temp = temp->next;
        }
        if(temp == nullptr) return head;
        ListNode* next = temp->next;
        temp->next = nullptr;
        ListNode* nhead = reverseList(head);
        head->next = reverseKGroup(next, k);
        return nhead;
    }

private:
    static ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* np = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return np;
    }
};

#endif //LEETCODE_SOLUTION_H
