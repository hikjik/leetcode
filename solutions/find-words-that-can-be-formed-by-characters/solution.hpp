#pragma once

#include <ranges>
#include <string>
#include <vector>

// N = chars.size(), M = words.size(), K = words[i].size(), A = |alphabet|
// Time: O(N+MK+MA)
// Space: O(A)

namespace sorting {

// Time: O(NlogN + MKlogK + M(K+N))
// Space: O(N+K)
class Solution {
public:
  static int countCharacters(const std::vector<std::string> &words,
                             std::string chars) {
    std::ranges::sort(chars);
    int ans = 0;
    for (auto word : words) {
      std::ranges::sort(word);
      if (std::ranges::includes(chars, word)) {
        ans += word.size();
      }
    }
    return ans;
  }
};

} // namespace sorting

namespace counting {

// Time: O(N+MK+MA)
// Space: O(A)
class Solution {
public:
  static int countCharacters(const std::vector<std::string> &words,
                             const std::string &chars) {
    std::array<int, 26> cnt{};
    for (auto c : chars) {
      ++cnt[c - 'a'];
    }

    int ans = 0;
    for (const auto &word : words) {
      if (isGood(word, cnt)) {
        ans += word.size();
      }
    }
    return ans;
  }

private:
  static bool isGood(const std::string &w, std::array<int, 26> cnt) {
    return std::ranges::all_of(w, [&](char c) { return --cnt[c - 'a'] >= 0; });
  }
};

} // namespace counting
