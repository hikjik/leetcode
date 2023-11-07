#pragma once

#include <tree_node.h>

#include <stack>

// Time: O(N)
// Space: O(1)

namespace recursive {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static void flatten(TreeNode *root) {
    if (!root) {
      return;
    }

    flatten(root->left);
    flatten(root->right);

    if (root->left) {
      auto *node = root->left;
      while (node->right) {
        node = node->right;
      }

      node->right = root->right;
      root->right = root->left;
      root->left = nullptr;
    }
  }
};

} // namespace recursive

namespace stack {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static void flatten(TreeNode *root) {
    if (!root) {
      return;
    }

    std::stack<TreeNode *> stack{{root}};
    while (!stack.empty()) {
      auto *node = stack.top();
      stack.pop();

      if (node->right) {
        stack.push(node->right);
      }
      if (node->left) {
        stack.push(node->left);
      }
      if (!stack.empty()) {
        node->right = stack.top();
      }
      node->left = nullptr;
    }
  }
};

} // namespace stack

namespace iterative {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static void flatten(TreeNode *root) {
    while (root) {
      if (root->left) {
        auto node = root->left;
        while (node->right) {
          node = node->right;
        }
        node->right = root->right;
        root->right = root->left;
        root->left = nullptr;
      }
      root = root->right;
    }
  }
};

} // namespace iterative
