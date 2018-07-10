#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <utility>
#include <map>


using std::vector;
using std::stack;
using std::queue;
using std::string;
using std::pair;
using std::map;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    int climbStairs(int n);
    int reverse(int x);
    int firstUniqChar(string s);
    bool isAnagram(string s, string t);
    bool isPalindrome(string s);
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
    ListNode* removeElements(ListNode* head, int val);
    bool isPalindrome(ListNode* head);
    ListNode* reverseList(ListNode* head);
    ListNode* oddEvenList(ListNode* head);
    int numTrees(int n);
    bool isValidBst(TreeNode* root);
    bool isSameTree(TreeNode* p, TreeNode* q);
    bool isSymmetric(TreeNode* root);
    int maxDepth(TreeNode* root);
    bool isBalanced(TreeNode* root);
    int minDepth(TreeNode* root);
    int maxSubArray(vector<int>& nums);
    vector<int> maxSlidingWindow(vector<int>& nums, int k);
    vector<int> singleNumber(vector<int>& nums);
    string decodeString(string s);
    int coinChange(vector<int>& coins, int amount);
    bool isOneBitCharacter(vector<int>& bits);

    bool hasAlternatingBits(int n);
    int minCostClimbingStairs(vector<int>& cost);
    int minDistance(string word1, string word2);
    vector<int> diffWaysToCompute(string input);
    int minSteps(int n);
    vector<int> twoSum(vector<int>& numbers, int target);
    string complexNumberMultiply(string a, string b);
private:
    const vector<int> ways(const string& input);
    map<string, vector<int>> m_;
};

#endif //LEETCODE_SOLUTION_H
