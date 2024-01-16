#pragma once

#include <cmath>
#include <vector>

#include <tree_node.h>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static std::vector<int> closestKValues(TreeNode *root, double target, int k) {
    std::vector<int> vals;
    traverseInorder(root, &vals);

    int l = 0, r = vals.size() - 1;
    while (r - l + 1 > k) {
      std::abs(vals[l] - target) > std::abs(vals[r] - target) ? ++l : --r;
    }
    return {vals.begin() + l, vals.begin() + l + k};
  }

private:
  static void traverseInorder(TreeNode *node, std::vector<int> *vals) {
    if (!node) {
      return;
    }
    traverseInorder(node->left, vals);
    vals->push_back(node->val);
    traverseInorder(node->right, vals);
  }
};
