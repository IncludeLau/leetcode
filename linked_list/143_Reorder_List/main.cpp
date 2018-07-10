#include <iostream>
#include "Solution.h"

using namespace std;


int main(){
    Solution solution;

    ListNode* head, *after;

    head = createList({});
    after = solution.reorderList(head);
    assert(listToVector(after) == std::vector<int>({}));

    head = createList({1});
    after = solution.reorderList(head);
    assert(listToVector(after) == std::vector<int>({1}));

    head = createList({1,2});
    after = solution.reorderList(head);
    assert(listToVector(after) == std::vector<int>({1,2}));

    head = createList({1,2,3});
    after = solution.reorderList(head);
    assert(listToVector(after) == std::vector<int>({1,3,2}));

    head = createList({1,2,3,4});
    after = solution.reorderList(head);
    assert(listToVector(after) == std::vector<int>({1,4,2,3}));

    head = createList({1,2,3,4,5});
    after = solution.reorderList(head);
    assert(listToVector(after) == std::vector<int>({1,5,2,4,3}));

    head = createList({1,2,3,4,5,6});
    after = solution.reorderList(head);
    assert(listToVector(after) == std::vector<int>({1,6,2,5,3,4}));

    cout << "All test passed!" << endl;
}