#include <iostream>

#include "Solution.h"

using namespace std;

int main() {
    Solution solution;

    ListNode* head, * after;

    head =  createList({});
    after = solution.partition(head,3);
    assert(listToVector(after) == std::vector<int>({}));

    head =  createList({1});
    after = solution.partition(head,3);
    assert(listToVector(after) == std::vector<int>({1}));

    head =  createList({1,2,3,1,5,3,2});
    after = solution.partition(head, 3);
    assert(listToVector(after) == std::vector<int>({1,2,1,2,3,5,3}));

    head =  createList({1,1,2,2});
    after = solution.partition(head, 3);
    assert(listToVector(after) == std::vector<int>({1,1,2,2}));

    head =  createList({3,3,4,3,5});
    after = solution.partition(head,3);
    assert(listToVector(after) == std::vector<int>({3,3,4,3,5}));

    head =  createList({2,1});
    after = solution.partition(head,2);
    assert(listToVector(after) == std::vector<int>({1,2}));

    std::cout << "All test passed" << std::endl;
    std::cout << "Done" << std::endl;
}
