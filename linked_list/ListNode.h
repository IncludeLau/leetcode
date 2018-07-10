#ifndef LEETCODE_LISTNODE_H
#define LEETCODE_LISTNODE_H

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x): val(x), next(nullptr) {}
};

void printList(ListNode* head) {
    int c = 0;
    std::cout << "*>" ;
    while (head && head->next) {
        std::cout << head->val << "->";
        head = head->next;
        c++;
        if (c > 100) {
            std::cout << std::endl;
            std::cout << "some thing wrong happend" << std::endl;
            return;
        }
    }
    if(head) {
        std::cout << head->val;
    }
    std::cout << "<*";
    std::cout << std::endl;
}

ListNode* createList(std::vector<int>&& v) {
    ListNode dummy(0);
    ListNode* head = &dummy;
    for(auto& i: v) {
        auto temp = new ListNode(i);
        head->next = temp;
        head = temp;
    }
#ifdef DEBUG
    std::cout << "Init finished..." << std::endl;
#endif
    return dummy.next;
}

std::vector<int> listToVector(ListNode* head) {
    std::vector<int> res;
    ListNode* temp = head;
    int c = 0;
    while (temp) {
        res.push_back(temp->val);
        temp = temp->next;
        c++;
        if(c > 100) {
            break;
        }
    }
    return res;
}

std::pair<ListNode*, ListNode*> createListRetTailAndHead(std::vector<int>&& v) {
    ListNode dummy(0);
    ListNode* head = &dummy;
    ListNode* temp;
    for(auto& i: v) {
        temp = new ListNode(i);
        head->next = temp;
        head = temp;
    }
    return std::make_pair(dummy.next, temp);
};

void destoryList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete(temp);
    }
#ifdef DEBUG
    std::cout << "Destory finished..." << std::endl;
#endif
}
#endif //LEETCODE_LISTNODE_H
