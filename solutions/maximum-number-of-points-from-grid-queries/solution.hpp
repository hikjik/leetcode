#pragma once

#include <numeric>
#include <queue>
#include <vector>

// Time: O(NMlogNM+KlogK)
// Space: O(NM+K)

class Solution {
public:
  static std::vector<int> maxPoints(const std::vector<std::vector<int>> &grid,
                                    const std::vector<int> &queries) {
    static const std::vector<std::pair<int, int>> kDirs{
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    const int m = grid.size(), n = grid.back().size();

    auto greater = [&](auto p1, auto p2) {
      return grid[p1.first][p1.second] > grid[p2.first][p2.second];
    };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        decltype(greater)>
        minHeap(greater);
    minHeap.push({0, 0});

    std::vector visited(m, std::vector<bool>(n));
    visited[0][0] = true;

    std::vector<int> indexes(queries.size());
    std::iota(indexes.begin(), indexes.end(), 0);
    std::ranges::sort(indexes,
                      [&](int i, int j) { return queries[i] < queries[j]; });

    std::vector<int> ans(queries.size());
    for (int sum = 0; auto idx : indexes) {
      while (!minHeap.empty()) {
        const auto [i, j] = minHeap.top();
        if (grid[i][j] >= queries[idx]) {
          break;
        }

        minHeap.pop();
        ++sum;

        for (const auto &[di, dj] : kDirs) {
          const auto r = i + di, c = j + dj;
          if (r >= 0 && r < m && c >= 0 && c < n && !visited[r][c]) {
            visited[r][c] = true;
            minHeap.push({r, c});
          }
        }
      }
      ans[idx] = sum;
    }
    return ans;
  }
};
