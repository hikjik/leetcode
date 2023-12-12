#pragma once

#include <string>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static std::vector<std::string>
  getWordsInLongestSubsequence(int n, const std::vector<std::string> &words,
                               const std::vector<int> &groups) {
    std::vector<std::string> ans;
    for (int group = -1, i = 0; i < n; ++i) {
      if (groups[i] != group) {
        group = groups[i];
        ans.push_back(words[i]);
      }
    }
    return ans;
  }
};
