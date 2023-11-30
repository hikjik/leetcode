#pragma once

#include <vector>

#include <tree_node.h>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static TreeNode *constructMaximumBinaryTree(const std::vector<int> &nums) {
    std::vector<TreeNode *> nodes;
    for (auto a : nums) {
      auto *node = new TreeNode(a);
      while (!nodes.empty() && nodes.back()->val < a) {
        node->left = nodes.back();
        nodes.pop_back();
      }
      if (!nodes.empty()) {
        nodes.back()->right = node;
      }
      nodes.push_back(node);
    }
    return nodes.front();
  }
};
