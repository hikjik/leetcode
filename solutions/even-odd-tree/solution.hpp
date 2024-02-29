#pragma once

#include <ranges>
#include <vector>

#include <tree_node.h>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static bool isEvenOddTree(TreeNode *root) {
    std::vector<TreeNode *> nodes{root};
    for (int level = 0; !nodes.empty(); ++level) {
      if (std::ranges::any_of(nodes, [=](TreeNode *node) {
            return (node->val & 1) == (level & 1);
          })) {
        return false;
      }

      if (!std::ranges::is_sorted(nodes, [=](TreeNode *lhs, TreeNode *rhs) {
            return level & 1 ? lhs->val >= rhs->val : lhs->val <= rhs->val;
          })) {
        return false;
      }

      std::vector<TreeNode *> next;
      for (auto *node : nodes) {
        for (auto *child : {node->left, node->right}) {
          if (child) {
            next.push_back(child);
          }
        }
      }
      nodes.swap(next);
    }
    return true;
  }
};
