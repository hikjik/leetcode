#pragma once

#include "tree_node.h"

#include <queue>

// Time: O(N)
// Space: O(N)

namespace dfs {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int minDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }
    if (!root->left || !root->right) {
      return 1 + std::max(minDepth(root->left), minDepth(root->right));
    }
    return 1 + std::min(minDepth(root->left), minDepth(root->right));
  }
};

} // namespace dfs

namespace bfs {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int minDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }
    std::queue<TreeNode *> queue{{root}};
    for (int depth = 1; !queue.empty(); ++depth) {
      for (int sz = queue.size(); sz; --sz) {
        auto *node = queue.front();
        queue.pop();

        if (!node->left && !node->right) {
          return depth;
        }

        for (auto *child : {node->left, node->right}) {
          if (child) {
            queue.push(child);
          }
        }
      }
    }
    throw;
  }
};

} // namespace bfs
