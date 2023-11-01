#pragma once

#include <tree_node.h>

/*
  222. Count Complete Tree Nodes
  https://leetcode.com/problems/count-complete-tree-nodes/
  Difficulty: Easy
  Tags: Binary Search, Bit Manipulation, Tree, Binary Tree
  Time:
  Space:
*/

class Solution {
public:
  static int countNodes(TreeNode *root) {
    int left_height = 0;
    for (auto node = root; node; node = node->left) {
      left_height++;
    }

    int right_height = 0;
    for (auto node = root; node; node = node->right) {
      right_height++;
    }

    if (left_height == right_height) {
      return (1 << left_height) - 1;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};
