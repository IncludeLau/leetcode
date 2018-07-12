/**
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba"也是一个有效答案。

示例 2：

输入: "cbbd"
输出: "bb"
 */

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H


/**
 * 此题解法的核心思想在于遍历字符串的某一位置时向两边扩张
 * 再遍历的开始需要处理最中间连续相同字符的情况
 * 遍历的过程中根据遍历得到的最大长度来选择更新最长回文子串的起始位置和最大长度
 * 一个小优化的地方：在遍历的末期，让发现剩下的长度不急当前最大长度的一半时可中止遍历
 *
 * 时间复杂度： O(n^2)
 * 空间复杂度： O(1)
 */

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if(s.empty() || s.length() == 1) return s;
        int min_start = 0, max_len = 1;
        for(int i = 0; i< s.size();) {
            if(s.size() - i < max_len >> 1) break;
            int j = i, k = i;
            while (k < s.size() - 1 && s[k+1] == s[k]) k++;
            i = k + 1;
            while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j;}
            int new_len = k - j + 1;
            if(new_len > max_len) {
                min_start = j;
                max_len = new_len;
            }
        }
        return s.substr(static_cast<u_long >(min_start), static_cast<u_long >(max_len));
    }
};

#endif //LEETCODE_SOLUTION_H
