#pragma once

#include <tree_node.h>

#include <algorithm>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int maxDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }
    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
  }
};
