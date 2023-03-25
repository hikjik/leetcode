#pragma once

#include <tree_node.h>

class Solution {
public:
  static TreeNode *deleteNode(TreeNode *root, int key) {
    if (!root) {
      return root;
    }

    if (root->val == key) {
      if (!root->left || !root->right) {
        auto new_root = !root->left ? root->right : root->left;
        delete root;
        return new_root;
      }

      if (!root->right->left) {
        auto right = root->right;
        right->left = root->left;
        delete root;
        return right;
      }

      auto curr = root, next = root->right;
      while (next->left) {
        curr = next;
        next = next->left;
      }
      curr->left = next->right;
      next->left = root->left;
      next->right = root->right;
      delete root;
      return next;
    }

    if (root->val < key) {
      root->right = deleteNode(root->right, key);
    } else {
      root->left = deleteNode(root->left, key);
    }
    return root;
  }
};
