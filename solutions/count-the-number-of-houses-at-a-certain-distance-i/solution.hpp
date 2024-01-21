#pragma once

#include <cmath>
#include <vector>

// Time: O(N^2)
// Space: O(N)

class Solution {
public:
  static std::vector<int> countOfPairs(int n, int x, int y) {
    std::vector<int> ans(n);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j < i; ++j) {
        const auto dist = std::min({
            std::abs(i - j),
            std::abs(i - x) + std::abs(j - y) + 1,
            std::abs(i - y) + std::abs(j - x) + 1,
        });
        ++ans[dist - 1];
      }
    }
    std::ranges::for_each(ans, [](int &a) { a *= 2; });
    return ans;
  }
};
