#pragma once

#include <string>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int removeAlmostEqualCharacters(std::string word) {
    int ans = 0;
    for (int i = 1; i < std::ssize(word); ++i) {
      if (std::abs(word[i] - word[i - 1]) < 2) {
        ++ans;
        ++i;
      }
    }
    return ans;
  }
};
