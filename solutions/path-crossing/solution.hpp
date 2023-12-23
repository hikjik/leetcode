#pragma once

#include <string>
#include <unordered_set>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static bool isPathCrossing(std::string path) {
    const int n = path.size() + 1;
    std::unordered_set<int> seen{{0}};
    for (int x = 0, y = 0; auto c : path) {
      x += (c == 'E') - (c == 'W');
      y += (c == 'N') - (c == 'S');
      if (!seen.insert(x * n + y).second) {
        return true;
      }
    }
    return false;
  }
};
