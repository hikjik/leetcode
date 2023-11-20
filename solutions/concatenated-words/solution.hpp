#pragma once

#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Time: O(NM^3)
// Space: O(N+M)

namespace memo {

// Time: O(NM^3)
// Space: O(N+M)
class Solution {
public:
  static std::vector<std::string>
  findAllConcatenatedWordsInADict(const std::vector<std::string> &words) {
    std::unordered_set<std::string_view> wordDict(words.begin(), words.end());
    std::unordered_map<std::string_view, bool> memo;

    std::vector<std::string> ans;
    for (std::string_view sv : words) {
      if (isConcatenatedWord(sv, wordDict, &memo)) {
        ans.emplace_back(sv);
      }
    }
    return ans;
  }

private:
  static bool
  isConcatenatedWord(std::string_view s,
                     const std::unordered_set<std::string_view> &wordDict,
                     std::unordered_map<std::string_view, bool> *memo) {
    if (auto it = memo->find(s); it != memo->end()) {
      return it->second;
    }
    auto &ans = (*memo)[s];
    for (int i = 1; i < std::ssize(s); ++i) {
      if (wordDict.contains(s.substr(0, i)) &&
          (wordDict.contains(s.substr(i)) ||
           isConcatenatedWord(s.substr(i), wordDict, memo))) {
        return ans = true;
      }
    }
    return ans = false;
  }
};

} // namespace memo

namespace dp {

// Time: O(NM^3)
// Space: O(N+M)
class Solution {
public:
  static std::vector<std::string>
  findAllConcatenatedWordsInADict(const std::vector<std::string> &words) {
    std::unordered_set<std::string_view> wordDict(words.begin(), words.end());

    std::vector<std::string> ans;
    for (std::string_view sv : words) {
      const int n = sv.size();

      std::vector<bool> dp(sv.size() + 1);
      dp[0] = true;

      for (int i = 1; i <= n; ++i) {
        for (int j = i == n; j < i; ++j) {
          if (dp[j] && wordDict.contains(sv.substr(j, i - j))) {
            dp[i] = true;
            break;
          }
        }
      }

      if (dp.back()) {
        ans.emplace_back(sv);
      }
    }
    return ans;
  }
};

} // namespace dp
