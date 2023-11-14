#pragma once

#include <tree_node.h>

#include <stack>

// Time: O(N)
// Space: O(1)
// Notes: [Threaded Binary Tree](https://w.wiki/84dw)

namespace recursion {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  void recoverTree(TreeNode *root) {
    traverseInOrder(root);
    std::swap(left->val, right->val);
  }

private:
  TreeNode *left = nullptr;
  TreeNode *right = nullptr;
  TreeNode *prev = nullptr;

  void traverseInOrder(TreeNode *root) {
    if (!root) {
      return;
    }

    traverseInOrder(root->left);

    if (prev && prev->val > root->val) {
      right = root;
      if (!left) {
        left = prev;
      } else {
        return;
      }
    }
    prev = root;

    traverseInOrder(root->right);
  }
};

} // namespace recursion

namespace iteration {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static void recoverTree(TreeNode *root) {
    TreeNode *left = nullptr, *right = nullptr;
    TreeNode *prev = nullptr;

    std::stack<TreeNode *> stack;
    while (root || !stack.empty()) {
      while (root) {
        stack.push(root);
        root = root->left;
      }
      root = stack.top();
      stack.pop();
      if (prev && prev->val > root->val) {
        right = root;
        if (!left) {
          left = prev;
        } else {
          break;
        }
      }
      prev = root;
      root = root->right;
    }

    std::swap(left->val, right->val);
  }
};

} // namespace iteration

namespace morris {

// Time: O(N)
// Space: O(1)
class Visitor {
public:
  Visitor(TreeNode **left, TreeNode **right) : left_(*left), right_(*right) {}

  void explore(TreeNode *node) {
    if (prev_ && prev_->val > node->val) {
      right_ = node;
      if (!left_) {
        left_ = prev_;
      }
    }
    prev_ = node;
  }

private:
  TreeNode *&left_;
  TreeNode *&right_;
  TreeNode *prev_ = nullptr;
};

void MorrisTraversal(TreeNode *root, Visitor visitor) {
  for (auto *node = root; node;) {
    if (node->left) {
      auto *pred = node->left;
      while (pred->right && pred->right != node) {
        pred = pred->right;
      }

      if (pred->right) {
        pred->right = nullptr;
        visitor.explore(node);
        node = node->right;
      } else {
        pred->right = node;
        node = node->left;
      }
    } else {
      visitor.explore(node);
      node = node->right;
    }
  }
}

class Solution {
public:
  static void recoverTree(TreeNode *root) {
    TreeNode *left = nullptr, *right = nullptr;
    Visitor visitor(&left, &right);
    MorrisTraversal(root, visitor);
    std::swap(left->val, right->val);
  }
};

} // namespace morris
