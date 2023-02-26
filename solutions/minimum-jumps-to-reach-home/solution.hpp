#pragma once

#include <queue>
#include <vector>

class Solution {
  static const int MAX_LENGTH = 6000;

public:
  static int minimumJumps(const std::vector<int> &forbidden, int a, int b,
                          int x) {
    std::vector<std::vector<bool>> visited(
        2, std::vector<bool>(MAX_LENGTH + 1, false));
    for (auto f : forbidden) {
      visited[0][f] = visited[1][f] = true;
    }

    std::queue<std::tuple<int, int, bool>> queue;
    queue.emplace(0, 0, false);
    visited[0][0] = visited[1][0] = true;

    while (!queue.empty()) {
      const auto [y, jumps, backward] = queue.front();
      queue.pop();

      if (y == x) {
        return jumps;
      }

      if (y + a <= MAX_LENGTH && !visited[0][y + a]) {
        queue.emplace(y + a, jumps + 1, false);
        visited[0][y + a] = true;
      }
      if (!backward && y - b >= 0 && !visited[1][y - b]) {
        queue.emplace(y - b, jumps + 1, true);
        visited[1][y - b] = true;
      }
    }

    return -1;
  }
};
