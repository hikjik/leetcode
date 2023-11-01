#pragma once

#include <tree_node.h>

#include <algorithm>

/*
  543. Diameter of Binary Tree
  https://leetcode.com/problems/diameter-of-binary-tree/
  Difficulty: Easy
  Tags: Tree, Depth-First Search, Binary Tree
  Time:
  Space:
*/

class Solution {
public:
  static int diameterOfBinaryTree(TreeNode *root) {
    int diameter = 0;
    depth(root, &diameter);
    return diameter;
  }

private:
  static int depth(TreeNode *root, int *diameter) {
    if (!root) {
      return 0;
    }
    const auto left = depth(root->left, diameter);
    const auto right = depth(root->right, diameter);
    *diameter = std::max(*diameter, left + right);
    return std::max(left, right) + 1;
  }
};
