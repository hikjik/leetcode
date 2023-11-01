#pragma once

#include <tree_node.h>

/*
  101. Symmetric Tree
  https://leetcode.com/problems/symmetric-tree/
  Difficulty: Easy
  Tags: Tree, Depth-First Search, Breadth-First Search, Binary Tree
  Time:
  Space:
*/

class Solution {
public:
  static bool isSymmetric(TreeNode *root) {
    if (!root) {
      return true;
    }
    return isSymmetric(root->left, root->right);
  }

private:
  static bool isSymmetric(TreeNode *left, TreeNode *right) {
    if (!left || !right) {
      return left == right;
    }

    if (left->val != right->val) {
      return false;
    }
    return isSymmetric(left->right, right->left) &&
           isSymmetric(left->left, right->right);
  }
};
