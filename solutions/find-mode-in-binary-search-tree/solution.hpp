#pragma once

#include <queue>
#include <unordered_map>
#include <vector>

#include <tree_node.h>

/*
  501. Find Mode in Binary Search Tree
  https://leetcode.com/problems/find-mode-in-binary-search-tree/
  Difficulty: Easy
  Tags: Tree, Depth-First Search, Binary Search Tree, Binary Tree
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> findMode(TreeNode *root) {
    int max = 0;
    std::unordered_map<int, int> counter;
    std::queue<TreeNode *> queue{{root}};
    while (!queue.empty()) {
      auto *node = queue.front();
      queue.pop();

      max = std::max(max, ++counter[node->val]);

      for (auto child : {node->left, node->right}) {
        if (child) {
          queue.push(child);
        }
      }
    }

    std::vector<int> ans;
    for (const auto &[a, f] : counter) {
      if (f == max) {
        ans.push_back(a);
      }
    }
    return ans;
  }
};
