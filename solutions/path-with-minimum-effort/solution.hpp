#pragma once

#include <algorithm>
#include <climits>
#include <cmath>
#include <queue>
#include <tuple>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int minimumEffortPath(const std::vector<std::vector<int>> &heights) {
    static const std::vector<std::pair<int, int>> dirs{
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    const int n = heights.size(), m = heights.back().size();

    std::vector dp(n, std::vector<int>(m, INT_MAX));
    std::priority_queue<std::tuple<int, int, int>,
                        std::vector<std::tuple<int, int, int>>, std::greater<>>
        min_heap;

    min_heap.push({0, 0, 0});
    dp[0][0] = 0;
    while (!min_heap.empty()) {
      const auto [effort, i, j] = min_heap.top();
      min_heap.pop();

      if (i == n - 1 && j == m - 1) {
        return effort;
      }

      for (auto [di, dj] : dirs) {
        const auto r = i + di, c = j + dj;
        if (r < 0 || r >= n || c < 0 || c >= m) {
          continue;
        }

        const auto new_effort =
            std::max(effort, std::abs(heights[i][j] - heights[r][c]));
        if (dp[r][c] > new_effort) {
          dp[r][c] = new_effort;
          min_heap.push({new_effort, r, c});
        }
      }
    }

    throw;
  }
};
