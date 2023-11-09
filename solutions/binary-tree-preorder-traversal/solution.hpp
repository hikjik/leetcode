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
  static std::vector<int> preorderTraversal(TreeNode *root) {
    std::vector<int> values;
    traverseInPreOrder(root, &values);
    return values;
  }

private:
  static void traverseInPreOrder(TreeNode *root, std::vector<int> *values) {
    if (!root) {
      return;
    }

    values->push_back(root->val);
    traverseInPreOrder(root->left, values);
    traverseInPreOrder(root->right, values);
  }
};

} // namespace recursive

namespace iterative {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static std::vector<int> preorderTraversal(TreeNode *root) {
    if (!root) {
      return {};
    }

    std::vector<int> values;
    std::stack<TreeNode *> stack{{root}};
    while (!stack.empty()) {
      auto *node = stack.top();
      stack.pop();

      values.push_back(node->val);

      for (auto *child : {node->right, node->left}) {
        if (child) {
          stack.push(child);
        }
      }
    }
    return values;
  }
};

} // namespace iterative
