#pragma once

#include <tree_node.h>

// Time:
// Space:

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
