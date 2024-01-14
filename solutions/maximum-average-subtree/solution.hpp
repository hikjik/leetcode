#pragma once

#include <tree_node.h>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static double maximumAverageSubtree(TreeNode *root) {
    double ans = 0.0;
    dfs(root, &ans);
    return ans;
  }

private:
  struct SumAndCount {
    int sum;
    int cnt;
  };

  static SumAndCount dfs(TreeNode *node, double *ans) {
    if (!node) {
      return {0, 0};
    }
    const auto left = dfs(node->left, ans);
    const auto right = dfs(node->right, ans);
    const int sum = left.sum + right.sum + node->val;
    const int cnt = left.cnt + right.cnt + 1;
    *ans = std::max(*ans, sum * 1.0 / cnt);
    return {sum, cnt};
  }
};
