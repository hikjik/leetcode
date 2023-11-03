#pragma once

#include <queue>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<int>
  eventualSafeNodes(const std::vector<std::vector<int>> &graph) {
    std::vector<std::vector<int>> reversed_graph(graph.size());
    std::vector<bool> is_safe(graph.size(), false);
    std::vector<int> out_degree(graph.size(), 0);

    std::queue<int> queue;
    for (size_t i = 0; i < graph.size(); ++i) {
      for (auto j : graph[i]) {
        reversed_graph[j].push_back(i);
      }
      out_degree[i] = graph[i].size();
      if (!out_degree[i]) {
        queue.push(i);
      }
    }

    while (!queue.empty()) {
      auto i = queue.front();
      queue.pop();

      is_safe[i] = true;

      for (auto j : reversed_graph[i]) {
        if (!--out_degree[j]) {
          queue.push(j);
        }
      }
    }

    std::vector<int> safe_nodes;
    for (size_t i = 0; i < graph.size(); ++i) {
      if (is_safe[i]) {
        safe_nodes.push_back(i);
      }
    }
    return safe_nodes;
  }
};
