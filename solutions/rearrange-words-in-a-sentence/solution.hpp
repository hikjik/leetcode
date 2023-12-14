#pragma once

#include <numeric>
#include <sstream>
#include <string>
#include <vector>

// Time: O(NlogN)
// Space: O(N)

class Solution {
public:
  static std::string arrangeWords(std::string text) {
    text[0] += 'a' - 'A';

    const int n = text.size();
    std::vector<std::pair<int, int>> words;
    for (int i = 0, j = 0; j <= n; ++j) {
      if (j == n || text[j] == ' ') {
        words.push_back({j - i, i});
        i = j + 1;
      }
    }
    std::ranges::sort(words);

    std::string ans;
    for (const auto &[length, start] : words) {
      std::ranges::copy(text.begin() + start, text.begin() + start + length,
                        std::back_inserter(ans));
      ans += ' ';
    }
    ans.pop_back();
    ans[0] += 'A' - 'a';
    return ans;
  }
};
