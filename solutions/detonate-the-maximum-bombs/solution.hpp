#pragma once

#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int maximumDetonation(const std::vector<std::vector<int>> &bombs) {
    const auto graph = buildGraph(bombs);

    size_t max_size = 1;
    for (size_t i = 0; i < graph.size(); ++i) {
      std::unordered_set<int> visited;
      dfs(i, graph, &visited);
      max_size = std::max(max_size, visited.size());
    }
    return max_size;
  }

private:
  static void dfs(size_t i, const std::vector<std::vector<int>> &graph,
                  std::unordered_set<int> *visited) {
    visited->insert(i);
    for (auto j : graph[i]) {
      if (!visited->count(j)) {
        dfs(j, graph, visited);
      }
    }
  }

  static std::vector<std::vector<int>>
  buildGraph(const std::vector<std::vector<int>> &bombs) {
    std::vector<std::vector<int>> graph(bombs.size());
    for (size_t i = 0; i < bombs.size(); ++i) {
      for (size_t j = 0; j < bombs.size(); ++j) {
        if (i != j) {
          const auto radius = bombs[i][2];
          if (radius >= computeDistance(bombs[i], bombs[j])) {
            graph[i].push_back(j);
          }
        }
      }
    }
    return graph;
  }

  static double computeDistance(const std::vector<int> &first_bomb,
                                const std::vector<int> &second_bomb) {
    const auto x1 = first_bomb[0], y1 = first_bomb[1];
    const auto x2 = second_bomb[0], y2 = second_bomb[1];
    return std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
  }
};
