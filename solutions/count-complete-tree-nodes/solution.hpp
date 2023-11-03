#pragma once

#include <tree_node.h>

// Time:
// Space:

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
