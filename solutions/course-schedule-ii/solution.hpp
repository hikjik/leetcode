#pragma once

#include <queue>
#include <vector>

// Time: O(V+E), V = |prerequisites|, E = numCourses
// Space: O(V+E)
// Notes: [Kahn's algorithm](https://w.wiki/8MeV)

class Solution {
public:
  static std::vector<int>
  findOrder(int numCourses,
            const std::vector<std::vector<int>> &prerequisites) {
    std::vector<std::vector<int>> graph(numCourses);
    std::vector<int> degree(numCourses);
    for (const auto &edge : prerequisites) {
      graph[edge[1]].push_back(edge[0]);
      ++degree[edge[0]];
    }

    std::queue<int> queue;
    for (int u = 0; u < numCourses; ++u) {
      if (!degree[u]) {
        queue.push(u);
      }
    }

    std::vector<int> courses;
    while (!queue.empty()) {
      auto u = queue.front();
      queue.pop();

      courses.push_back(u);

      for (auto v : graph[u]) {
        if (!--degree[v]) {
          queue.push(v);
        }
      }
    }

    if (numCourses != std::ssize(courses)) {
      return {};
    }
    return courses;
  }
};
