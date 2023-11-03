#pragma once

#include <tree_node.h>

// Time:
// Space:

class Solution {
public:
  static bool hasPathSum(TreeNode *root, int target) {
    if (!root) {
      return false;
    }

    if (isLeaf(root)) {
      return target == root->val;
    }

    target -= root->val;
    return hasPathSum(root->left, target) || hasPathSum(root->right, target);
  }

private:
  static bool isLeaf(TreeNode *node) {
    return node && !node->left && !node->right;
  }
};
