#pragma once

#include <tree_node.h>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int longestConsecutive(TreeNode *node, TreeNode *parent = nullptr,
                                int length = 0) {
    if (!node) {
      return length;
    }
    length = !parent || parent->val + 1 != node->val ? 1 : 1 + length;
    return std::max({
        length,
        longestConsecutive(node->left, node, length),
        longestConsecutive(node->right, node, length),
    });
  }
};
