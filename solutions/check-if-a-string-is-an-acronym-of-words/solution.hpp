#pragma once

#include <string>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static bool isAcronym(const std::vector<std::string> &words, std::string s) {
    std::string acronym;
    for (const auto &word : words) {
      acronym += word.front();
    }
    return acronym == s;
  }
};
