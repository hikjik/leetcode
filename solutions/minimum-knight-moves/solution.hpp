#pragma once

#include <cmath>
#include <functional>
#include <unordered_map>

// Time: O(XY)
// Space: O(XY)

class Solution {
public:
  static constexpr int kMax = 301;

  static int minKnightMoves(int x, int y) {
    std::unordered_map<int, int> memo;

    std::function<int(int, int)> dfs = [&](int x, int y) {
      if (x == 0 && y == 0) {
        return 0;
      }
      if (x + y == 2) {
        return 2;
      }
      const auto k = x * kMax + y;
      if (auto it = memo.find(k); it != memo.end()) {
        return it->second;
      }
      return memo[k] = 1 + std::min(dfs(std::abs(x - 2), std::abs(y - 1)),
                                    dfs(std::abs(x - 1), std::abs(y - 2)));
    };

    return dfs(std::abs(x), std::abs(y));
  }
};
