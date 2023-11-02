#pragma once

#include "tree_node.h"

#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
    const auto parents = getParents(root);

    std::queue<TreeNode *> queue{{target}};
    std::unordered_set<TreeNode *> visited{target};
    std::vector<int> ans;
    int distance = 0;
    while (!queue.empty() && distance <= k) {
      for (int sz = queue.size(); sz; --sz) {
        auto node = queue.front();
        queue.pop();

        if (distance == k) {
          ans.push_back(node->val);
        }

        if (distance < k) {
          for (auto adj_node : {node->left, node->right, parents.at(node)}) {
            if (adj_node && !visited.count(adj_node)) {
              queue.push(adj_node);
              visited.insert(adj_node);
            }
          }
        }
      }
      ++distance;
    }
    return ans;
  }

private:
  static std::unordered_map<TreeNode *, TreeNode *> getParents(TreeNode *root) {
    std::unordered_map<TreeNode *, TreeNode *> map{{root, nullptr}};
    std::queue<TreeNode *> queue{{root}};
    while (!queue.empty()) {
      auto node = queue.front();
      queue.pop();

      for (auto child : {node->left, node->right}) {
        if (child) {
          map[child] = node;
          queue.push(child);
        }
      }
    }
    return map;
  }
};
