#pragma once

#include <vector>

#include <node.h>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int diameter(Node *root) {
    int ans = 0;
    dfs(root, &ans);
    return ans;
  }

private:
  static int dfs(Node *node, int *ans) {
    if (!node) {
      return 0;
    }

    int max1 = 0, max2 = 0;
    for (auto *child : node->children) {
      const auto height = dfs(child, ans) + 1;
      if (height > max1) {
        max2 = std::exchange(max1, height);
      } else if (height > max2) {
        max2 = height;
      }
    }
    *ans = std::max(*ans, max1 + max2);
    return max1;
  }
};
