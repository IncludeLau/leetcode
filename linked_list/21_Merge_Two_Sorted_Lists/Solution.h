/*
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include "../ListNode.h"

class Solution {
public:
    static ListNode* mergeTwoListsV1(ListNode* l1, ListNode* l2) {
        ListNode* dump = new ListNode(0);
        ListNode* k1 = l1;
        ListNode* k2 = l2;
        ListNode* cur = dump;
        while(k1 && k2) {
            if(k1->val < k2->val) {
                cur->next = k1;
                k1 = k1->next;
                cur = cur->next;
            }else {
                cur->next = k2;
                k2 = k2->next;
                cur = cur->next;
            }
        }

        if(k1) cur->next= k1;
        if(k2) cur->next = k2;
        return dump->next;
    }

    static ListNode* mergeTwoListsV2(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode* node;
        if(l1->val < l2->val) {
            node = l1;
            node->next = mergeTwoListsV2(l1->next, l2);
        }else {
            node = l2;
            node->next = mergeTwoListsV2(l1, l2->next);
        }
        return node;
    }
};

#endif //LEETCODE_SOLUTION_H
