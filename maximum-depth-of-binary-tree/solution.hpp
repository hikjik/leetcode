#pragma once

#include "tree_node.hpp"

#include <algorithm>

class Solution {
public:
  static int maxDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }
    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
};
