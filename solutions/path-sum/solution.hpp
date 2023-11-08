#pragma once

#include <tree_node.h>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static bool hasPathSum(TreeNode *root, int target) {
    if (!root) {
      return false;
    }
    if (!root->left && !root->right) {
      return target == root->val;
    }
    return hasPathSum(root->left, target - root->val) ||
           hasPathSum(root->right, target - root->val);
  }
};
