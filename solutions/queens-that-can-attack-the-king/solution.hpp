#pragma once

#include <array>
#include <vector>

// Time: O(N^2), where N = 8
// Space: O(N^2)

class Solution {
public:
  static std::vector<std::vector<int>>
  queensAttacktheKing(const std::vector<std::vector<int>> &queens,
                      const std::vector<int> &king) {
    std::array<std::array<bool, 8>, 8> board{};
    for (const auto &q : queens) {
      board[q[0]][q[1]] = 1;
    }

    const std::vector<std::pair<int, int>> dirs{
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    std::vector<std::vector<int>> ans;
    for (const auto &[di, dj] : dirs) {
      for (int i = king[0], j = king[1]; 0 <= i && i < 8 && 0 <= j && j < 8;
           i += di, j += dj) {
        if (board[i][j]) {
          ans.push_back({i, j});
          break;
        }
      }
    }
    return ans;
  }
};
