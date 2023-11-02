#pragma once

#include <algorithm>
#include <queue>
#include <string>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int largestPathValue(std::string colors,
                              const std::vector<std::vector<int>> &edges) {
    int n = colors.size();
    std::vector<int> in_degree(n, 0);
    std::vector<std::vector<int>> graph(n);
    for (const auto &edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      in_degree[edge[1]]++;
    }

    std::queue<int> queue;
    for (int u = 0; u < n; ++u) {
      if (!in_degree[u]) {
        queue.push(u);
      }
    }

    int color_value = 0;
    int visited_count = 0;
    std::vector<std::vector<int>> count(n, std::vector<int>(26, 0));
    while (!queue.empty()) {
      const auto u = queue.front();
      queue.pop();
      visited_count++;

      color_value = std::max(color_value, ++count[u][colors[u] - 'a']);
      for (auto v : graph[u]) {
        for (int color = 0; color < 26; ++color) {
          count[v][color] = std::max(count[v][color], count[u][color]);
        }

        if (!--in_degree[v]) {
          queue.push(v);
        }
      }
    }

    return visited_count < n ? -1 : color_value;
  }
};
