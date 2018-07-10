#include <iostream>
#include "Solution.h"

#define DEBUG 0

int main() {
    std::function<ListNode*(ListNode*)> f;

    f = Solution::reverseListv2;

    ListNode* head = createList({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18});
#ifdef DEBUG
    printList(head);
#endif
    head = f(head);
    assert(head->val == 18);
    assert(head->next->val = 17);
    destoryList(head);
    ListNode* head2 = createList({});
    printList(head2);
    printList(f(head2));
    assert(head2 == nullptr);
    destoryList(head2);

    ListNode* head3 = createList({1});
    printList(head3);
    printList(f(head3));
    assert(head3->val == 1);
    assert(head3->next == nullptr);
    destoryList(head3);
    std::cout << "DONE" << std::endl;
}