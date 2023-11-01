#pragma once

#include <tree_node.h>

/*
  114. Flatten Binary Tree to Linked List
  https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
  Difficulty: Medium
  Tags: Linked List, Stack, Tree, Depth-First Search, Binary Tree
  Time:
  Space:
*/

class Solution {
public:
  static void flatten(TreeNode *root) {
    while (root) {
      if (root->left) {
        auto node = root->left;
        while (node->right) {
          node = node->right;
        }
        node->right = root->right;
        root->right = root->left;
        root->left = nullptr;
      }
      root = root->right;
    }
  }
};
