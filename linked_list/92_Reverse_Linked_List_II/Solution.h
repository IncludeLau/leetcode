/*
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL
*/
#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include "../ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;
        n = n - m;
        ListNode preHead(0);
        preHead.next = head;
        ListNode *pre = &preHead;
        while (--m) pre = pre->next;
        ListNode *first = pre->next;
        while (n--) {
            ListNode *p = first->next;
            first->next = p->next;
            p->next = pre->next;
            pre->next = p;
        }
        return preHead.next;
    }
};

#endif //LEETCODE_SOLUTION_H
