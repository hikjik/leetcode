#pragma once

#include <set>
#include <unordered_map>

// Time: O(QlogN+QK)
// Space: O(N)

class Leaderboard {
public:
  // O(logN)
  void addScore(int playerId, int score) {
    if (auto it = players.find(playerId); it != players.end()) {
      score += it->second;
      reset(playerId);
    }
    players[playerId] = score;
    scores.insert(score);
  }

  // O(K)
  int top(int k) {
    int sum = 0;
    for (auto it = scores.rbegin(); k--; ++it) {
      sum += *it;
    }
    return sum;
  }

  // O(logN)
  void reset(int playerId) {
    const auto score = players[playerId];
    scores.erase(scores.find(score));
    players.erase(playerId);
  }

private:
  std::multiset<int> scores;
  std::unordered_map<int, int> players;
};
