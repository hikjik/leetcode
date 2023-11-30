#pragma once

#include <ranges>
#include <string>
#include <vector>

// Time: O(NM)
// Space: O(1)

class Solution {
public:
  static int numberOfBeams(const std::vector<std::string> &bank) {
    int ans = 0;
    for (int prev = 0; const auto &row : bank) {
      const int cnt = std::ranges::count(row, '1');
      if (cnt) {
        ans += prev * cnt;
        prev = cnt;
      }
    }
    return ans;
  }
};
