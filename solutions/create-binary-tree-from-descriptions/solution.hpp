#pragma once

#include <tree_node.h>

#include <unordered_map>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static TreeNode *
  createBinaryTree(const std::vector<std::vector<int>> &descriptions) {
    std::unordered_map<int, TreeNode *> valueToNode;
    int root_value = 0;
    for (const auto &d : descriptions) {
      for (auto value : {d[0], d[1]}) {
        if (!valueToNode.count(value)) {
          valueToNode[value] = new TreeNode(value);
          root_value ^= value;
        }
      }

      auto parent = valueToNode[d[0]], child = valueToNode[d[1]];
      d[2] ? parent->left = child : parent->right = child;

      root_value ^= child->val;
    }

    return valueToNode[root_value];
  }
};
