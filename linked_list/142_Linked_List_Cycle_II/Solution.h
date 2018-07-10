/*
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

说明：不允许修改给定的链表。

进阶：
你是否可以不用额外空间解决此题？
*/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include "../ListNode.h"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return nullptr;

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                slow = head;
                while(slow != fast) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};
#endif //LEETCODE_SOLUTION_H
