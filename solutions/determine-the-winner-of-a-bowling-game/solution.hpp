#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static int isWinner(const std::vector<int> &player1,
                      const std::vector<int> &player2) {
    const auto score1 = computeScore(player1), score2 = computeScore(player2);
    if (score1 > score2) {
      return 1;
    }
    if (score2 > score1) {
      return 2;
    }
    return 0;
  }

private:
  static int computeScore(const std::vector<int> &player) {
    int score = 0;
    for (size_t i = 0; i < player.size(); ++i) {
      if (i && player[i - 1] == 10 || i > 1 && player[i - 2] == 10) {
        score += 2 * player[i];
      } else {
        score += player[i];
      }
    }
    return score;
  }
};
