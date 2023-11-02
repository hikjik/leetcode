#pragma once

#include <tree_node.h>

#include <algorithm>

// Time:
// Space:

class Solution {
public:
  static int maxDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }
    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
};
