#pragma once

#include <algorithm>
#include <iterator>
#include <vector>

#include <tree_node.h>

// Time: O(N+M)
// Space: O(1)
// Notes: [Morris Traversal](https://w.wiki/84dw)

class BSTIterator : std::iterator<std::input_iterator_tag, int> {
public:
  BSTIterator() : node(nullptr), curr(nullptr) {}

  explicit BSTIterator(TreeNode *root) : node(root), curr(nullptr) { next(); }

  int &operator*() { return curr->val; }

  BSTIterator &operator++() {
    next();
    return *this;
  }

  BSTIterator operator++(int) {
    BSTIterator other(node, curr);
    next();
    return other;
  }

  bool operator!=(BSTIterator other) const { return curr != other.curr; }

private:
  BSTIterator(TreeNode *node, TreeNode *curr) : node(node), curr(curr) {}

  void next() {
    while (node) {
      if (node->left) {
        auto *pred = node->left;
        while (pred->right && pred->right != node) {
          pred = pred->right;
        }

        if (pred->right) {
          pred->right = nullptr;
          curr = node;
          node = node->right;
          return;
        } else {
          pred->right = node;
          node = node->left;
        }
      } else {
        curr = node;
        node = node->right;
        return;
      }
    }
    curr = nullptr;
  }

  TreeNode *node, *curr;
};

class Solution {
public:
  static std::vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
    std::vector<int> ans;
    std::merge(BSTIterator(root1), BSTIterator(), BSTIterator(root2),
               BSTIterator(), std::back_inserter(ans));
    return ans;
  }
};
