#pragma once

#include <queue>
#include <tuple>
#include <vector>

// Time: O(NMlogNM)
// Space: O(NM)

class Solution {
public:
  static int trapRainWater(const std::vector<std::vector<int>> &heightMap) {
    static const std::vector<std::pair<int, int>> kDirs{
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    const int m = heightMap.size(), n = heightMap.back().size();

    std::priority_queue<std::tuple<int, int, int>,
                        std::vector<std::tuple<int, int, int>>, std::greater<>>
        minHeap;
    std::vector visited(m, std::vector<bool>(n));

    for (int i = 0; i < m; ++i) {
      minHeap.push({heightMap[i][0], i, 0});
      minHeap.push({heightMap[i][n - 1], i, n - 1});
      visited[i][0] = visited[i][n - 1] = true;
    }
    for (int j = 0; j < n; ++j) {
      minHeap.push({heightMap[0][j], 0, j});
      minHeap.push({heightMap[m - 1][j], m - 1, j});
      visited[0][j] = visited[m - 1][j] = true;
    }

    int ans = 0;
    while (!minHeap.empty()) {
      const auto [height, i, j] = minHeap.top();
      minHeap.pop();

      for (const auto &[di, dj] : kDirs) {
        const int r = i + di, c = j + dj;
        if (r >= 0 && r < m && c >= 0 && c < n && !visited[r][c]) {
          minHeap.push({std::max(height, heightMap[r][c]), r, c});
          visited[r][c] = true;

          ans += std::max(0, height - heightMap[r][c]);
        }
      }
    }
    return ans;
  }
};
