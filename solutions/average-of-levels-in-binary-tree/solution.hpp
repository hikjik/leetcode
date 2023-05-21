#pragma once

#include <tree_node.h>

#include <queue>
#include <vector>

class Solution {
public:
  static std::vector<double> averageOfLevels(TreeNode *root) {
    std::queue<TreeNode *> queue{{root}};
    std::vector<double> ans;
    while (!queue.empty()) {
      const auto size = queue.size();
      double sum = 0;
      for (size_t i = 0; i < size; ++i) {
        auto node = queue.front();
        queue.pop();

        sum += node->val;

        for (auto child : {node->left, node->right}) {
          if (child) {
            queue.push(child);
          }
        }
      }
      ans.push_back(sum / size);
    }
    return ans;
  }
};