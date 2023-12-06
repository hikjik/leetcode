#pragma once

#include <string>
#include <unordered_map>

// Time: O(N)
// Space: O(A)

class Solution {
public:
  static int longestPalindrome(std::string s) {
    std::unordered_map<char, int> counter;
    for (auto c : s) {
      ++counter[c];
    }

    int odds = 0;
    for (const auto &[c, f] : counter) {
      odds += f & 1;
    }
    return s.size() - odds + (odds > 0);
  }
};
