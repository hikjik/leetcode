#pragma once

#include <tree_node.h>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int amountOfTime(TreeNode *root, int start) {
    int ans = 0;
    amountOfTime(root, start, &ans);
    return ans;
  }

  static int amountOfTime(TreeNode *root, int start, int *ans) {
    if (!root) {
      return 0;
    }
    const auto leftDepth = amountOfTime(root->left, start, ans);
    const auto rightDepth = amountOfTime(root->right, start, ans);
    if (root->val == start) {
      *ans = std::max({*ans, leftDepth, rightDepth});
      return -1;
    }
    if (leftDepth >= 0 && rightDepth >= 0) {
      return 1 + std::max(leftDepth, rightDepth);
    }
    *ans = std::max(*ans, std::abs(leftDepth) + std::abs(rightDepth));
    return std::min(leftDepth, rightDepth) - 1;
  }
};
