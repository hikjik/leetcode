#pragma once

#include <tree_node_with_next.h>

class Solution {
public:
  static Node *connect(Node *root) {
    auto node = root;
    while (node) {
      Node dummy;
      for (auto tail = &dummy; node; node = node->next) {
        if (node->left) {
          tail->next = node->left;
          tail = tail->next;
        }
        if (node->right) {
          tail->next = node->right;
          tail = tail->next;
        }
      }
      node = dummy.next;
    }
    return root;
  }
};
