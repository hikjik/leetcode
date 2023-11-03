#pragma once

#include <array>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

// Time: O(N^4)
// Space: O(N^3)

namespace memo {

// Time: O(N^4)
// Space: O(N^3)
class Solution {
private:
  template <class T, class U> struct PairHasher {
    std::size_t operator()(const std::pair<T, U> &p) const {
      return std::hash<T>()(p.first) ^ std::hash<U>()(p.second);
    }
  };

  using StringPair = std::pair<std::string_view, std::string_view>;
  using StringPairHasher = PairHasher<std::string_view, std::string_view>;
  using Memo = std::unordered_map<StringPair, bool, StringPairHasher>;

public:
  static bool isScramble(std::string s1, std::string s2) {
    Memo memo;
    return isScramble(std::string_view(s1), std::string_view(s2), &memo);
  }

  static bool isScramble(std::string_view s1, std::string_view s2, Memo *memo) {
    if (s1 == s2) {
      return true;
    }

    const auto key = std::make_pair(s1, s2);
    if (auto it = memo->find(key); it != memo->end()) {
      return it->second;
    }

    auto &is_scramble = (*memo)[key];

    const int n = s1.size();
    std::array<int, 26> counter{};
    for (int i = 0; i < n; ++i) {
      ++counter[s1[i] - 'a'], --counter[s2[i] - 'a'];
    }
    for (auto c : counter) {
      if (c) {
        return is_scramble = false;
      }
    }

    for (int i = 1; i < n; ++i) {
      if (isScramble(s1.substr(0, i), s2.substr(0, i), memo) &&
          isScramble(s1.substr(i), s2.substr(i), memo)) {
        return is_scramble = true;
      }
      if (isScramble(s1.substr(0, i), s2.substr(n - i), memo) &&
          isScramble(s1.substr(i), s2.substr(0, n - i), memo)) {
        return is_scramble = true;
      }
    }
    return is_scramble = false;
  }
};

} // namespace memo

namespace dp {

// Time: O(N^4)
// Space: O(N^3)
class Solution {
public:
  static constexpr size_t kN = 30;

  static bool isScramble(std::string s1, std::string s2) {
    const int n = s1.size();
    std::array<std::array<std::array<int, kN>, kN>, kN + 1> dp{};
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dp[1][i][j] = s1[i] == s2[j];
      }
    }

    for (int length = 2; length <= n; ++length) {
      for (int i = 0; i < n + 1 - length; ++i) {
        for (int j = 0; j < n + 1 - length; ++j) {
          for (int new_length = 1; new_length < length; new_length++) {
            const auto &dp1 = dp[new_length][i];
            const auto &dp2 = dp[length - new_length][i + new_length];
            dp[length][i][j] |= dp1[j] && dp2[j + new_length];
            dp[length][i][j] |= dp1[j + length - new_length] && dp2[j];
          }
        }
      }
    }
    return dp[n][0][0];
  }
};

} // namespace dp
