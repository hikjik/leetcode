#pragma once

#include "tree_node.h"

#include <queue>

/*
  111. Minimum Depth of Binary Tree
  https://leetcode.com/problems/minimum-depth-of-binary-tree/
  Difficulty: Easy
  Tags: Tree, Depth-First Search, Breadth-First Search, Binary Tree
  Time:
  Space:
*/

class Solution {
public:
  static int minDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }

    std::queue<TreeNode *> queue{{root}};

    int min_depth = 0;
    while (!queue.empty()) {
      ++min_depth;
      for (int sz = queue.size(); sz; --sz) {
        auto node = queue.front();
        queue.pop();

        if (!node->left && !node->right) {
          return min_depth;
        }

        for (auto child : {node->left, node->right}) {
          if (child) {
            queue.push(child);
          }
        }
      }
    }

    throw;
  }
};
