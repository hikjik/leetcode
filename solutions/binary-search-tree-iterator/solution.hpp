#pragma once

#include <tree_node.h>

#include <stack>

class BSTIterator {
public:
  BSTIterator(TreeNode *root) { pushLeftSubTree(root); }

  int next() {
    auto node = stack_.top();
    stack_.pop();
    pushLeftSubTree(node->right);
    return node->val;
  }

  bool hasNext() { return !stack_.empty(); }

private:
  void pushLeftSubTree(TreeNode *node) {
    while (node) {
      stack_.push(node);
      node = node->left;
    }
  }

  std::stack<TreeNode *> stack_;
};
