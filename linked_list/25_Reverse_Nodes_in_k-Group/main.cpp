#include <iostream>

#include "Solution.h"

using namespace std;

int main() {
    Solution solution;

    ListNode* head, * after;
    head = createList({1,2,3,4,5,6,7,8,9});
    after = solution.reverseKGroup(head, 2);
    assert(listToVector(after) == std::vector<int>({2,1,4,3,6,5,8,7,9}));

    head = createList({1,2,3,4,5,6,7,8,9});
    after = solution.reverseKGroup(head, 3);
    assert(listToVector(after) == std::vector<int>({3,2,1,6,5,4,9,8,7}));


    head = createList({1,2,3,4,5,6,7,8,9});
    after = solution.reverseKGroup(head, 4);
    assert(listToVector(after) == std::vector<int>({4,3,2,1,8,7,6,5,9}));

    head = createList({1,2,3,4,5,6,7,8,9});
    after = solution.reverseKGroup(head, 5);
    assert(listToVector(after) == std::vector<int>({5,4,3,2,1,6,7,8,9}));

    head = createList({1,2,3,4,5,6,7,8,9});
    after = solution.reverseKGroup(head, 6);
    assert(listToVector(after) == std::vector<int>({6,5,4,3,2,1,7,8,9}));

    head = createList({1,2,3,4,5,6,7,8,9});
    after = solution.reverseKGroup(head, 1);
    assert(listToVector(after) == std::vector<int>({1,2,3,4,5,6,7,8,9}));

    head = createList({1,2,3,4,5,6,7,8,9});
    after = solution.reverseKGroup(head, 10);
    assert(listToVector(after) == std::vector<int>({1,2,3,4,5,6,7,8,9}));

    std::cout << "All test passed" << std::endl;
    std::cout << "Done" << std::endl;
}
