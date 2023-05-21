#pragma once

#include <tree_node.h>

#include <limits>

class Solution {
public:
  static int maxPathSum(TreeNode *root) {
    int path_sum = std::numeric_limits<int>::min();
    maxPathSum(root, &path_sum);
    return path_sum;
  }

private:
  static int maxPathSum(TreeNode *root, int *path_sum) {
    if (!root) {
      return 0;
    }

    const auto left = std::max(0, maxPathSum(root->left, path_sum));
    const auto right = std::max(0, maxPathSum(root->right, path_sum));

    *path_sum = std::max(*path_sum, root->val + left + right);

    return root->val + std::max(left, right);
  }
};