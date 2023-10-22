#pragma once

#include <vector>

#include <node.h>

class Solution {
public:
  static std::vector<int> postorder(Node *root) {
    std::vector<int> values;
    postorder(root, &values);
    return values;
  }

private:
  static void postorder(Node *node, std::vector<int> *values) {
    if (!node) {
      return;
    }

    for (auto child : node->children) {
      postorder(child, values);
    }
    values->push_back(node->val);
  }
};
