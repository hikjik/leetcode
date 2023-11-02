#pragma once

#include <array>
#include <string>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::string tictactoe(const std::vector<std::vector<int>> &moves) {
    std::array<std::array<int, 3>, 2> rows{}, cols{}, diag{};
    for (size_t k = 0; k < moves.size(); ++k) {
      const auto i = moves[k][0], j = moves[k][1];
      const auto player = k & 1;
      if (++rows[player][i] == 3 || ++cols[player][j] == 3 ||
          (i == j && ++diag[player][0] == 3) ||
          (i + j == 2 && ++diag[player][1] == 3))
        return player ? "B" : "A";
    }
    return moves.size() == 9 ? "Draw" : "Pending";
  }
};
