#pragma once

#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  static int numOfStrings(const std::vector<std::string> &patterns,
                          std::string word) {
    return std::count_if(patterns.begin(), patterns.end(), [&](const auto &p) {
      return word.find(p) != std::string::npos;
    });
  }
};
