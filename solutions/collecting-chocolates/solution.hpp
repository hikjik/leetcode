#pragma once

#include <climits>
#include <numeric>
#include <vector>

// Time: O(N^2)
// Space: O(N)

class Solution {
public:
  static long long minCost(const std::vector<int> &nums, int x) {
    const int n = nums.size();
    std::vector<int> costs(nums);
    auto ans = LONG_LONG_MAX;
    for (int i = 0; i < n; ++i) {
      ans = std::min(ans, std::accumulate(costs.begin(), costs.end(), 0LL) +
                              1LL * x * i);
      for (int j = 0; j < n; ++j) {
        costs[j] = std::min(costs[j], nums[(j + i + 1) % n]);
      }
    }
    return ans;
  }
};
