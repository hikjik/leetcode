#pragma once

#include <tree_node.h>

// Time:
// Space:

class Solution {
public:
  static bool isSymmetric(TreeNode *root) {
    if (!root) {
      return true;
    }
    return isSymmetric(root->left, root->right);
  }

private:
  static bool isSymmetric(TreeNode *left, TreeNode *right) {
    if (!left || !right) {
      return left == right;
    }

    if (left->val != right->val) {
      return false;
    }
    return isSymmetric(left->right, right->left) &&
           isSymmetric(left->left, right->right);
  }
};
