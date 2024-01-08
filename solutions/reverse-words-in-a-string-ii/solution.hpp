#pragma once

#include <algorithm>
#include <ranges>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static void reverseWords(std::vector<char> &s) {
    std::ranges::reverse(s);
    for (auto l = s.begin(), r = s.begin(); l != s.end(); ++r) {
      if (r == s.end() || std::isspace(*r)) {
        std::ranges::reverse(l, r);
        l = r == s.end() ? s.end() : std::next(r);
      }
    }
  }
};
