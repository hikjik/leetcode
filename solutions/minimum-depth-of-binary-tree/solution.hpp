#pragma once

#include "tree_node.h"

#include <queue>

class Solution {
public:
  static int minDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }

    std::queue<TreeNode *> queue{{root}};

    int min_depth = 0;
    while (!queue.empty()) {
      ++min_depth;
      for (int sz = queue.size(); sz; --sz) {
        auto node = queue.front();
        queue.pop();

        if (!node->left && !node->right) {
          return min_depth;
        }

        for (auto child : {node->left, node->right}) {
          if (child) {
            queue.push(child);
          }
        }
      }
    }

    throw;
  }
};
