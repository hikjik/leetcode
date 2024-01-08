#pragma once

#include <string>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static bool isOneEditDistance(std::string s, std::string t) {
    if (s.size() > t.size()) {
      std::swap(s, t);
    }
    const auto [it1, it2] = std::ranges::mismatch(s, t);
    if (it1 != s.end() && it2 != t.end()) {
      if (s.size() == t.size()) {
        return std::equal(it1 + 1, s.end(), it2 + 1, t.end());
      }
      return std::equal(it1, s.end(), it2 + 1, t.end());
    }
    return s.size() + 1 == t.size();
  }
};
