/**
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]

进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 */

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <stack>
#include "../TreeNode.h"


using namespace std;
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) return res;
        inorderTraversal(root->left);
        res.push_back(root->val);
        inorderTraversal(root->right);
        return res;
    }

    vector<int> inorderTraversal2(TreeNode* root) {
        if(root == nullptr) return res;
        stack<TreeNode*> s;
        while (!s.empty() || root) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root =  s.top();
            s.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
private:
    vector<int> res;
};


#endif //LEETCODE_SOLUTION_H
