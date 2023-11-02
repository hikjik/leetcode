#pragma once

#include <algorithm>
#include <string>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static bool checkZeroOnes(std::string s) {
    std::vector<size_t> longest(2);
    for (size_t i = 0, j = 1; i < s.size(); ++j) {
      if (j == s.size() || s[i] != s[j]) {
        longest[s[i] - '0'] = std::max(longest[s[i] - '0'], j - i);
        i = j;
      }
    }
    return longest[1] > longest[0];
  }
};
