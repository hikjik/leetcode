#pragma once

#include <tree_node_with_next.h>

// Time: O(N)
// Space: O(1)

namespace recursive {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static Node *connect(Node *root) {
    if (!root || !root->left) {
      return root;
    }
    root->left->next = root->right;
    if (root->next) {
      root->right->next = root->next->left;
    }
    connect(root->left);
    connect(root->right);
    return root;
  }
};

} // namespace recursive

namespace iterative {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static Node *connect(Node *root) {
    for (auto *node = root; node; node = node->left) {
      for (auto *curr = node; curr && curr->left; curr = curr->next) {
        curr->left->next = curr->right;
        if (curr->next) {
          curr->right->next = curr->next->left;
        }
      }
    }
    return root;
  }
};

} // namespace iterative
