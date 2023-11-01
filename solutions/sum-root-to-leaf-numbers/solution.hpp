#pragma once

#include <tree_node.h>

/*
  129. Sum Root to Leaf Numbers
  https://leetcode.com/problems/sum-root-to-leaf-numbers/
  Difficulty: Medium
  Tags: Tree, Depth-First Search, Binary Tree
  Time:
  Space:
*/

class Solution {
public:
  static int sumNumbers(TreeNode *root) { return sumNumbers(root, 0); }

private:
  static int sumNumbers(TreeNode *root, int value) {
    if (!root) {
      return 0;
    }

    value = value * 10 + root->val;
    if (!root->left && !root->right) {
      return value;
    }

    return sumNumbers(root->left, value) + sumNumbers(root->right, value);
  }
};
