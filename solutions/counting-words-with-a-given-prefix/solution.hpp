#pragma once

#include <algorithm>
#include <string>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int prefixCount(const std::vector<std::string> &words,
                         std::string pref) {
    return count_if(words.begin(), words.end(), [&pref](const auto &word) {
      return word.starts_with(pref);
    });
  }
};
