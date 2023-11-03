#pragma once

#include <string>
#include <vector>

// Time: O(N4^N)
// Space: O(N)

namespace brute_force {

// Time: O(N4^N)
// Space: O(N)
// Brute Force
class Solution {
public:
  static std::vector<std::string> generateParenthesis(int n) {
    auto isValid = [n](int i) {
      int cnt = 0;
      for (int k = 0; k < 2 * n; ++k) {
        cnt += (i >> k) & 1 ? 1 : -1;
        if (cnt < 0) {
          return false;
        }
      }
      return cnt == 0;
    };

    std::vector<std::string> combinations;
    for (int i = 0; i < 1 << (2 * n); i++) {
      if (isValid(i)) {
        std::string s;
        for (int k = 0; k < 2 * n; ++k) {
          s += (i >> k) & 1 ? '(' : ')';
        }
        combinations.push_back(std::move(s));
      }
    }
    return combinations;
  }
};

} // namespace brute_force

namespace backtracking {

// Time: O(N4^N)
// Space: O(N)
// Backtracing
class Solution {
public:
  static std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> combinations;
    std::string combination;
    generateParenthesis(n, n, &combinations, &combination);
    return combinations;
  }

private:
  static void generateParenthesis(int open, int close,
                                  std::vector<std::string> *combinations,
                                  std::string *combination) {
    if (!open && !close) {
      combinations->push_back(*combination);
      return;
    }
    if (open) {
      combination->push_back('(');
      generateParenthesis(open - 1, close, combinations, combination);
      combination->pop_back();
    }
    if (close > open) {
      combination->push_back(')');
      generateParenthesis(open, close - 1, combinations, combination);
      combination->pop_back();
    }
  }
};

} // namespace backtracking

namespace dp {

// Time: O(N C(N)), where C(N) - Catalan number
// Space: O(N C(N))
// Dynamic Programming
class Solution {
public:
  static std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::vector<std::string>> dp(n + 1);
    dp[0] = {""};
    for (int i = 0; i < n + 1; ++i) {
      for (int j = 0; j < i; ++j) {
        for (const auto &x : dp[j]) {
          for (const auto &y : dp[i - j - 1]) {
            dp[i].push_back('(' + x + ')' + y);
          }
        }
      }
    }
    return dp[n];
  }
};

} // namespace dp
