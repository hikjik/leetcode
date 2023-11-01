#pragma once

#include <tree_node.h>

#include <algorithm>

/*
  104. Maximum Depth of Binary Tree
  https://leetcode.com/problems/maximum-depth-of-binary-tree/
  Difficulty: Easy
  Tags: Tree, Depth-First Search, Breadth-First Search, Binary Tree
  Time:
  Space:
*/

class Solution {
public:
  static int maxDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }
    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
};
