#pragma once

#include <queue>
#include <unordered_set>
#include <vector>

// Time: O(V+E)
// Space: O(V+E)

class Solution {
public:
  enum class Color { kWhite, kGrey, kBlack };

  static bool leadsToDestination(int n,
                                 const std::vector<std::vector<int>> &edges,
                                 int source, int destination) {
    std::vector<std::unordered_set<int>> graph(n);
    for (const auto &edge : edges) {
      graph[edge[0]].insert(edge[1]);
    }

    std::vector<Color> colors(n, Color::kWhite);

    std::function<bool(int u)> dfs = [&](int u) {
      if (colors[u] != Color::kWhite) {
        return colors[u] == Color::kBlack;
      }
      if (graph[u].empty()) {
        return u == destination;
      }
      colors[u] = Color::kGrey;
      for (auto v : graph[u]) {
        if (!dfs(v)) {
          return false;
        }
      }
      colors[u] = Color::kBlack;
      return true;
    };

    return dfs(source);
  }
};
