#include <iostream>
#include "Solution.h"

using namespace std;


int main(){
    Solution solution;

    ListNode* head = createList({1,2,3,4});
    assert(!solution.hasCycle(head));
    auto pair1 = createListRetTailAndHead({1,2,3,4,5,6});
    auto pair2 = createListRetTailAndHead({7,8,9});
    auto pair3 = createListRetTailAndHead({7,8,9});
    pair1.first->next = pair2.first;
    pair2.second->next = pair3.first;
    pair3.second->next = pair2.first;
    assert(pair1.first);
    cout << "All test passed!" << endl;
}