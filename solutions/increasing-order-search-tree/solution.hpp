#pragma once

#include <tree_node.h>

class Solution {
public:
  static TreeNode *increasingBST(TreeNode *root, TreeNode *tail = nullptr) {
    if (!root) {
      return tail;
    }
    auto *left = root->left;
    root->right = increasingBST(root->right, tail);
    root->left = nullptr;
    return increasingBST(left, root);
  }
};
