#pragma once

#include <tree_node.h>

#include <queue>

// Time: O(N)
// Space: O(N)

namespace bfs {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int deepestLeavesSum(TreeNode *root) {
    std::queue<TreeNode *> queue{{root}};
    int ans = 0;
    while (!queue.empty()) {
      ans = 0;
      for (int sz = queue.size(); sz; --sz) {
        auto *node = queue.front();
        queue.pop();

        ans += node->val;

        for (auto *child : {node->left, node->right}) {
          if (child) {
            queue.push(child);
          }
        }
      }
    }
    return ans;
  }
};

} // namespace bfs

namespace dfs {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int deepestLeavesSum(TreeNode *root) {
    int ans = 0;
    int depth = 0;
    deepestLeavesSum(root, 0, &depth, &ans);
    return ans;
  }

private:
  static void deepestLeavesSum(TreeNode *node, int level, int *depth,
                               int *ans) {
    if (!node) {
      return;
    }

    deepestLeavesSum(node->left, level + 1, depth, ans);
    deepestLeavesSum(node->right, level + 1, depth, ans);

    if (*depth < level) {
      *depth = level;
      *ans = node->val;
    } else {
      if (*depth == level) {
        *ans += node->val;
      }
    }
  }
};

} // namespace dfs
