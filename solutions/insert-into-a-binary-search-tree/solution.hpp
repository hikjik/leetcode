#pragma once

#include <tree_node.h>

class Solution {
public:
  static TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (!root) {
      return new TreeNode(val);
    }

    if (val < root->val) {
      root->left = insertIntoBST(root->left, val);
    } else {
      root->right = insertIntoBST(root->right, val);
    }
    return root;
  }
};
