#pragma once

#include <tree_node.h>

// Time:
// Space:

class Solution {
public:
  static int sumRootToLeaf(TreeNode *root) { return sumRootToLeaf(0, root); }

private:
  static int sumRootToLeaf(int val, TreeNode *node) {
    if (!node) {
      return 0;
    }

    val = val * 2 + node->val;
    if (!node->left && !node->right) {
      return val;
    }

    return sumRootToLeaf(val, node->left) + sumRootToLeaf(val, node->right);
  }
};
