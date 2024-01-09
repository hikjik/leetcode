#pragma once

#include <queue>
#include <vector>

// Time: O(V+E)
// Space: O(V+E)

class Solution {
public:
  static int minimumSemesters(int n,
                              const std::vector<std::vector<int>> &relations) {
    std::vector<std::vector<int>> graph(n);
    std::vector<int> inDegree(n);
    for (const auto &edge : relations) {
      graph[edge[0] - 1].push_back(edge[1] - 1);
      ++inDegree[edge[1] - 1];
    }

    std::queue<int> queue;
    for (int u = 0; u < n; ++u) {
      if (!inDegree[u]) {
        queue.push(u);
      }
    }

    int ans = 0;
    int cnt = 0;
    while (!queue.empty()) {
      ++ans;
      for (int sz = queue.size(); sz; --sz) {
        const auto u = queue.front();
        queue.pop();

        ++cnt;

        for (auto v : graph[u]) {
          if (!--inDegree[v]) {
            queue.push(v);
          }
        }
      }
    }
    return cnt == n ? ans : -1;
  }
};
