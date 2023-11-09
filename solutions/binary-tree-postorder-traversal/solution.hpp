#pragma once

#include <tree_node.h>

#include <algorithm>
#include <stack>
#include <vector>

// Time: O(N)
// Space: O(N)

namespace recursive {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static std::vector<int> postorderTraversal(TreeNode *root) {
    std::vector<int> values;
    traverseInPostOrder(root, &values);
    return values;
  }

private:
  static void traverseInPostOrder(TreeNode *root, std::vector<int> *values) {
    if (!root) {
      return;
    }

    traverseInPostOrder(root->left, values);
    traverseInPostOrder(root->right, values);
    values->push_back(root->val);
  }
};

} // namespace recursive

namespace iterative {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static std::vector<int> postorderTraversal(TreeNode *root) {
    if (!root) {
      return {};
    }

    std::vector<int> values;
    std::stack<TreeNode *> stack{{root}};
    while (!stack.empty()) {
      auto *node = stack.top();
      stack.pop();

      values.push_back(node->val);

      for (auto *child : {node->left, node->right}) {
        if (child) {
          stack.push(child);
        }
      }
    }
    std::reverse(values.begin(), values.end());
    return values;
  }
};

} // namespace iterative
