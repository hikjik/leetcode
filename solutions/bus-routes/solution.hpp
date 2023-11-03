#pragma once

#include <queue>
#include <unordered_map>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int numBusesToDestination(const std::vector<std::vector<int>> &routes,
                                   int source, int target) {
    std::unordered_map<int, std::vector<int>> stops_to_routes;
    for (size_t i = 0; i < routes.size(); ++i) {
      for (const auto &stop : routes[i]) {
        stops_to_routes[stop].push_back(i);
      }
    }

    std::vector<bool> visited(routes.size());
    std::queue<int> queue{{source}};
    for (int steps = 0; !queue.empty(); ++steps) {
      for (int size = queue.size(); size > 0; --size) {
        const auto stop = queue.front();
        queue.pop();

        if (stop == target) {
          return steps;
        }

        for (const auto &route : stops_to_routes[stop]) {
          if (!visited[route]) {
            visited[route] = true;
            for (auto stop : routes[route]) {
              queue.push(stop);
            }
          }
        }
      }
    }

    return -1;
  }
};
