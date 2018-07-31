//
// Created by 刘新军 on 2018/7/3.
//

#ifndef LEETCODE_TREENODE_H
#define LEETCODE_TREENODE_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif //LEETCODE_TREENODE_H
