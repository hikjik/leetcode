#pragma once

#include <array>
#include <ranges>
#include <string>
#include <vector>

// Time: O(NlogN)
// Space: O(N)

class Solution {
public:
  static int maxPalindromesAfterOperations(std::vector<std::string> words) {
    std::array<int, 26> counter{};
    int cnt = 0;
    for (const auto &word : words) {
      for (auto c : word) {
        ++counter[c - 'a'];
        cnt += counter[c - 'a'] % 2 == 0;
      }
    }

    std::ranges::sort(words, {}, std::ranges::size);
    int ans = 0;
    for (const auto &word : words) {
      cnt -= word.size() / 2;
      ans += cnt >= 0;
    }
    return ans;
  }
};
