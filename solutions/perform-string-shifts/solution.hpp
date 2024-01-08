#pragma once

#include <algorithm>
#include <string>
#include <vector>

// Time: O(N+L)
// Space: O(N)

class Solution {
public:
  static std::string stringShift(std::string s,
                                 const std::vector<std::vector<int>> &shift) {
    int k = 0;
    for (const auto &move : shift) {
      k += move[0] ? -move[1] : +move[1];
    }

    const int n = s.size();
    k = (n + k % n) % n;
    return s.substr(k) + s.substr(0, k);
  }
};
