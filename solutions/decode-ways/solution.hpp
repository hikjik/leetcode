#pragma once

#include <string>
#include <string_view>
#include <vector>

// Time: O(N)
// Space: O(N)

namespace memo {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int numDecodings(std::string s) {
    std::vector<int> memo(s.size() + 1, -1);
    memo[0] = 1;
    return numDecodings(std::string_view(s), &memo);
  }

private:
  static int numDecodings(std::string_view s, std::vector<int> *memo) {
    auto &ways = (*memo)[s.size()];
    if (ways != -1) {
      return ways;
    }

    ways = 0;
    if (s[0] != '0') {
      ways += numDecodings(s.substr(1), memo);
    }
    if (s.size() > 1) {
      if (s[0] == '1' || s[0] == '2' && s[1] < '7') {
        ways += numDecodings(s.substr(2), memo);
      }
    }
    return ways;
  }
};

} // namespace memo

namespace dp {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int numDecodings(std::string s) {
    const int n = s.size();

    std::vector<int> dp(n + 1);
    dp[n] = 1;
    dp[n - 1] = s[n - 1] != '0';

    for (int i = n - 2; i >= 0; --i) {
      if (s[i] != '0') {
        dp[i] += dp[i + 1];
      }
      if (s[i] == '1' || s[i] == '2' && s[i + 1] < '7') {
        dp[i] += dp[i + 2];
      }
    }

    return dp[0];
  }
};

} // namespace dp
