#pragma once

#include <tree_node.h>

#include <queue>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root) {
    if (!root) {
      return {};
    }

    std::vector<std::vector<int>> levels;
    std::queue<TreeNode *> queue{{root}};
    for (bool forward = true; !queue.empty(); forward = !forward) {
      const int size = queue.size();
      std::vector<int> level(size);
      for (int i = 0; i < size; ++i) {
        auto *node = queue.front();
        queue.pop();

        level[forward ? i : size - i - 1] = node->val;

        for (auto *child : {node->left, node->right}) {
          if (child) {
            queue.push(child);
          }
        }
      }
      levels.push_back(std::move(level));
    }
    return levels;
  }
};
