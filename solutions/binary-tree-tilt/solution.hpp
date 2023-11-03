#pragma once

#include <tree_node.h>

// Time:
// Space:

class Solution {
public:
  static int findTilt(TreeNode *root) {
    int sum = 0;
    findTilt(root, &sum);
    return sum;
  }

private:
  static int findTilt(TreeNode *root, int *sum) {
    if (!root) {
      return 0;
    }
    const auto left = findTilt(root->left, sum);
    const auto right = findTilt(root->right, sum);
    *sum += std::abs(left - right);
    return root->val + left + right;
  }
};
