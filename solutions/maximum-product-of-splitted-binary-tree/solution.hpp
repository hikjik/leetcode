#pragma once

#include <tree_node.h>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static constexpr int kMod = 1e9 + 7;

  static int maxProduct(TreeNode *root) {
    std::vector<int> sums;
    const long long total = treeSum(root, &sums);
    long long ans = 0;
    for (auto sum : sums) {
      ans = std::max(ans, sum * (total - sum));
    }
    return ans % kMod;
  }

private:
  static int treeSum(TreeNode *node, std::vector<int> *sums) {
    if (!node) {
      return 0;
    }
    const auto sum =
        node->val + treeSum(node->left, sums) + treeSum(node->right, sums);
    sums->push_back(sum);
    return sum;
  }
};
