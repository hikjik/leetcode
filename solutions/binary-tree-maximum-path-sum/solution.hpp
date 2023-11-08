#pragma once

#include <tree_node.h>

#include <limits>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int maxPathSum(TreeNode *root) {
    auto ans = std::numeric_limits<int>::min();
    maxPathSum(root, &ans);
    return ans;
  }

private:
  static int maxPathSum(TreeNode *root, int *ans) {
    if (!root) {
      return 0;
    }

    const auto left = std::max(0, maxPathSum(root->left, ans));
    const auto right = std::max(0, maxPathSum(root->right, ans));
    *ans = std::max(*ans, root->val + left + right);
    return root->val + std::max(left, right);
  }
};
