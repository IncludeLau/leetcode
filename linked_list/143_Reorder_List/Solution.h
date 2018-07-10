/*
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:

给定链表 1->2->3->4, 重新排列为 1->4->2->3.

示例 2:

给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
*/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include "../ListNode.h"

class Solution {
public:
    ListNode* reorderList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* slow = &dummy, *fast = &dummy;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* t = slow->next;
        slow->next = nullptr;
        ListNode* nh = reverse(t);
        ListNode ret(0);
        ListNode *cur = &ret;
        while(nh && head) {
            ListNode* newHead = head->next;
            ListNode* newNh = nh->next;
            cur->next = head;
            cur->next->next = nh;
            cur = nh;
            head = newHead;
            nh = newNh;
        }
        if(head) {
            cur->next = head;
        }
        return ret.next;
    }

    ListNode* reverse(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* np = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return np;
    }
};
#endif //LEETCODE_SOLUTION_H
