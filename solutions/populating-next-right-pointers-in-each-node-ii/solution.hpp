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
    if (!root) {
      return nullptr;
    }
    if (root->left) {
      root->left->next = root->right ? root->right : getNext(root->next);
    }
    if (root->right) {
      root->right->next = getNext(root->next);
    }
    connect(root->right);
    connect(root->left);
    return root;
  }

private:
  static Node *getNext(Node *root) {
    for (auto *node = root; node; node = node->next) {
      if (node->left) {
        return node->left;
      }
      if (node->right) {
        return node->right;
      }
    }
    return nullptr;
  }
};

} // namespace recursive

namespace iterative {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static Node *connect(Node *root) {
    for (auto *node = root; node;) {
      Node dummy;
      for (auto *curr = &dummy; node; node = node->next) {
        if (node->left) {
          curr->next = node->left;
          curr = curr->next;
        }
        if (node->right) {
          curr->next = node->right;
          curr = curr->next;
        }
      }
      node = dummy.next;
    }
    return root;
  }
};

} // namespace iterative
