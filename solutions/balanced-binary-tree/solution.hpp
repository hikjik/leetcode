#pragma once

#include <tree_node.h>

#include <algorithm>

class Solution {
public:
  static bool isBalanced(TreeNode *root) {
    if (!root) {
      return true;
    }
    return isBalanced(root->left) && isBalanced(root->right) &&
           abs(depth(root->left) - depth(root->right)) <= 1;
  }

private:
  static int depth(TreeNode *root) {
    if (!root) {
      return 0;
    }
    return 1 + std::max(depth(root->left), depth(root->right));
  }
};