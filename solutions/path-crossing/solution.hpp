#pragma once

#include <set>
#include <string>

class Solution {
public:
  static bool isPathCrossing(std::string path) {
    const std::pair<int, int> start{0, 0};
    std::set<std::pair<int, int>> visited{start};
    for (auto node = start; auto c : path) {
      if (c == 'N') {
        ++node.second;
      } else if (c == 'S') {
        --node.second;
      } else if (c == 'E') {
        ++node.first;
      } else if (c == 'W') {
        --node.first;
      } else {
        throw;
      }

      if (!visited.insert(node).second) {
        return true;
      }
    }
    return false;
  }
};
