#pragma once

#include <tree_node.h>

#include <utility>

class Solution {
public:
  static TreeNode *invertTree(TreeNode *root) {
    if (root) {
      std::swap(root->left, root->right);
      invertTree(root->left);
      invertTree(root->right);
    }
    return root;
  }
};
