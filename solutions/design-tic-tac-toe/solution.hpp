#pragma once

#include <vector>

// Time: O(N^2)
// Space: O(N)

class TicTacToe {
public:
  // O(N)
  explicit TicTacToe(int n) : rows(n), cols(n), n(n) {}

  // O(1)
  int move(int i, int j, int player) {
    const auto p = player == 1 ? -1 : 1;
    rows[i] += p;
    cols[j] += p;
    if (i == j) {
      mainDiag += p;
    }
    if (i + j == n - 1) {
      antiDiag += p;
    }
    if (std::abs(rows[i]) == n || std::abs(cols[j]) == n ||
        std::abs(mainDiag) == n || std::abs(antiDiag) == n) {
      return player;
    }
    return 0;
  }

private:
  std::vector<int> rows, cols;
  int n;
  int mainDiag = 0, antiDiag = 0;
};
