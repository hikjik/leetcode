#pragma once

#include <tree_node.h>

/*
  112. Path Sum
  https://leetcode.com/problems/path-sum/
  Difficulty: Easy
  Tags: Tree, Depth-First Search, Breadth-First Search, Binary Tree
  Time:
  Space:
*/

class Solution {
public:
  static bool hasPathSum(TreeNode *root, int target) {
    if (!root) {
      return false;
    }

    if (isLeaf(root)) {
      return target == root->val;
    }

    target -= root->val;
    return hasPathSum(root->left, target) || hasPathSum(root->right, target);
  }

private:
  static bool isLeaf(TreeNode *node) {
    return node && !node->left && !node->right;
  }
};
