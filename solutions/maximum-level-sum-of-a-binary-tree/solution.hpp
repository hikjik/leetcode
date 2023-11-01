#pragma once

#include <tree_node.h>

#include <climits>
#include <queue>

/*
  1161. Maximum Level Sum of a Binary Tree
  https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
  Difficulty: Medium
  Tags: Tree, Depth-First Search, Breadth-First Search, Binary Tree
  Time:
  Space:
*/

class Solution {
public:
  static int maxLevelSum(TreeNode *root) {
    int max_level_sum = INT_MIN;
    int max_level = -1;

    int level = 0;
    std::queue<TreeNode *> queue{{root}};
    while (!queue.empty()) {
      ++level;
      int level_sum = 0;
      for (int size = queue.size(); size; --size) {
        auto node = queue.front();
        queue.pop();

        level_sum += node->val;

        for (auto child : {node->left, node->right}) {
          if (child) {
            queue.push(child);
          }
        }
      }

      if (level_sum > max_level_sum) {
        max_level_sum = level_sum;
        max_level = level;
      }
    }

    return max_level;
  }
};
