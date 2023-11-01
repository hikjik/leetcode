#pragma once

#include <tree_node.h>

/*
  2331. Evaluate Boolean Binary Tree
  https://leetcode.com/problems/evaluate-boolean-binary-tree/
  Difficulty: Easy
  Tags: Tree, Depth-First Search, Binary Tree
  Time:
  Space:
*/

class Solution {
public:
  static bool evaluateTree(TreeNode *root) {
    switch (root->val) {
    case 0:
      return false;
    case 1:
      return true;
    case 2:
      return evaluateTree(root->left) || evaluateTree(root->right);
    case 3:
      return evaluateTree(root->left) && evaluateTree(root->right);
    default:
      throw;
    }
  }
};
