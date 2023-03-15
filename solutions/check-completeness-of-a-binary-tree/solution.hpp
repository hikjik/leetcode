#pragma once

#include <tree_node.h>

#include <queue>

class Solution {
public:
  static bool isCompleteTree(TreeNode *root) {
    std::queue<TreeNode *> queue{{root}};

    while (queue.front()) {
      auto node = queue.front();
      queue.pop();
      queue.push(node->left);
      queue.push(node->right);
    }

    while (!queue.empty() && !queue.front()) {
      queue.pop();
    }

    return queue.empty();
  }
};
