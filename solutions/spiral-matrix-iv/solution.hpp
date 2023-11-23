#pragma once

#include <vector>

#include <list_node.h>

// Time: O(MN)
// Space: O(1)

class Solution {
public:
  static std::vector<std::vector<int>> spiralMatrix(int m, int n,
                                                    ListNode *head) {
    static const std::vector<int> kDirs{0, 1, 0, -1, 0};

    std::vector ans(m, std::vector<int>(n, -1));
    int i = 0, j = 0;
    int d = 0;
    for (auto *node = head; node; node = node->next) {
      ans[i][j] = node->val;

      const auto r = i + kDirs[d], c = j + kDirs[d + 1];
      if (r < 0 || r >= m || c < 0 || c >= n || ans[r][c] != -1) {
        d = (d + 1) % 4;
      }

      i += kDirs[d], j += kDirs[d + 1];
    }
    return ans;
  }
};
