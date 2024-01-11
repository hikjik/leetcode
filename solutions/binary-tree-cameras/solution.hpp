#pragma once

#include <tree_node.h>

#include <functional>
#include <unordered_set>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  enum State {
    kNotCovered,
    kCoveredNoCamera,
    kCoveredWithCamera,
  };

  static int minCameraCover(TreeNode *root) {
    int ans = 0;
    std::function<State(TreeNode *)> dfs = [&](TreeNode *node) {
      if (!node) {
        return kCoveredNoCamera;
      }
      const auto left = dfs(node->left);
      const auto right = dfs(node->right);
      if (left == kNotCovered || right == kNotCovered) {
        ++ans;
        return kCoveredWithCamera;
      }
      if (left == kCoveredWithCamera || right == kCoveredWithCamera) {
        return kCoveredNoCamera;
      }
      return kNotCovered;
    };
    return (dfs(root) == kNotCovered) + ans;
  }
};
