#pragma once

#include <queue>
#include <unordered_map>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int minJumps(const std::vector<int> &arr) {
    int n = arr.size();

    std::unordered_map<int, std::vector<int>> graph;
    for (int i = 0; i < n; ++i) {
      graph[arr[i]].push_back(i);
    }

    std::vector<bool> visited(n, false);
    visited[0] = true;

    std::queue<int> queue;
    queue.push(0);

    for (int jumps = 0; !queue.empty(); ++jumps) {
      for (int size = queue.size(); size > 0; --size) {
        auto i = queue.front();
        queue.pop();

        if (i + 1 == n) {
          return jumps;
        }

        if (i > 0 && !visited[i - 1]) {
          queue.push(i - 1);
          visited[i - 1] = true;
        }
        if (i + 1 < n && !visited[i + 1]) {
          queue.push(i + 1);
          visited[i + 1] = true;
        }

        for (auto v : graph[arr[i]]) {
          if (!visited[v]) {
            queue.push(v);
            visited[v] = true;
          }
        }
        graph[arr[i]].clear();
      }
    }

    throw;
  }
};
