/*
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:

输入: 1->1->2
输出: 1->2

示例 2:

输入: 1->1->2->3->3
输出: 1->2->3
*/
#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include "../ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* retCur = head;
        ListNode* prev = head;
        ListNode* cur = head->next;
        while (cur) {
            if(cur->val != prev->val) {
                retCur->next = cur;
                retCur = cur;
            }
            cur = cur->next;
            prev = prev->next;
        }
        retCur->next = nullptr;
        return dummy.next;
    }
};

#endif //LEETCODE_SOLUTION_H
