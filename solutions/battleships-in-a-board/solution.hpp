#pragma once

#include <vector>

// Time: O(NM)
// Space: O(1)

class Solution {
public:
  static int countBattleships(const std::vector<std::vector<char>> &board) {
    int ans = 0;
    for (int i = 0; i < std::ssize(board); ++i) {
      for (int j = 0; j < std::ssize(board.back()); ++j) {
        if (board[i][j] == 'X' && (!i || board[i - 1][j] == '.') &&
            (!j || board[i][j - 1] == '.')) {
          ++ans;
        }
      }
    }
    return ans;
  }
};
