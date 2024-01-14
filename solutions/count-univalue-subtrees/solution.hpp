#pragma once

#include <tree_node.h>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int countUnivalSubtrees(TreeNode *root) {
    int ans = 0;
    dfs(root, INT_MAX, &ans);
    return ans;
  }

private:
  static bool dfs(TreeNode *node, int val, int *ans) {
    if (!node) {
      return true;
    }
    if (dfs(node->left, node->val, ans) & dfs(node->right, node->val, ans)) {
      ++*ans;
      return node->val == val;
    }
    return false;
  }
};
