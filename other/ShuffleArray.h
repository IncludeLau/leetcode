//
// Created by 刘新军 on 2018/4/24.
//

#ifndef LEETCODE_SHUFFLEARRAY_H
#define LEETCODE_SHUFFLEARRAY_H

#include <vector>
using std::vector;
class ShuffleArray{
public:
    explicit ShuffleArray(vector<int> nums) {
        _nums = nums;
        _size = _nums.size();
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return _nums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> tem(_nums);
        int len = _nums.size();
        for(int i = 0; i < len; i++)
        {
            int pos = std::rand()%(len-i);
            std::swap(tem[i+pos], tem[i]);
        }
        return tem;
    }

private:
    vector<int> _nums;
    size_t _size;
};

#endif //LEETCODE_SHUFFLEARRAY_H
