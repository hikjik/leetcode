#pragma once

#include <unordered_set>

#include <tree_node.h>

// Time: O(QlogT)
// Space: O(1)

namespace hash_table {

// Time: O(N+Q)
// Space: O(N)
class FindElements {
public:
  // O(N)
  FindElements(TreeNode *root) { recover(root, 0); }

  // O(1)
  bool find(int target) const { return values.contains(target); }

private:
  void recover(TreeNode *node, int x) {
    if (!node) {
      return;
    }
    values.insert(x);
    recover(node->left, 2 * x + 1);
    recover(node->right, 2 * x + 2);
  }

  std::unordered_set<int> values;
};

} // namespace hash_table

namespace bit {

// Time: O(QlogT)
// Space: O(1)
class FindElements {
public:
  // O(1)
  FindElements(TreeNode *root) : root(root) {}

  // O(logT)
  bool find(int target) const {
    int x = 0, h = 0;
    for (; target; target = (target - 1) / 2, ++h) {
      x = x << 1 | target & 1;
    }

    auto *node = root;
    while (h-- && node) {
      node = x & 1 ? node->left : node->right;
      x >>= 1;
    }
    return node;
  }

private:
  TreeNode *root;
};

} // namespace bit
