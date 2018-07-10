#include <iostream>

#include "Solution.h"

using namespace std;

int main() {
    Solution solution;

    ListNode* head;
    ListNode* after;

    head = createList({});
    after = solution.swapPairs(head);
    assert(listToVector(after) == std::vector<int>({}));

    head = createList({2});
    after = solution.swapPairs(head);
    assert(listToVector(after) == std::vector<int>({2}));


    head = createList({1, 2});
    after = solution.swapPairs(head);
    assert(listToVector(after) == std::vector<int>({2, 1}));

    head = createList({1,2,3});
    after = solution.swapPairs(head);
    assert(listToVector(after) == std::vector<int>({2, 1, 3}));

    head = createList({1, 2, 3, 4});
    after = solution.swapPairs(head);
    assert(listToVector(after) == std::vector<int>({2, 1, 4, 3}));

    std::cout << "All test passed" << std::endl;
    std::cout << "Done" << std::endl;
}
