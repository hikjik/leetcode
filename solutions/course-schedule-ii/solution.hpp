#pragma once

#include <queue>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<int>
  findOrder(int num_courses,
            const std::vector<std::vector<int>> &prerequisites) {
    std::vector<std::vector<int>> graph(num_courses);
    std::vector<int> in_degree(num_courses);
    for (const auto &edge : prerequisites) {
      const auto u = edge[0], v = edge[1];
      graph[v].push_back(u);
      in_degree[u]++;
    }

    std::queue<int> queue;
    for (int u = 0; u < num_courses; ++u) {
      if (!in_degree[u]) {
        queue.push(u);
      }
    }

    std::vector<int> courses;
    while (!queue.empty()) {
      auto u = queue.front();
      queue.pop();

      courses.push_back(u);

      for (auto v : graph[u]) {
        if (!--in_degree[v]) {
          queue.push(v);
        }
      }
    }

    if (num_courses * 1UL != courses.size()) {
      return {};
    }
    return courses;
  }
};
