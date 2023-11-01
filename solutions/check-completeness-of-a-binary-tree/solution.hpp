#pragma once

#include <tree_node.h>

#include <queue>

/*
  958. Check Completeness of a Binary Tree
  https://leetcode.com/problems/check-completeness-of-a-binary-tree/
  Difficulty: Medium
  Tags: Tree, Breadth-First Search, Binary Tree
  Time:
  Space:
*/

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
