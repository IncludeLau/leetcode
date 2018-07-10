#include <iostream>
#include "Solution.h"
#include <vector>

int main() {
    std::function<ListNode*(ListNode*, int)> f;

    f = Solution::removeNthFromEndv2;

    ListNode* head = createList({1,2,3,4,5,6});
    ListNode* after = f(head, 1);
    assert(listToVector(after) == std::vector<int>({1,2,3,4,5}));

    head = createList({1,2,3,4,5,6});
    after = f(head, 2);
    assert(listToVector(after) == std::vector<int>({1,2,3,4,6}));

    head = createList({1,2,3,4,5,6});
    after = f(head, 3);
    assert(listToVector(after) == std::vector<int>({1,2,3,5,6}));

    head = createList({1,2,3,4,5,6});
    after = f(head, 4);
    assert(listToVector(after) == std::vector<int>({1,2,4,5,6}));

    head = createList({1,2,3,4,5,6});
    after = f(head, 5);
    assert(listToVector(after) == std::vector<int>({1,3,4,5,6}));

    head = createList({1,2,3,4,5,6});
    after = f(head, 6);
    assert(listToVector(after) == std::vector<int>({2,3,4,5,6}));
    std::cout << "All test passed!" << std::endl;

}