//
// Created by 刘新军 on 2018/6/25.
//

#include <iostream>
#include "Solution.h"
using namespace std;

int main() {
    Solution solution;
    vector<int> v = {-1};
    assert(solution.maxSubArrayV2(v) == -1);
    v = {};
    assert(solution.maxSubArrayV2(v) == 0);
    v = {-2,1,-3,4,-1,2,1,-5,4};
    assert(solution.maxSubArrayV2(v) == 6);

    cout << "all test pasted" << endl;
    cout << "done" << endl;
}
