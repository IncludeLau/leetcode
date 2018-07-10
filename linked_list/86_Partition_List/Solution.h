/*
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例:

输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5
*/
#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include "../ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode dummy1(0);
        ListNode dummy2(0);
        ListNode* cur1 = &dummy1;
        ListNode* cur2 = &dummy2;
        while (head) {
            if(head->val < x) {
                cur1->next = head;
                cur1 = head;
            }else {
                cur2->next = head;
                cur2 = head;
            }
            head = head->next;
        }
        cur2->next = nullptr;
        if(dummy1.next == nullptr) return dummy2.next;
        if(dummy2.next == nullptr) return dummy1.next;
        cur1->next = dummy2.next;
        return dummy1.next;
    }
};

#endif //LEETCODE_SOLUTION_H
