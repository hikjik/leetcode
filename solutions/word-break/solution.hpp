#pragma once

#include <algorithm>
#include <ranges>
#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>

// N is the length of string s
// M is the number of words in the wordList
// K is the maximum length of a word in the wordList
// Time: O(NK^2)
// Space: O(M+N)

namespace memo {

// Time: O(N^2K)
// Space: O(M+N)
class Solution {
public:
  static bool wordBreak(std::string s,
                        const std::vector<std::string> &wordList) {
    std::unordered_set<std::string_view> wordSet{wordList.begin(),
                                                 wordList.end()};
    std::vector<char> memo(s.size() + 1, -1);
    return wordBreak(std::string_view(s), wordSet, &memo);
  }

private:
  static bool wordBreak(std::string_view s,
                        const std::unordered_set<std::string_view> &wordSet,
                        std::vector<char> *memo) {
    if (s.empty()) {
      return true;
    }
    auto &ans = (*memo)[s.size()];
    if (ans == -1) {
      for (int i = 1; i <= std::ssize(s); ++i) {
        if (wordSet.contains(s.substr(0, i)) &&
            wordBreak(s.substr(i), wordSet, memo)) {
          return ans = true;
        }
      }
    }
    return ans = false;
  }
};

} // namespace memo

namespace dp {

// Time: O(N^2K)
// Space: O(M+N)
class Solution {
public:
  static bool wordBreak(std::string s,
                        const std::vector<std::string> &wordList) {
    std::unordered_set<std::string_view> wordSet{wordList.begin(),
                                                 wordList.end()};
    std::string_view view(s);

    std::vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= std::ssize(s); ++i) {
      for (int j = 0; j < i; ++j) {
        if (dp[j] && wordSet.contains(view.substr(j, i - j))) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp.back();
  }
};

} // namespace dp

namespace optimized {

// Time: O(NK^2)
// Space: O(M+N)
class Solution {
public:
  static bool wordBreak(std::string s,
                        const std::vector<std::string> &wordList) {
    std::unordered_set<std::string_view> wordSet{wordList.begin(),
                                                 wordList.end()};
    std::string_view view(s);
    const int max_length =
        std::ranges::max(wordSet, {}, &std::string_view::size).size();

    std::vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= std::ssize(s); ++i) {
      for (int j = i - 1; j >= i - max_length && j >= 0; --j) {
        if (dp[j] && wordSet.contains(view.substr(j, i - j))) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp.back();
  }
};

} // namespace optimized
