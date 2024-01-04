#pragma once

#include <node.h>

#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static Node *cloneTree(Node *root) {
    if (root) {
      std::vector<Node *> children;
      for (auto *child : root->children) {
        children.push_back(cloneTree(child));
      }
      return new Node(root->val, std::move(children));
    }
    return nullptr;
  }
};
