/*
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
示例:

输入:
[
1->4->5,
1->3->4,
2->6
]
输出: 1->1->2->3->4->4->5->6
*/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include "../ListNode.h"
#include <vector>

using namespace std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        if (lists.size() == 1) return lists[0];
        vector<ListNode*> temp;
        int i = 0;
        for(; i < lists.size(); i+=2) {
            if(i+2 > lists.size()) break;
            temp.push_back(mergeTwoLists(lists[i], lists[i+1]));
        }
        if(i < lists.size()) {
            temp.push_back(lists[i]);
        }
        return mergeKLists(temp);
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode* node;
        if(l1->val < l2->val) {
            node = l1;
            node->next = mergeTwoLists(l1->next, l2);
        }else {
            node = l2;
            node->next = mergeTwoLists(l1, l2->next);
        }
        return node;
    }
};
