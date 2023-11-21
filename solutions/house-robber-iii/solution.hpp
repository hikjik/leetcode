#pragma once

#include <tree_node.h>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int rob(TreeNode *root) {
    const auto [rob, notRob] = dfs(root);
    return std::max(rob, notRob);
  }

private:
  struct RobOrNot {
    int rob;
    int notRob;
  };

  static RobOrNot dfs(TreeNode *root) {
    if (!root) {
      return {0, 0};
    }
    const auto left = dfs(root->left);
    const auto right = dfs(root->right);
    return {
        root->val + left.notRob + right.notRob,
        std::max(left.rob, left.notRob) + std::max(right.rob, right.notRob),
    };
  }
};
