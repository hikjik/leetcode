#pragma once

#include <tree_node.h>

class Solution {
public:
  static bool evaluateTree(TreeNode *root) {
    switch (root->val) {
    case 0:
      return false;
    case 1:
      return true;
    case 2:
      return evaluateTree(root->left) || evaluateTree(root->right);
    case 3:
      return evaluateTree(root->left) && evaluateTree(root->right);
    default:
      throw;
    }
  }
};
