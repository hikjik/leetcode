#pragma once

#include <tree_node.h>

// Time:
// Space:

class Solution {
private:
  TreeNode *left;
  TreeNode *right;
  TreeNode *prev;

  void traverseInOrder(TreeNode *root) {
    if (!root) {
      return;
    }

    traverseInOrder(root->left);

    if (prev && prev->val > root->val) {
      right = root;
      if (!left) {
        left = prev;
      } else {
        return;
      }
    }
    prev = root;

    traverseInOrder(root->right);
  }

public:
  void recoverTree(TreeNode *root) {
    left = right = prev = nullptr;
    traverseInOrder(root);
    std::swap(left->val, right->val);
  }
};
