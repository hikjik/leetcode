#pragma once

#include <ranges>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Time: O(2^N)
// Space: O(2^N)

namespace backtracking {

// Time: O(2^N)
// Space: O(2^N)
class Solution {
public:
  static std::vector<std::string>
  wordBreak(std::string s, const std::vector<std::string> &wordList) {
    std::unordered_set<std::string_view> wordSet{wordList.begin(),
                                                 wordList.end()};
    std::string sentence;
    std::vector<std::string> sentences;
    wordBreak(std::string_view(s), wordSet, &sentence, &sentences);
    return sentences;
  }

private:
  static constexpr int kMaxLen = 10;

  static void wordBreak(std::string_view s,
                        const std::unordered_set<std::string_view> &wordSet,
                        std::string *sentence,
                        std::vector<std::string> *sentences) {
    if (s.empty()) {
      sentences->push_back(*sentence);
      return;
    }

    for (int i = 1; i <= std::ssize(s) && i <= kMaxLen; ++i) {
      if (wordSet.contains(s.substr(0, i))) {
        if (!sentence->empty()) {
          sentence->push_back(' ');
        }
        sentence->append(s.substr(0, i));
        wordBreak(s.substr(i), wordSet, sentence, sentences);
        const auto pos = sentence->find_last_of(' ');
        sentence->erase(pos == std::string::npos ? 0 : pos);
      }
    }
  }
};

} // namespace backtracking

namespace memo {

// Time: O(2^N)
// Space: O(2^N)
class Solution {
public:
  static std::vector<std::string>
  wordBreak(std::string s, const std::vector<std::string> &wordList) {
    std::unordered_set<std::string_view> wordSet{wordList.begin(),
                                                 wordList.end()};
    std::unordered_map<int, std::vector<std::string>> memo;
    return wordBreak(s, wordSet, &memo);
  }

private:
  static constexpr int kMaxLen = 10;

  static std::vector<std::string>
  wordBreak(const std::string &s,
            const std::unordered_set<std::string_view> &wordSet,
            std::unordered_map<int, std::vector<std::string>> *memo) {
    if (auto it = memo->find(s.size()); it != memo->end()) {
      return it->second;
    }
    std::vector<std::string> ans;
    for (int i = 1; i <= std::ssize(s) && i <= kMaxLen; ++i) {
      const auto &word = s.substr(0, i);
      if (wordSet.contains(word)) {
        if (i == std::ssize(s)) {
          ans.push_back(word);
        } else {
          for (const auto &sentence : wordBreak(s.substr(i), wordSet, memo)) {
            ans.push_back(word + " " + sentence);
          }
        }
      }
    }
    return (*memo)[s.size()] = std::move(ans);
  }
};

} // namespace memo

namespace dp {

// Time: O(2^N)
// Space: O(2^N)
class Solution {
public:
  static constexpr int kMaxLen = 10;

  static std::vector<std::string>
  wordBreak(std::string s, const std::vector<std::string> &wordList) {
    std::unordered_set<std::string_view> wordSet{wordList.begin(),
                                                 wordList.end()};
    std::vector<std::vector<std::string>> dp(s.size());
    for (int i = 0; i < std::ssize(s); ++i) {
      for (int j = i; i - j + 1 <= kMaxLen && j >= 0; --j) {
        const auto &word = s.substr(j, i - j + 1);
        if (wordSet.contains(word)) {
          if (j == 0) {
            dp[i].push_back(word);
          } else {
            for (const auto &sentence : dp[j - 1]) {
              dp[i].push_back(sentence + " " + word);
            }
          }
        }
      }
    }
    return dp.back();
  }
};

} // namespace dp
