#pragma once

// Time: O(N)
// Space: O(N)

#include <tree_node_with_parent.h>

#include <unordered_set>

namespace hash_set {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static Node *lowestCommonAncestor(Node *p, Node *q) {
    std::unordered_set<Node *> nodes;
    for (auto *node = p; node; node = node->parent) {
      nodes.insert(node);
    }
    for (auto *node = q; node; node = node->parent) {
      if (nodes.contains(node)) {
        return node;
      }
    }
    return nullptr;
  }
};

} // namespace hash_set

namespace opt {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static Node *lowestCommonAncestor(Node *p, Node *q) {
    const auto pDepth = getDepth(p);
    const auto qDepth = getDepth(q);
    if (pDepth < qDepth) {
      std::swap(p, q);
    }
    for (int i = 0; i < std::abs(pDepth - qDepth); ++i) {
      p = p->parent;
    }
    while (p != q) {
      p = p->parent;
      q = q->parent;
    }
    return p;
  }

private:
  static int getDepth(Node *node) {
    int depth = 0;
    for (; node; node = node->parent) {
      ++depth;
    }
    return depth;
  }
};

} // namespace opt
