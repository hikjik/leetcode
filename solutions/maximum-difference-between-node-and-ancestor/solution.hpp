#pragma once

#include <climits>

#include <tree_node.h>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int maxAncestorDiff(TreeNode *root, int min = INT_MAX,
                             int max = INT_MIN) {
    if (!root) {
      return 0;
    }
    min = std::min(min, root->val), max = std::max(max, root->val);
    return std::max({
        max - min,
        maxAncestorDiff(root->left, min, max),
        maxAncestorDiff(root->right, min, max),
    });
  }
};
