#pragma once

#include <string>
#include <vector>

// N = words.size()
// K = words[i].size()
// Time: O(N^2K)
// Space: O(1)

class Solution {
public:
  static int countPrefixSuffixPairs(const std::vector<std::string> &words) {
    int ans = 0;
    for (int i = 0; i < std::ssize(words); ++i) {
      for (int j = 0; j < i; ++j) {
        ans += isPrefixSuffix(words[j], words[i]);
      }
    }
    return ans;
  }

private:
  static bool isPrefixSuffix(const std::string &s, const std::string &t) {
    return t.size() >= s.size() && t.starts_with(s) && t.ends_with(s);
  }
};
