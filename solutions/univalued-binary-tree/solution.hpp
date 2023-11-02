#pragma once

#include <tree_node.h>

// Time:
// Space:

class Solution {
public:
  static bool isUnivalTree(TreeNode *root) {
    if (!root) {
      return true;
    }

    for (auto child : {root->left, root->right}) {
      if (child && root->val != child->val) {
        return false;
      }
    }

    return isUnivalTree(root->left) && isUnivalTree(root->right);
  }
};
