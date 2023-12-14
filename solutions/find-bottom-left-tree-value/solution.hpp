#pragma once

#include <queue>

#include <tree_node.h>

// Time: O(N)
// Space: O(N)

namespace bfs {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int findBottomLeftValue(TreeNode *root) {
    std::queue<TreeNode *> queue{{root}};
    auto ans = root->val;
    while (!queue.empty()) {
      ans = queue.front()->val;
      for (int sz = queue.size(); sz; --sz) {
        auto *node = queue.front();
        queue.pop();

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
  static int findBottomLeftValue(TreeNode *root) {
    int ans = root->val;
    int maxDepth = 0;
    findBottomLeftValue(root, 0, &maxDepth, &ans);
    return ans;
  }

private:
  static void findBottomLeftValue(TreeNode *node, int depth, int *maxDepth,
                                  int *ans) {
    if (!node) {
      return;
    }
    if (depth > *maxDepth) {
      *maxDepth = depth;
      *ans = node->val;
    }
    findBottomLeftValue(node->left, depth + 1, maxDepth, ans);
    findBottomLeftValue(node->right, depth + 1, maxDepth, ans);
  }
};

} // namespace dfs
