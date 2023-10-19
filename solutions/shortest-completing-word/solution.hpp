#pragma once

#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  static std::string
  shortestCompletingWord(std::string licensePlate,
                         const std::vector<std::string> &words) {
    normalize(licensePlate);
    std::string ans(16, '.');
    for (const auto &word : words) {
      if (word.size() < ans.size() && isCompletingWord(word, licensePlate)) {
        ans = word;
      }
    }
    return ans;
  }

  static void normalize(std::string &str) {
    str.erase(std::remove_if(str.begin(), str.end(),
                             [](unsigned char c) { return !std::isalpha(c); }),
              str.end());
    std::transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    std::sort(str.begin(), str.end());
  }

  static bool isCompletingWord(std::string word, std::string licensePlate) {
    std::sort(word.begin(), word.end());
    return std::includes(word.begin(), word.end(), licensePlate.begin(),
                         licensePlate.end());
  }
};
