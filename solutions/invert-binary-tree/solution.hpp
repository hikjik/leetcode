#pragma once

#include <tree_node.h>

#include <utility>

/*
  226. Invert Binary Tree
  https://leetcode.com/problems/invert-binary-tree/
  Difficulty: Easy
  Tags: Tree, Depth-First Search, Breadth-First Search, Binary Tree
  Time:
  Space:
*/

class Solution {
public:
  static TreeNode *invertTree(TreeNode *root) {
    if (root) {
      std::swap(root->left, root->right);
      invertTree(root->left);
      invertTree(root->right);
    }
    return root;
  }
};
