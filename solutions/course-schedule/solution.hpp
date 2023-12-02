#pragma once

#include <queue>
#include <ranges>
#include <vector>

// Time: O(V+E), V = |prerequisites|, E = numCourses
// Space: O(V+E)
// Notes: [Kahn's algorithm](https://w.wiki/8MeV)

class Solution {
public:
  static bool canFinish(int numCourses,
                        const std::vector<std::vector<int>> &prerequisites) {
    std::vector<int> in_degree(numCourses);
    std::vector<std::vector<int>> graph(numCourses);
    for (const auto &edge : prerequisites) {
      ++in_degree[edge[1]];
      graph[edge[0]].push_back(edge[1]);
    }

    std::queue<int> queue;
    for (int u = 0; u < numCourses; ++u) {
      if (!in_degree[u]) {
        queue.push(u);
      }
    }

    while (!queue.empty()) {
      const auto u = queue.front();
      queue.pop();

      for (auto v : graph[u]) {
        if (!--in_degree[v]) {
          queue.push(v);
        }
      }
    }

    return std::ranges::all_of(in_degree, [](int a) { return !a; });
  }
};
