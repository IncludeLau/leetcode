/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.

说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？
*/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include "../ListNode.h"

class Solution {
public:
    /**
     * 两遍扫描
     * @param head
     * @param n
     * @return
     */
    static ListNode* removeNthFromEndv1(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        int len = 0;
        ListNode* temp = head;
        while (temp) {
            len++;
            temp=temp->next;
        }
        temp = &dummy;
        for(int i = 0; i <len - n; i++) {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return dummy.next;
    }

    /**
     *
     * @param head
     * @param n
     * @return
     */
    static ListNode* removeNthFromEndv2(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* temp = head, * temp2 = &dummy;
        while (n--) {
            temp = temp->next;
        }
        while (temp) {
            temp = temp->next;
            temp2 =temp2->next;
        }
        temp2->next = temp2->next->next;
        return dummy.next;
    }
};

#endif //LEETCODE_SOLUTION_H
