#pragma once

#include <algorithm>
#include <climits>
#include <queue>
#include <vector>

class Solution {
public:
  static int findCheapestPrice(int n,
                               const std::vector<std::vector<int>> &flights,
                               int src, int dst, int k) {
    std::vector<std::vector<std::pair<int, int>>> graph(n);
    for (const auto &edge : flights) {
      const auto from = edge[0], to = edge[1], price = edge[2];
      graph[from].push_back({to, price});
    }

    std::vector<int> distances(n, INT_MAX);
    distances[src] = 0;

    std::queue<std::pair<int, int>> queue;
    queue.push({src, 0});

    for (int stops = 0; !queue.empty() && stops <= k; ++stops) {
      for (int sz = queue.size(); sz; --sz) {
        const auto [u, distance] = queue.front();
        queue.pop();

        for (const auto &[v, w] : graph[u]) {
          if (distances[v] > distance + w) {
            distances[v] = distance + w;
            queue.push({v, distance + w});
          }
        }
      }
    }

    return distances[dst] == INT_MAX ? -1 : distances[dst];
  }
};
