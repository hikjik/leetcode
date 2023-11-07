#pragma once

#include <tree_node.h>

#include <algorithm>
#include <cmath>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static bool isBalanced(TreeNode *root) {
    return isHeightBalanced(root).is_balanced;
  }

private:
  struct Result {
    int height;
    bool is_balanced;
  };

  static Result isHeightBalanced(TreeNode *root) {
    if (!root) {
      return {0, true};
    }
    const auto left = isHeightBalanced(root->left);
    const auto right = isHeightBalanced(root->right);
    return {
        1 + std::max(left.height, right.height),
        left.is_balanced && right.is_balanced &&
            std::abs(left.height - right.height) <= 1,
    };
  }
};
