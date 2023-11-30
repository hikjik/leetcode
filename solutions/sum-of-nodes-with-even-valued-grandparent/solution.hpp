#pragma once

#include <queue>

#include <tree_node.h>

// Time: O(N)
// Space: O(N)

namespace dfs {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int sumEvenGrandparent(TreeNode *root, int parent = -1,
                                int grandparent = -1) {
    if (!root) {
      return 0;
    }
    return sumEvenGrandparent(root->left, root->val, parent) +
           sumEvenGrandparent(root->right, root->val, parent) +
           (grandparent % 2 == 0 ? root->val : 0);
  }
};

}; // namespace dfs

namespace bfs {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int sumEvenGrandparent(TreeNode *root) {
    std::queue<TreeNode *> queue{{root}};

    int ans = 0;
    while (!queue.empty()) {
      auto *node = queue.front();
      queue.pop();

      for (auto *child : {node->left, node->right}) {
        if (child) {
          if (node->val % 2 == 0) {
            ans += child->left ? child->left->val : 0;
            ans += child->right ? child->right->val : 0;
          }
          queue.push(child);
        }
      }
    }
    return ans;
  }
};

}; // namespace bfs
