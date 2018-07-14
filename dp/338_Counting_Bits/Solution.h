/**
给定一个非负整数 num。 对于范围 0 ≤ i ≤ num 中的每个数字 i ，计算其二进制数中的1的数目并将它们作为数组返回。

示例：
比如给定 num = 5 ，应该返回 [0,1,1,2,1,2].

进阶：

    给出时间复杂度为O(n * sizeof(integer)) 的解答非常容易。 但是你可以在线性时间O(n)内用一次遍历做到吗？
    要求算法的空间复杂度为O(n)。
    你能进一步完善解法吗？ 在c ++或任何其他语言中不使用任何内置函数（如c++里的 __builtin_popcount）来执行此操作。
 */

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>

class Solution {
public:
    /**
     * time: o(n^2)
     * space: o(n)
     */
    static std::vector<int> countBits1(int num) {
        std::vector<int> ret(num+1);
        for(int i = 0; i <= num; i++) {
            ret[i] = getBits(i);
        }
        return ret;
    }

    static std::vector<int> countBits2(int num) {
        std::vector<int> ret(num+1, 0);
        for(int i = 1; i<= num; i++) {
            if(ret[i] > 0) continue;
            int k = i;
            int bitNum = getBits(k);
            while (k <= num){
                ret[k] = bitNum;
                k <<= 1;
            }
        }
        return ret;
    }

    static std::vector<int> countBits3(int num) {
        std::vector<int> ret(num+1, 0);
        for ( int i = 1 ; i <= num ; i++ )
            ret[i] = ret[i>>1] + (i & 1);
        return ret;
    }

private:
    static int getBits(int i) {
        int c = 0;
        while (i) {
            i &= i-1;
            c++;
        }
        return c;
    }
};

#endif //LEETCODE_SOLUTION_H
