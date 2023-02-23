#pragma once

#include <tree_node_with_next.h>

class Solution {
public:
  static Node *connect(Node *root) {
    if (!root) {
      return nullptr;
    }

    if (root->left) {
      root->left->next = root->right;
    }

    if (root->right && root->next) {
      root->right->next = root->next->left;
    }

    connect(root->left);
    connect(root->right);

    return root;
  }
};
