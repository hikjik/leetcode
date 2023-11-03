#pragma once

#include <tree_node.h>

// Time:
// Space:

class Solution {
public:
  static int longestZigZag(TreeNode *root) {
    int max_length = 0;
    dfs(root, true, 0, &max_length);
    dfs(root, false, 0, &max_length);
    return max_length;
  }

private:
  static void dfs(TreeNode *node, bool is_left_child, int length,
                  int *max_length) {
    if (!node) {
      return;
    }

    *max_length = std::max(*max_length, length);

    if (is_left_child) {
      dfs(node->left, true, 1, max_length);
      dfs(node->right, false, length + 1, max_length);
    } else {
      dfs(node->left, true, length + 1, max_length);
      dfs(node->right, false, 1, max_length);
    }
  }
};
