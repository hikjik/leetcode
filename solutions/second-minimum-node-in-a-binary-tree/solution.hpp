#pragma once

#include <tree_node.h>

/*
  671. Second Minimum Node In a Binary Tree
  https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/
  Difficulty: Easy
  Tags: Tree, Depth-First Search, Binary Tree
  Time:
  Space:
*/

class Solution {
public:
  static int findSecondMinimumValue(TreeNode *root) {
    return findSecondMinimumValue(root, root->val);
  }

private:
  static int findSecondMinimumValue(TreeNode *node, int min1) {
    if (!node) {
      return -1;
    }
    if (node->val > min1) {
      return node->val;
    }
    const auto left = findSecondMinimumValue(node->left, min1);
    const auto right = findSecondMinimumValue(node->right, min1);
    if (left != -1 && right != -1) {
      return std::min(left, right);
    }
    return std::max(left, right);
  };
};
