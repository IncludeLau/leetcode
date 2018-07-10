#include <iostream>

#include "Solution.h"

using namespace std;

int main() {
    Solution solution;

    ListNode* head, * after;

    head =  createList({});
    after = solution.deleteDuplicates(head);
    assert(listToVector(after) == std::vector<int>({}));

    head =  createList({1});
    after = solution.deleteDuplicates(head);
    assert(listToVector(after) == std::vector<int>({1}));

    head =  createList({1,2,3});
    after = solution.deleteDuplicates(head);
    assert(listToVector(after) == std::vector<int>({1,2,3}));

    head =  createList({1,1,2,2});
    after = solution.deleteDuplicates(head);
    assert(listToVector(after) == std::vector<int>({1,2}));

    head =  createList({1,2,3,3});
    after = solution.deleteDuplicates(head);
    assert(listToVector(after) == std::vector<int>({1,2,3}));

    head =  createList({1,2,2,3});
    after = solution.deleteDuplicates(head);
    assert(listToVector(after) == std::vector<int>({1,2,3}));

    head =  createList({1,1,1,2,2,3});
    after = solution.deleteDuplicates(head);
    assert(listToVector(after) == std::vector<int>({1,2,3}));
    std::cout << "All test passed" << std::endl;
    std::cout << "Done" << std::endl;
}
