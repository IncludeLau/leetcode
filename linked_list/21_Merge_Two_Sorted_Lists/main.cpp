#include <iostream>
#include <vector>
#include "Solution.h"

using namespace std;
int main() {
    std::function<ListNode*(ListNode*, ListNode*)> f;

    f = Solution::mergeTwoListsV2;

    ListNode* h1 = createList({1,3,5});
    ListNode* h2 = createList({2,3,6});

    assert(listToVector(f(h1 , h2)) == std::vector<int>({1,2,3,3,5,6}));

    h1 = createList({});
    h2 = createList({2,3,6});

    assert(listToVector(f(h1 , h2)) == std::vector<int>({2,3,6}));

    h1 = createList({});
    h2 = createList({});

    assert(listToVector(f(h1 , h2)) == std::vector<int>({}));

    h1 = createList({1,2,3});
    h2 = createList({1,2,3});

    assert(listToVector(f(h1 , h2)) == std::vector<int>({1,1,2,2,3,3}));

    std::cout << "All test passed" << std::endl;
}
