#include <iostream>

#include "Solution.h"

using namespace std;

int main() {
    Solution solution;

    ListNode* head, * after;

    head = createList({1,2,3,4,5});
    after = solution.reverseBetween(head, 2, 4);
    assert(listToVector(after) == std::vector<int>({1,4,3,2,5}));

    head = createList({1});
    after = solution.reverseBetween(head, 1,1);
    assert(listToVector(after) == std::vector<int>({1}));

    head = createList({1,2,3,4,5});
    after = solution.reverseBetween(head, 2, 3);
    assert(listToVector(after) == std::vector<int>({1,3,2,4,5}));

    std::cout << "All test passed" << std::endl;
    std::cout << "Done" << std::endl;
}
