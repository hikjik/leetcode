#pragma once

#include <queue>
#include <vector>

/*
  909. Snakes and Ladders
  https://leetcode.com/problems/snakes-and-ladders/
  Difficulty: Medium
  Tags: Array, Breadth-First Search, Matrix
  Time:
  Space:
*/

class Solution {
public:
  static int snakesAndLadders(const std::vector<std::vector<int>> &board) {
    const int n = board.size();
    const int source = 1, target = n * n;

    std::queue<int> queue{{source}};
    std::vector<bool> visited(n * n + 1, false);
    visited[source] = true;

    for (int steps = 1; !queue.empty(); ++steps) {
      for (int size = queue.size(); size > 0; --size) {
        const auto i = queue.front();
        queue.pop();

        for (int j = i + 1; j <= std::min(i + 6, n * n); ++j) {
          const auto dest = getDestination(j, board);
          if (dest == target) {
            return steps;
          }

          if (!visited[dest]) {
            visited[dest] = true;
            queue.push(dest);
          }
        }
      }
    }
    return -1;
  }

private:
  static int getDestination(int i, const std::vector<std::vector<int>> &board) {
    const int n = board.size();
    const int row = n - 1 - (i - 1) / n;
    const int col = (i - 1) / n % 2 == 0 ? (i - 1) % n : n - 1 - (i - 1) % n;
    return board[row][col] == -1 ? i : board[row][col];
  }
};
