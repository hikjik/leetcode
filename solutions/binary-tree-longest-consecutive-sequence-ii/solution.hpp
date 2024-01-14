#pragma once

#include <tree_node.h>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int longestConsecutive(TreeNode *root) {
    int ans = 0;
    dfs(root, &ans);
    return ans;
  }

private:
  struct ConsecutivePathLengths {
    int inc;
    int dec;
  };

  static ConsecutivePathLengths dfs(TreeNode *node, int *ans) {
    int inc = 0, dec = 0;
    for (auto *child : {node->left, node->right}) {
      if (!child) {
        continue;
      }
      const auto lens = dfs(child, ans);
      if (child->val + 1 == node->val) {
        inc = std::max(inc, lens.inc);
      }
      if (child->val == node->val + 1) {
        dec = std::max(dec, lens.dec);
      }
    }

    *ans = std::max(*ans, inc + dec + 1);
    return {inc + 1, dec + 1};
  }
};
