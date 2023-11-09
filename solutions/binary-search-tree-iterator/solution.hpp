#pragma once

#include <tree_node.h>

#include <stack>

// Time: O(1) on average
// Space: O(1)

namespace recursion {

// Space: O(N)
class BSTIterator {
public:
  // O(N)
  BSTIterator(TreeNode *root) { traverseInorder(root); }

  // O(1)
  int next() { return values[pos++]; }

  // O(1)
  bool hasNext() { return pos < std::ssize(values); }

private:
  void traverseInorder(TreeNode *root) {
    if (!root) {
      return;
    }
    traverseInorder(root->left);
    values.push_back(root->val);
    traverseInorder(root->right);
  }

  int pos = 0;
  std::vector<int> values;
};

} // namespace recursion

namespace stack {

// Space: O(H) where H is the height of the tree
class BSTIterator {
public:
  // O(H)
  BSTIterator(TreeNode *root) { pushLeftSubTree(root); }

  // O(1) on average
  int next() {
    auto *node = stack.top();
    stack.pop();
    pushLeftSubTree(node->right);
    return node->val;
  }

  // O(1)
  bool hasNext() { return !stack.empty(); }

private:
  void pushLeftSubTree(TreeNode *node) {
    while (node) {
      stack.push(node);
      node = node->left;
    }
  }

  std::stack<TreeNode *> stack;
};

} // namespace stack

namespace morris {

// Space: O(1)
class BSTIterator {
public:
  // O(1)
  BSTIterator(TreeNode *root) : node(root) {}

  // O(1) on average
  int next() {
    while (node) {
      if (node->left) {
        auto *pred = node->left;
        while (pred->right && pred->right != node) {
          pred = pred->right;
        }

        if (pred->right) {
          pred->right = nullptr;
          const auto val = node->val;
          node = node->right;
          return val;
        } else {
          pred->right = node;
          node = node->left;
        }
      } else {
        const auto val = node->val;
        node = node->right;
        return val;
      }
    }
    throw;
  }

  // O(1)
  bool hasNext() { return node; }

private:
  TreeNode *node;
};

} // namespace morris
