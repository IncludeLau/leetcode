/*
中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

    void addNum(int num) - 从数据流中添加一个整数到数据结构中。
    double findMedian() - 返回目前所有元素的中位数。

示例：

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3)
findMedian() -> 2
*/

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

#ifndef LEETCODE_MEDIANFINDER_H
#define LEETCODE_MEDIANFINDER_H

#include <queue>
#include <vector>

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() = default;

    void addNum(int num) {
        ++n;
        if (n % 2) {
            if(bigger.empty() || num <= bigger.top()) {
                smaller.push(num);
            }else {
                smaller.push(bigger.top());
                bigger.pop();
                bigger.push(num);
            }
        }else {
            if(num >= smaller.top()) {
                bigger.push(num);
            }else{
                bigger.push(smaller.top());
                smaller.pop();
                smaller.push(num);
            }
        }
    }

    double findMedian() {
        if(n % 2) return static_cast<double >(smaller.top());
        return static_cast<double >(smaller.top() + bigger.top()) / 2;
    }

private:
    int n = 0;
    std::priority_queue<int, std::vector<int>, std::less<int>> smaller;
    std::priority_queue<int, std::vector<int>, std::greater<int>> bigger;
};
#endif //LEETCODE_MEDIANFINDER_H
