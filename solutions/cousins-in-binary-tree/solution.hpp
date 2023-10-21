#pragma once

#include <tree_node.h>

#include <queue>
#include <unordered_map>

class Solution {
public:
  static bool isCousins(TreeNode *root, int x, int y) {
    std::unordered_map<int, int> depths, parent;
    std::queue<TreeNode *> queue{{root}};
    for (int depth = 0; !queue.empty(); ++depth) {
      for (int sz = queue.size(); sz; --sz) {
        const auto node = queue.front();
        queue.pop();

        depths[node->val] = depth;

        for (auto child : {node->left, node->right}) {
          if (child) {
            queue.push(child);
            parent[child->val] = node->val;
          }
        }
      }
    }
    return depths[x] == depths[y] && parent[x] != parent[y];
  }
};
