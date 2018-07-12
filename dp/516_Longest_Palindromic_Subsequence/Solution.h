/**
给定一个字符串s，找到其中最长的回文子序列。可以假设s的最大长度为1000。

示例 1:
输入:

"bbbab"

输出:

4

一个可能的最长回文子序列为 "bbbb"。

示例 2:
输入:

"cbbd"

输出:

2

一个可能的最长回文子序列为 "bb"。
 */

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <map>
#include <vector>

class Solution {
public:
    /**
     * str[0...n-1]是给定的字符串序列，长度为n，假设lps(0,n-1)表示序列str[0...n-1]的最长回文子序列的长度。
     * 1.如果str的最后一个元素和第一个元素是相同的，则有：lps(0,n-1)=lps(1,n-2)+2；例如字符串序列“AABACACBA”，
     * 第一个元素和最后一个元素相同，其中lps(1,n-2)表示红色部分的最长回文子序列的长度；
     * 2.如果str的最后一个元素和第一个元素是不相同的，则有：lps(0,n-1)=max(lps(1,n-1),lps(0,n-2))；
     * 例如字符串序列“ABACACB”，其中lps(1,n-1)表示去掉第一元素的子序列，lps(0,n-2)表示去掉最后一个元素的子序列。
     */
    int longestPalindromeSubseq(std::string s) {
        if(_m.count(s)) return _m[s];
        if(s.empty()) return  0;
        if(s.size() == 1) return 1;
        int l;
        if(s[0] == s[s.size()-1]) {
            l = longestPalindromeSubseq(s.substr(1, s.size() - 2)) + 2;
        }else {
            l = std::max(longestPalindromeSubseq(s.substr(1)), longestPalindromeSubseq(s.substr(0, s.size() - 1)));
        }
        _m[s] = l;
        return l;
    }

    int longestPalindromeSubseq1(std::string str){
        int n=str.length();
        std::vector<std::vector<int> > dp(n,std::vector<int>(n));

        for(int j=0;j<n;j++){
            dp[j][j]=1;
            for(int i=j-1;i>=0;i--){
                if(str[i]==str[j])
                    dp[i][j]=dp[i+1][j-1]+2;
                else
                    dp[i][j]=std::max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }

private:
    std::map<std::string, int> _m;
};

#endif //LEETCODE_SOLUTION_H
