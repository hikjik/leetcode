#pragma once

#include <queue>
#include <vector>

/*
  1030. Matrix Cells in Distance Order
  https://leetcode.com/problems/matrix-cells-in-distance-order/
  Difficulty: Easy
  Tags: Array, Math, Geometry, Sorting, Matrix
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<std::vector<int>>
  allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
    static const std::vector<std::pair<int, int>> dirs{
        {0, -1}, {1, 0}, {-1, 0}, {0, 1}};

    std::vector visited(rows, std::vector<bool>(cols));
    visited[rCenter][cCenter] = true;

    std::queue<std::pair<int, int>> queue;
    queue.emplace(rCenter, cCenter);

    std::vector<std::vector<int>> ans;
    while (!queue.empty()) {
      const auto [i, j] = queue.front();
      queue.pop();

      ans.push_back({i, j});

      for (const auto &[di, dj] : dirs) {
        const auto r = i + di, c = j + dj;
        if (r >= 0 && r < rows && c >= 0 && c < cols && !visited[r][c]) {
          queue.emplace(r, c);
          visited[r][c] = true;
        }
      }
    }
    return ans;
  }
};
