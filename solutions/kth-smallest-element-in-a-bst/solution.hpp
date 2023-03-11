#pragma once

#include <tree_node.h>

#include <stack>

class Solution {
public:
  static int kthSmallest(TreeNode *root, int k) {
    std::stack<TreeNode *> stack;
    pushLeft(root, &stack);
    while (--k) {
      auto node = stack.top();
      stack.pop();
      pushLeft(node->right, &stack);
    }
    return stack.top()->val;
  }

private:
  static void pushLeft(TreeNode *node, std::stack<TreeNode *> *stack) {
    while (node) {
      stack->push(node);
      node = node->left;
    }
  }
};
