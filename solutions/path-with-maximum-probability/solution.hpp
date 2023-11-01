#pragma once

#include <queue>
#include <vector>

/*
  1514. Path with Maximum Probability
  https://leetcode.com/problems/path-with-maximum-probability/
  Difficulty: Medium
  Tags: Array, Graph, Heap (Priority Queue), Shortest Path
  Time:
  Space:
*/

class Solution {
public:
  static double maxProbability(int n,
                               const std::vector<std::vector<int>> &edges,
                               const std::vector<double> &succProb, int start,
                               int end) {
    std::vector<std::vector<std::pair<double, int>>> graph(n);
    for (size_t i = 0; i < edges.size(); ++i) {
      const auto u = edges[i][0], v = edges[i][1];
      const auto prob = succProb[i];
      graph[u].push_back({prob, v}), graph[v].push_back({prob, u});
    }

    std::priority_queue<std::pair<double, int>> queue;
    queue.push({1.0, start});

    std::vector<double> max_probs(n);
    max_probs[start] = 1.0;

    while (!queue.empty()) {
      const auto [prob, u] = queue.top();
      queue.pop();

      if (u == end) {
        return prob;
      }

      for (const auto &[edge_prob, v] : graph[u]) {
        if (edge_prob * prob > max_probs[v]) {
          max_probs[v] = edge_prob * prob;
          queue.push({max_probs[v], v});
        }
      }
    }

    return 0.0;
  }
};
