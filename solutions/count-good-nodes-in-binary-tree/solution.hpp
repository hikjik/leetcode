#pragma once

#include <tree_node.h>

#include <climits>

class Solution {
public:
  static int goodNodes(TreeNode *root) { return dfs(INT_MIN, root); }

private:
  static int dfs(int max, TreeNode *node) {
    if (!node) {
      return 0;
    }
    int good = node->val >= max;
    max = std::max(max, node->val);
    return good + dfs(max, node->left) + dfs(max, node->right);
  }
};
