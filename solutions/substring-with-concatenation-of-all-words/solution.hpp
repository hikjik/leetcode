#pragma once

#include <string>
#include <unordered_map>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<int> findSubstring(const std::string &s,
                                        const std::vector<std::string> &words) {
    const int n = s.size();
    const int m = words.size();
    const int k = words.back().size();

    std::unordered_map<std::string, int> map;
    for (const auto &word : words) {
      ++map[word];
    }

    std::vector<int> ans;
    for (int i = 0; i < n - k * m + 1; ++i) {
      std::unordered_map<std::string, int> seen;
      int j = 0;
      for (; j < m; ++j) {
        const auto &word = s.substr(i + j * k, k);
        if (++seen[word] > map[word]) {
          break;
        }
      }
      if (j == m) {
        ans.push_back(i);
      }
    }
    return ans;
  }
};
