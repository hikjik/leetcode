#pragma once

#include <string>
#include <unordered_map>
#include <vector>

// Time: O(N^2)
// Space: O(N)

class Solution {
public:
  static std::string findTheString(const std::vector<std::vector<int>> &lcp) {
    const int n = lcp.size();
    std::string s(n, '0');
    char c = 'a';
    for (int i = 0; i < n; ++i) {
      if (s[i] != '0') {
        continue;
      }
      if (c > 'z') {
        return "";
      }
      for (int j = i; j < n; ++j) {
        if (lcp[i][j]) {
          s[j] = c;
        }
      }
      ++c;
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int v = s[i] == s[j];
        if (v && i + 1 < n && j + 1 < n) {
          v += lcp[i + 1][j + 1];
        }
        if (lcp[i][j] != v) {
          return "";
        }
      }
    }
    return s;
  }
};
