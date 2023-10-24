#pragma once

#include <algorithm>
#include <climits>
#include <queue>
#include <vector>

#include <tree_node.h>

class Solution {
public:
  static std::vector<int> largestValues(TreeNode *root) {
    if (!root) {
      return {};
    }

    std::queue<TreeNode *> queue{{root}};
    std::vector<int> ans;
    while (!queue.empty()) {
      auto max = INT_MIN;
      for (int sz = queue.size(); sz; --sz) {
        const auto *node = queue.front();
        queue.pop();

        max = std::max(max, node->val);

        for (auto child : {node->left, node->right}) {
          if (child) {
            queue.push(child);
          }
        }
      }
      ans.push_back(max);
    }
    return ans;
  }
};
