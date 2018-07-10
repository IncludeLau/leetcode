/*
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:

输入: 1->2->3->3->4->4->5
输出: 1->2->5

示例 2:

输入: 1->1->1->2->3
输出: 2->3
*/
#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include "../ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode dummy(INT_MAX);
        dummy.next = head;
        ListNode *prev = &dummy;
        ListNode *cur = head;
        ListNode *next = head->next;

        ListNode ret(0);

        ListNode* curRet = &ret;
        while (cur->next) {
            if(prev->val != cur->val && cur->val != next->val) {
                curRet->next = cur;
                curRet = cur;
            }
            prev = prev->next;
            cur = cur->next;
            next = next->next;
        }
        if(cur->val != prev->val) {
            curRet->next = cur;
            curRet = cur;
        }
        curRet->next = nullptr;
        return ret.next;
    }
};

#endif //LEETCODE_SOLUTION_H
