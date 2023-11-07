#pragma once

#include <ranges>
#include <vector>

#include <tree_node.h>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static std::vector<std::vector<int>> levelOrderBottom(TreeNode *root) {
    if (!root) {
      return {};
    }

    std::vector<std::vector<int>> levels;
    std::queue<TreeNode *> queue{{root}};
    while (!queue.empty()) {
      std::vector<int> level(queue.size());
      for (int i = 0; i < std::ssize(level); ++i) {
        auto *node = queue.front();
        queue.pop();

        level[i] = node->val;

        for (auto *child : {node->left, node->right}) {
          if (child) {
            queue.push(child);
          }
        }
      }
      levels.push_back(std::move(level));
    }
    std::ranges::reverse(levels);
    return levels;
  }
};
