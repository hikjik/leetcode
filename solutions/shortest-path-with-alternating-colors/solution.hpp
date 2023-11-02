#pragma once

#include <queue>
#include <vector>

// Time:
// Space:

class Solution {
public:
  using Color = int;
  static inline const int RED = 0;
  static inline const int BLUE = 1;

  static std::vector<int>
  shortestAlternatingPaths(int n, const std::vector<std::vector<int>> &redEdges,
                           const std::vector<std::vector<int>> &blueEdges) {
    std::vector<std::vector<std::pair<int, Color>>> graph(n);
    for (const auto &edge : redEdges) {
      graph[edge[0]].emplace_back(edge[1], RED);
    }
    for (const auto &edge : blueEdges) {
      graph[edge[0]].emplace_back(edge[1], BLUE);
    }

    std::vector<std::vector<bool>> visited(2, std::vector<bool>(n, false));
    visited[RED][0] = true;
    visited[BLUE][0] = true;

    std::queue<std::tuple<int, Color, int>> queue;
    queue.emplace(0, RED, 0);
    queue.emplace(0, BLUE, 0);

    std::vector<int> distances(n, -1);
    while (!queue.empty()) {
      const auto [u, prev_color, distance] = queue.front();
      queue.pop();

      if (distances[u] == -1) {
        distances[u] = distance;
      }

      for (const auto &[v, color] : graph[u]) {
        if (!visited[color][v] && color != prev_color) {
          visited[color][v] = true;
          queue.emplace(v, color, distance + 1);
        }
      }
    }
    return distances;
  }
};
