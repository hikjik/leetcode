#pragma once

#include <tree_node.h>

/*
  2236. Root Equals Sum of Children
  https://leetcode.com/problems/root-equals-sum-of-children/
  Difficulty: Easy
  Tags: Tree, Binary Tree
  Time:
  Space:
*/

class Solution {
public:
  static bool checkTree(TreeNode *root) {
    return root->val == root->left->val + root->right->val;
  }
};
