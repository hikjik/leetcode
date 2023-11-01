#pragma once

#include <tree_node.h>

#include <queue>
#include <vector>

/*
  102. Binary Tree Level Order Traversal
  https://leetcode.com/problems/binary-tree-level-order-traversal/
  Difficulty: Medium
  Tags: Tree, Breadth-First Search, Binary Tree
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    std::queue<std::pair<TreeNode *, size_t>> queue;
    std::vector<std::vector<int>> values;
    queue.emplace(root, 0);
    while (!queue.empty()) {
      const auto [node, depth] = queue.front();
      queue.pop();

      if (node) {
        if (values.size() < depth + 1) {
          values.emplace_back();
        }
        values[depth].push_back(node->val);

        queue.emplace(node->left, depth + 1);
        queue.emplace(node->right, depth + 1);
      }
    }
    return values;
  }
};
