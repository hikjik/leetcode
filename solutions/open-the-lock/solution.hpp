#pragma once

#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
  static int openLock(const std::vector<std::string> &deadends,
                      std::string target) {
    std::unordered_set<std::string> visited{deadends.begin(), deadends.end()};
    const std::string start_wheel = "0000";
    if (visited.count(start_wheel)) {
      return -1;
    }

    std::queue<std::pair<std::string, int>> queue;
    queue.emplace(start_wheel, 0);
    visited.insert(start_wheel);
    while (!queue.empty()) {
      auto [wheel, distance] = queue.front();
      queue.pop();

      if (wheel == target) {
        return distance;
      }

      for (size_t i = 0; i < wheel.size(); ++i) {
        char c = wheel[i];
        for (auto dc : {-1, 1}) {
          wheel[i] = (c - '0' + dc + 10) % 10 + '0';
          if (!visited.count(wheel)) {
            queue.emplace(wheel, distance + 1);
            visited.insert(wheel);
          }
        }
        wheel[i] = c;
      }
    }
    return -1;
  }
};
