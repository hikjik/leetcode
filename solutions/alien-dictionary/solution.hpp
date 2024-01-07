#pragma once

#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Time: O(NK)
// Space: O(A^2)

class Solution {
public:
  static std::string alienOrder(const std::vector<std::string> &words) {
    std::unordered_map<char, std::unordered_set<char>> graph;
    for (const auto &word : words) {
      for (auto c : word) {
        graph[c];
      }
    }

    for (int i = 0; i + 1 < std::ssize(words); ++i) {
      const int size = std::min(words[i].size(), words[i + 1].size());
      if (words[i].size() > words[i + 1].size() &&
          words[i].substr(0, size) == words[i + 1]) {
        return "";
      }
      for (int j = 0; j < size; ++j) {
        if (words[i][j] != words[i + 1][j]) {
          graph[words[i][j]].insert(words[i + 1][j]);
          break;
        }
      }
    }

    return TopologicalSort(graph);
  }

private:
  static std::string TopologicalSort(
      const std::unordered_map<char, std::unordered_set<char>> &graph) {
    const int n = graph.size();

    std::unordered_map<char, int> inDegree(n);
    for (const auto &[u, adj] : graph) {
      for (auto v : adj) {
        ++inDegree[v];
      }
    }

    std::queue<char> queue;
    for (const auto &[u, _] : graph) {
      if (!inDegree[u]) {
        queue.push(u);
      }
    }

    std::string order;
    while (!queue.empty()) {
      const auto u = queue.front();
      queue.pop();

      order.push_back(u);
      for (auto v : graph.at(u)) {
        if (!--inDegree[v]) {
          queue.push(v);
        }
      }
    }

    if (order.size() != graph.size()) {
      return "";
    }
    return order;
  }
};
