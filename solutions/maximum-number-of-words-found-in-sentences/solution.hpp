#pragma once

#include <algorithm>
#include <string>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int mostWordsFound(const std::vector<std::string> &sentences) {
    int ans = 0;
    for (const auto &s : sentences) {
      const int words_count = std::count(s.begin(), s.end(), ' ') + 1;
      ans = std::max(ans, words_count);
    }
    return ans;
  }
};
