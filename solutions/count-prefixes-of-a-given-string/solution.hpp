#pragma once

#include <string>
#include <vector>

class Solution {
public:
  static int countPrefixes(const std::vector<std::string> &words,
                           std::string s) {
    int count = 0;
    for (const auto &word : words) {
      count += s.find(word) == 0;
    }
    return count;
  }
};
