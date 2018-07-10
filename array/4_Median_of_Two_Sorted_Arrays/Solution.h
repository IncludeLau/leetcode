/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。

请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。

示例 1:

nums1 = [1, 3]
nums2 = [2]

中位数是 2.0

示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

中位数是 (2 + 3)/2 = 2.5
 */

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>

using namespace std;
class Solution {
public:
    static double findMedianSortedArraysV1(vector<int>& nums1, vector<int>& nums2) {
        u_long m = nums1.size();
        u_long n = nums2.size();

    }

    static double findMedianSortedArraysV2(vector<int>& nums1, vector<int>& nums2) {}
};
#endif //LEETCODE_SOLUTION_H
