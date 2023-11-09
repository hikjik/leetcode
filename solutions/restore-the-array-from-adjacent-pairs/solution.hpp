#pragma once

#include <ranges>
#include <unordered_map>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static std::vector<int>
  restoreArray(const std::vector<std::vector<int>> &adjacentPairs) {
    std::unordered_map<int, std::vector<int>> graph;
    for (const auto &edge : adjacentPairs) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    int u = std::ranges::find_if(graph, [](const auto &p) {
              return p.second.size() == 1;
            })->first;
    std::vector<int> ans(adjacentPairs.size() + 1, u);
    std::transform(
        ans.cbegin(), std::prev(ans.cend()), ans.begin() + 1,
        [&](int v) { return std::swap(u, v), graph[u][graph[u][0] == v]; });
    return ans;
  }
};
