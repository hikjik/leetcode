#pragma once

#include <tree_node.h>

#include <queue>

class Solution {
public:
  static int widthOfBinaryTree(TreeNode *root) {
    int max_width = 0;

    std::queue<std::pair<TreeNode *, int>> nodes;
    nodes.emplace(root, 0);

    while (!nodes.empty()) {
      max_width =
          std::max(max_width, nodes.back().second - nodes.front().second + 1);

      const auto offset = nodes.back().second * 2;
      for (int i = nodes.size(); i > 0; --i) {
        const auto [node, index] = nodes.front();
        nodes.pop();

        if (node->left) {
          nodes.emplace(node->left, 2 * index - offset + 1);
        }
        if (node->right) {
          nodes.emplace(node->right, 2 * index - offset + 2);
        }
      }
    }
    return max_width;
  }
};
