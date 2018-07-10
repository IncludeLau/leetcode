#include <iostream>
#include "Solution.h"

using namespace std;

int main() {
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    Solution solution;
    solution.deleteNode(&node3);
    assert(listToVector(&node1) == std::vector<int>({1,2,4}));
    solution.deleteNode(&node2);
    assert(listToVector(&node1) == std::vector<int>({1,4}));

    std::cout << "All test passed" << std::endl;
    std::cout << "DONE" << std::endl;
}

