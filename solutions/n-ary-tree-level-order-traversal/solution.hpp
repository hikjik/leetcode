#pragma once

#include <node.h>

#include <queue>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<std::vector<int>> levelOrder(Node *root) {
    if (!root) {
      return {};
    }

    std::queue<Node *> queue{{root}};
    std::vector<std::vector<int>> levels;
    while (!queue.empty()) {
      std::vector<int> level;
      for (int i = queue.size(); i > 0; --i) {
        auto node = queue.front();
        queue.pop();

        level.push_back(node->val);
        for (auto child : node->children) {
          queue.push(child);
        }
      }
      levels.push_back(level);
    }
    return levels;
  }
};
