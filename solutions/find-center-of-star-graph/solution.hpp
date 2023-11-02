#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static int findCenter(const std::vector<std::vector<int>> &edges) {
    if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
      return edges[0][0];
    }
    return edges[0][1];
  }
};
