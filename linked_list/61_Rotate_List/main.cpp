#include <iostream>

#include "Solution.h"

using namespace std;

int main() {
    Solution solution;

    ListNode* head, * after;

    head  = createList({1,2,3,4,5,6});
    after = solution.rotateRight(head, 1);
    assert(listToVector(after) == std::vector<int>({6,1,2,3,4,5}));

    head  = createList({1,2,3,4,5,6});
    after = solution.rotateRight(head, 2);
    assert(listToVector(after) == std::vector<int>({5,6,1,2,3,4}));

    head  = createList({1,2,3,4,5,6});
    after = solution.rotateRight(head, 4);
    assert(listToVector(after) == std::vector<int>({3,4,5,6,1,2}));

    head  = createList({1,2,3,4,5,6});
    after = solution.rotateRight(head, 6);
    assert(listToVector(after) == std::vector<int>({1,2,3,4,5,6}));

    head  = createList({1,2,3,4,5,6});
    after = solution.rotateRight(head, 0);
    assert(listToVector(after) == std::vector<int>({1,2,3,4,5,6}));

    head  = createList({1,2,3,4,5,6});
    after = solution.rotateRight(head, 7);
    assert(listToVector(after) == std::vector<int>({6,1,2,3,4,5}));

    std::cout << "All test passed" << std::endl;
    std::cout << "Done" << std::endl;
}
