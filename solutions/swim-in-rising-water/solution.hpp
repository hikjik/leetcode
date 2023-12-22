#pragma once

#include <queue>
#include <tuple>
#include <vector>

// Time: O(N^2logN)
// Space: O(N^2)

class Solution {
public:
  static int swimInWater(const std::vector<std::vector<int>> &grid) {
    static const std::vector<std::pair<int, int>> kDirs{
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    const int n = grid.size();

    std::priority_queue<std::tuple<int, int, int>,
                        std::vector<std::tuple<int, int, int>>, std::greater<>>
        minHeap;
    minHeap.push({grid[0][0], 0, 0});

    std::vector seen(n, std::vector<bool>(n));
    seen[0][0] = true;

    int ans = 0;
    while (!minHeap.empty()) {
      const auto [val, i, j] = minHeap.top();
      minHeap.pop();

      ans = std::max(ans, val);
      if (i == n - 1 && j == n - 1) {
        break;
      }

      for (const auto &[di, dj] : kDirs) {
        const auto r = i + di, c = j + dj;
        if (r >= 0 && r < n && c >= 0 && c < n && !seen[r][c]) {
          minHeap.push({grid[r][c], r, c});
          seen[r][c] = true;
        }
      }
    }
    return ans;
  }
};
