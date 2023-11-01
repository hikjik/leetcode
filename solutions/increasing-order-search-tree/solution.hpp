#pragma once

#include <tree_node.h>

/*
  897. Increasing Order Search Tree
  https://leetcode.com/problems/increasing-order-search-tree/
  Difficulty: Easy
  Tags: Stack, Tree, Depth-First Search, Binary Search Tree, Binary Tree
  Time:
  Space:
*/

class Solution {
public:
  static TreeNode *increasingBST(TreeNode *root, TreeNode *tail = nullptr) {
    if (!root) {
      return tail;
    }
    auto *left = root->left;
    root->right = increasingBST(root->right, tail);
    root->left = nullptr;
    return increasingBST(left, root);
  }
};
