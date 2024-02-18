#pragma once

#include <functional>
#include <ranges>
#include <vector>

// Time: O(N^2)
// Space: O(N^2)

class Solution {
public:
  static int maxOperations(const std::vector<int> &nums) {
    std::function<int(int, int, int, std::vector<std::vector<int>> *)> maxOps =
        [&](int l, int r, int score,
            std::vector<std::vector<int>> *memo) -> int {
      if (r - l < 1) {
        return 0;
      }
      auto &ans = (*memo)[l][r];
      if (ans == -1) {
        ans = 0;
        if (nums[l] + nums[l + 1] == score) {
          ans = std::max(ans, 1 + maxOps(l + 2, r, score, memo));
        }
        if (nums[r - 1] + nums[r] == score) {
          ans = std::max(ans, 1 + maxOps(l, r - 2, score, memo));
        }
        if (nums[l] + nums[r] == score) {
          ans = std::max(ans, 1 + maxOps(l + 1, r - 1, score, memo));
        }
      }
      return ans;
    };

    const int n = nums.size();
    int ans = 0;
    std::vector memo(n, std::vector<int>(n));
    for (auto score : {nums[0] + nums[1], nums[n - 2] + nums[n - 1],
                       nums[0] + nums[n - 1]}) {
      std::ranges::fill(memo, std::vector<int>(n, -1));
      ans = std::max(ans, maxOps(0, n - 1, score, &memo));
    }
    return ans;
  }
};
