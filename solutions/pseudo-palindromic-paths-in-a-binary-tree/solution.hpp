#pragma once

#include <tree_node.h>

#include <bit>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int pseudoPalindromicPaths(TreeNode *node, unsigned mask = 0) {
    if (!node) {
      return 0;
    }
    mask ^= 1 << node->val;
    return (!node->left && !node->right && std::popcount(mask) <= 1) +
           pseudoPalindromicPaths(node->left, mask) +
           pseudoPalindromicPaths(node->right, mask);
  }
};
