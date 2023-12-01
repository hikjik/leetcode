#pragma once

#include <queue>
#include <vector>

#include <tree_node.h>

// Time:
// Space:

namespace bfs {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static TreeNode *reverseOddLevels(TreeNode *root) {
    std::queue<TreeNode *> queue{{root}};
    std::vector<TreeNode *> level;
    for (int depth = 0; !queue.empty(); ++depth) {
      for (int sz = queue.size(); sz; --sz) {
        auto *node = queue.front();
        queue.pop();

        if (depth & 1) {
          level.push_back(node);
        }

        for (auto *child : {node->left, node->right}) {
          if (child) {
            queue.push(child);
          }
        }
      }

      if (depth & 1) {
        const int n = level.size();
        for (int i = 0; i < n / 2; ++i) {
          std::swap(level[i]->val, level[n - i - 1]->val);
        }
        level.clear();
      }
    }
    return root;
  }
};

} // namespace bfs

namespace dfs {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static TreeNode *reverseOddLevels(TreeNode *root) {
    reverseOddLevels(root->left, root->right, 1);
    return root;
  }

private:
  static void reverseOddLevels(TreeNode *left, TreeNode *right, int depth) {
    if (!left) {
      return;
    }
    if (depth & 1) {
      std::swap(left->val, right->val);
    }
    reverseOddLevels(left->left, right->right, depth + 1);
    reverseOddLevels(left->right, right->left, depth + 1);
  }
};

} // namespace dfs
