#pragma once

#include <tree_node.h>

#include <queue>
#include <vector>

class Solution {
public:
  static std::vector<int> rightSideView(TreeNode *root) {
    if (!root) {
      return {};
    }

    std::vector<int> values;
    std::queue<TreeNode *> queue{{root}};
    while (!queue.empty()) {
      for (int i = queue.size(); i > 0; --i) {
        auto node = queue.front();
        queue.pop();

        if (i == 1) {
          values.push_back(node->val);
        }
        if (node->left) {
          queue.push(node->left);
        }
        if (node->right) {
          queue.push(node->right);
        }
      }
    }
    return values;
  }
};