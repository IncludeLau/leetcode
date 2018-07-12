#include <iostream>
#include "Solution.h"

using namespace std;

int main() {
    Solution solution;

    assert(solution.longestPalindrome("").empty());
    assert(solution.longestPalindrome("a") == "a");
    assert(solution.longestPalindrome("ab") == "a");
    assert(solution.longestPalindrome("abb") == "bb");
    assert(solution.longestPalindrome("aabb") == "aa");
    assert(solution.longestPalindrome("abcba") == "abcba");
    cout << "All test passed" << endl;
}
