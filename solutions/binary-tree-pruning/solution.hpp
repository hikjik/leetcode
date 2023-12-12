#pragma once

#include <tree_node.h>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static TreeNode *pruneTree(TreeNode *root) {
    if (!root) {
      return nullptr;
    }
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if (!root->left && !root->right && !root->val) {
      return nullptr;
    }
    return root;
  }
};
