#pragma once

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int similarPairs(const std::vector<std::string> &words) {
    std::unordered_map<std::string, int> counter;
    int cnt = 0;
    for (const auto &word : words) {
      cnt += counter[normalize(word)]++;
    }
    return cnt;
  }

private:
  static std::string normalize(std::string str) {
    std::sort(str.begin(), str.end());
    return {str.begin(), std::unique(str.begin(), str.end())};
  }
};
