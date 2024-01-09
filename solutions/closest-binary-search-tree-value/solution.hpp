#pragma once

#include <tree_node.h>

#include <cmath>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int closestValue(TreeNode *root, double target) {
    auto ans = root->val;
    for (auto *node = root; node;) {
      if (std::abs(node->val - target) < std::abs(ans - target) ||
          std::abs(node->val - target) == std::abs(ans - target) &&
              node->val < ans) {
        ans = node->val;
      }
      node = target < node->val ? node->left : node->right;
    }
    return ans;
  }
};
