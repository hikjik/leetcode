#pragma once

#include <climits>

#include <tree_node.h>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int largestBSTSubtree(TreeNode *root) { return dfs(root).size; }

private:
  struct DfsData {
    int min;
    int max;
    int size;
  };

  static DfsData dfs(TreeNode *node) {
    if (!node) {
      return {INT_MAX, INT_MIN, 0};
    }
    const auto left = dfs(node->left);
    const auto right = dfs(node->right);
    if (left.max < node->val && node->val < right.min) {
      return {
          std::min(left.min, node->val),
          std::max(right.max, node->val),
          1 + left.size + right.size,
      };
    }
    return {INT_MIN, INT_MAX, std::max(left.size, right.size)};
  }
};
