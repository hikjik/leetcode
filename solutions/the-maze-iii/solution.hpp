#pragma once

#include <climits>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

// Time: O(NMlogNM)
// Space: O(NM)

class Solution {
public:
  static std::string findShortestWay(const std::vector<std::vector<int>> &maze,
                                     const std::vector<int> &ball,
                                     const std::vector<int> &hole) {
    static const std::vector<std::tuple<int, int, char>> kDirs{
        {1, 0, 'd'}, {0, -1, 'l'}, {0, 1, 'r'}, {-1, 0, 'u'}};
    const int m = maze.size(), n = maze[0].size();

    std::vector visited(m, std::vector<bool>(n));

    std::priority_queue<std::tuple<int, std::string, int, int>,
                        std::vector<std::tuple<int, std::string, int, int>>,
                        std::greater<>>
        minHeap;
    minHeap.push({0, "", ball[0], ball[1]});

    while (!minHeap.empty()) {
      const auto [distance, path, i, j] = minHeap.top();
      minHeap.pop();

      if (visited[i][j]) {
        continue;
      }
      visited[i][j] = true;

      if (i == hole[0] && j == hole[1]) {
        return path;
      }

      for (const auto &[di, dj, dc] : kDirs) {
        int cnt = 0;
        int r = i, c = j;
        while (r + di >= 0 && r + di < m && c + dj >= 0 && c + dj < n &&
               !maze[r + di][c + dj]) {
          ++cnt;
          r += di, c += dj;
          if (r == hole[0] && c == hole[1]) {
            break;
          }
        }

        minHeap.push({distance + cnt, path + dc, r, c});
      }
    }

    return "impossible";
  }
};
