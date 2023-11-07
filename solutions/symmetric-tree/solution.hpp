#pragma once

#include <queue>

#include <tree_node.h>

// Time: O(N)
// Space: O(N)

namespace recursion {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static bool isSymmetric(TreeNode *root) {
    return isSymmetric(root->left, root->right);
  }

private:
  static bool isSymmetric(TreeNode *p, TreeNode *q) {
    if (!p || !q) {
      return p == q;
    }
    if (p->val != q->val) {
      return false;
    }
    return isSymmetric(p->right, q->left) && isSymmetric(p->left, q->right);
  }
};

} // namespace recursion

namespace iterative {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static bool isSymmetric(TreeNode *root) {
    std::queue<std::pair<TreeNode *, TreeNode *>> queue;
    queue.emplace(root->left, root->right);
    while (!queue.empty()) {
      const auto [p, q] = queue.front();
      queue.pop();

      if (!p && q || p && !q) {
        return false;
      }
      if (!p && !q) {
        continue;
      }

      if (p->val != q->val) {
        return false;
      }

      queue.emplace(p->right, q->left);
      queue.emplace(p->left, q->right);
    }
    return true;
  }
};

} // namespace iterative
