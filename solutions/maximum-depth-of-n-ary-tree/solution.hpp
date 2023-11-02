#pragma once

#include <node.h>

#include <queue>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int maxDepth(Node *root) {
    if (!root) {
      return 0;
    }

    std::queue<Node *> queue{{root}};
    int depth = 0;
    while (!queue.empty()) {
      ++depth;
      for (int sz = queue.size(); sz; --sz) {
        auto node = queue.front();
        queue.pop();

        for (auto child : node->children) {
          queue.push(child);
        }
      }
    }
    return depth;
  }
};
