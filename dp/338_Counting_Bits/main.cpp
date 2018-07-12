#include <iostream>
#include "Solution.h"

using namespace std;

int main() {
    std::function<vector<int>(int)> f = Solution::countBits3;

    assert(f(0) == vector<int>({0}));
    assert(f(1) == vector<int>({0,1}));
    assert(f(2) == vector<int>({0,1,1}));
    assert(f(3) == vector<int>({0,1,1,2}));
    assert(f(4) == vector<int>({0,1,1,2,1}));
    assert(f(5) == vector<int>({0,1,1,2,1,2}));
    assert(f(6) == vector<int>({0,1,1,2,1,2,2}));
    cout << "All test passed" << endl;
}
