#include <iostream>
#include "Solution.h"

using namespace std;

int main() {
    Solution solution;

    assert(solution.twoSum({2, 7, 11, 15}, 9) == std::vector<int>({1,0}));
}