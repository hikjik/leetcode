#pragma once

#include <tree_node.h>

#include <queue>
#include <vector>

/*
  103. Binary Tree Zigzag Level Order Traversal
  https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
  Difficulty: Medium
  Tags: Tree, Breadth-First Search, Binary Tree
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root) {
    std::vector<std::vector<int>> values;

    std::queue<std::pair<TreeNode *, size_t>> queue;
    queue.emplace(root, 0);
    while (!queue.empty()) {
      auto [node, depth] = queue.front();
      queue.pop();

      if (!node) {
        continue;
      }

      if (values.size() < depth + 1) {
        values.emplace_back();
      }
      values[depth].push_back(node->val);

      queue.emplace(node->left, depth + 1);
      queue.emplace(node->right, depth + 1);
    }

    for (size_t i = 1; i < values.size(); i += 2) {
      std::reverse(values[i].begin(), values[i].end());
    }

    return values;
  }
};
