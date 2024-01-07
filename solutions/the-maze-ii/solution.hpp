#pragma once

#include <climits>
#include <queue>
#include <tuple>
#include <vector>

// Time: O(MN max(M,N))
// Space: O(MN)

class Solution {
public:
  static int shortestDistance(const std::vector<std::vector<int>> &maze,
                              const std::vector<int> &start,
                              const std::vector<int> &destination) {
    static const std::vector<std::pair<int, int>> kDirs{
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    const int m = maze.size(), n = maze[0].size();

    std::vector distances(m, std::vector<int>(n, INT_MAX));
    distances[start[0]][start[1]] = 0;

    std::priority_queue<std::tuple<int, int, int>,
                        std::vector<std::tuple<int, int, int>>, std::greater<>>
        minHeap;
    minHeap.push({0, start[0], start[1]});

    while (!minHeap.empty()) {
      const auto [distance, i, j] = minHeap.top();
      minHeap.pop();

      if (distances[i][j] < distance) {
        continue;
      }
      if (i == destination[0] && j == destination[1]) {
        return distance;
      }

      for (const auto &[di, dj] : kDirs) {
        int cnt = 0;
        int r = i, c = j;
        for (r += di, c += dj;
             r >= 0 && r < m && c >= 0 && c < n && !maze[r][c];
             r += di, c += dj) {
          ++cnt;
        }
        r -= di, c -= dj;
        if (distances[r][c] > distance + cnt) {
          distances[r][c] = distance + cnt;
          minHeap.push({distance + cnt, r, c});
        }
      }
    }
    return -1;
  }
};
