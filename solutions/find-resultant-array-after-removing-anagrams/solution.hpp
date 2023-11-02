#pragma once

#include <algorithm>
#include <string>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<std::string>
  removeAnagrams(const std::vector<std::string> &words) {
    std::vector<std::string> ans;
    for (const auto &word : words) {
      if (ans.empty() || !IsAnagrams(ans.back(), word)) {
        ans.push_back(word);
      }
    }
    return ans;
  }

private:
  static bool IsAnagrams(std::string first, std::string second) {
    std::sort(first.begin(), first.end());
    std::sort(second.begin(), second.end());
    return first == second;
  }
};
