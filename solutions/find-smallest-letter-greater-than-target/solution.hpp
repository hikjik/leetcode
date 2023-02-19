#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static char nextGreatestLetter(const std::vector<char> &letters,
                                 char target) {
    if (target >= letters.back()) {
      return letters.front();
    }
    return *std::upper_bound(letters.begin(), letters.end(), target);
  }
};
