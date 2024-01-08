#pragma once

#include <node.h>

#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static Node *findRoot(const std::vector<Node *> &tree) {
    uintptr_t ptr = 0;
    for (auto *node : tree) {
      ptr ^= reinterpret_cast<uintptr_t>(node);
      for (auto *child : node->children) {
        ptr ^= reinterpret_cast<uintptr_t>(child);
      }
    }
    return reinterpret_cast<Node *>(ptr);
  }
};
