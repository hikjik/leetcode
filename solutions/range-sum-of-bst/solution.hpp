#pragma once

#include <tree_node.h>

/*
  938. Range Sum of BST
  https://leetcode.com/problems/range-sum-of-bst/
  Difficulty: Easy
  Tags: Tree, Depth-First Search, Binary Search Tree, Binary Tree
  Time:
  Space:
*/

class Solution {
public:
  static int rangeSumBST(TreeNode *root, int low, int high) {
    if (!root) {
      return 0;
    }
    if (root->val < low) {
      return rangeSumBST(root->right, low, high);
    }
    if (root->val > high) {
      return rangeSumBST(root->left, low, high);
    }
    return root->val + rangeSumBST(root->left, low, high) +
           rangeSumBST(root->right, low, high);
  }
};
