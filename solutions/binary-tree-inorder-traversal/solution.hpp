#pragma once

#include <tree_node.h>

#include <stack>
#include <vector>

// Time: O(N)
// Space: O(N)

namespace recursive {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static std::vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> values;
    traverseInOrder(root, &values);
    return values;
  }

private:
  static void traverseInOrder(TreeNode *root, std::vector<int> *values) {
    if (!root) {
      return;
    }
    traverseInOrder(root->left, values);
    values->push_back(root->val);
    traverseInOrder(root->right, values);
  }
};

} // namespace recursive

namespace iterative {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static std::vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> values;
    std::stack<TreeNode *> stack;

    auto *node = root;
    while (node || !stack.empty()) {
      while (node) {
        stack.push(node);
        node = node->left;
      }
      node = stack.top();
      stack.pop();
      values.push_back(node->val);
      node = node->right;
    }

    return values;
  }
};

} // namespace iterative
