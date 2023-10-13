#pragma once

#include <algorithm>
#include <cctype>
#include <set>
#include <string>
#include <vector>

class Solution {
public:
  static std::vector<std::string>
  findWords(const std::vector<std::string> &words) {
    const std::vector<int> rows{2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3,
                                3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3};
    std::vector<std::string> ans;
    for (const auto &word : words) {
      std::set<int> set;
      std::transform(
          word.begin(), word.end(), std::inserter(set, set.begin()),
          [&rows](unsigned char c) { return rows[std::tolower(c) - 'a']; });
      if (set.size() == 1) {
        ans.push_back(word);
      }
    }
    return ans;
  }
};
