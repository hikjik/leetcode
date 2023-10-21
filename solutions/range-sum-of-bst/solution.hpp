#pragma once

#include <tree_node.h>

class Solution {
public:
  static int rangeSumBST(TreeNode *root, int low, int high) {
    if (!root) {
      return 0;
    }
    if (root->val < low) {
      return rangeSumBST(root->right, low, high);
    }
    if (root->val > high) {
      return rangeSumBST(root->left, low, high);
    }
    return root->val + rangeSumBST(root->left, low, high) +
           rangeSumBST(root->right, low, high);
  }
};
