#include <iostream>

#include "Solution.h"

using namespace std;

int main() {
    ListNode* h1 = createList({2});
    ListNode* h2 = createList({});
    ListNode* h3 = createList({-1});
    ListNode* h4 = createList({});
//    ListNode* h5 = createList({1,3,5});

    vector<ListNode*> v = {h1, h2, h3};
    Solution solution;
    ListNode* r = solution.mergeKLists(v);

    printList(r);

    std::cout << "Done" << std::endl;
}
