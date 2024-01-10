#pragma once

#include <string>

// Time: O(N)
// Space: O(1)

namespace memo {

// Time: O(N)
// Space: O(N)
class Solution {
private:
  static constexpr int kMod = 1e9 + 7;

  static int mul(long long a, long long b, int mod = kMod) {
    return a * b % mod;
  }

  static int sum(long long a, long long b, int mod = kMod) {
    return (a + b) % mod;
  }

  static int count(char c) { return c == '*' ? 9 : c != '0'; }

  static int count(char c1, char c2) {
    if (c1 == '*') {
      return c2 == '*' ? 15 : 1 + (c2 <= '6');
    }
    if (c1 == '1') {
      return c2 == '*' ? 9 : 1;
    }
    if (c1 == '2') {
      return c2 == '*' ? 6 : c2 <= '6';
    }
    return 0;
  }

public:
  static int numDecodings(std::string s) {
    const int n = s.size();
    std::vector<int> memo(n, -1);

    std::function<int(int)> ways = [&](int i) -> int {
      if (i > n || s[i] == '0') {
        return 0;
      }
      if (i == n) {
        return 1;
      }
      if (memo[i] != -1) {
        return memo[i];
      }
      memo[i] = mul(count(s[i]), ways(i + 1));
      if (i < n - 1) {
        memo[i] = sum(memo[i], mul(count(s[i], s[i + 1]), ways(i + 2)));
      }
      return memo[i];
    };

    return ways(0);
  }
};

} // namespace memo

namespace dp {

// Time: O(N)
// Space: O(N)
class Solution {
private:
  static constexpr int kMod = 1e9 + 7;

  static int mul(long long a, long long b, int mod = kMod) {
    return a * b % mod;
  }

  static int sum(long long a, long long b, int mod = kMod) {
    return (a + b) % mod;
  }

  static int count(char c) { return c == '*' ? 9 : c != '0'; }

  static int count(char c1, char c2) {
    if (c1 == '*') {
      return c2 == '*' ? 15 : 1 + (c2 <= '6');
    }
    if (c1 == '1') {
      return c2 == '*' ? 9 : 1;
    }
    if (c1 == '2') {
      return c2 == '*' ? 6 : c2 <= '6';
    }
    return 0;
  }

public:
  static int numDecodings(std::string s) {
    const int n = s.size();
    std::vector<int> dp(n + 1);
    dp[n] = 1;
    dp[n - 1] = count(s[n - 1]);
    for (int i = n - 2; i >= 0; --i) {
      dp[i] = sum(mul(count(s[i]), dp[i + 1]),
                  mul(count(s[i], s[i + 1]), dp[i + 2]));
    }
    return dp[0];
  }
};

} // namespace dp

namespace opt {

// Time: O(N)
// Space: O(1)
class Solution {
private:
  static constexpr int kMod = 1e9 + 7;

  static int mul(long long a, long long b, int mod = kMod) {
    return a * b % mod;
  }

  static int sum(long long a, long long b, int mod = kMod) {
    return (a + b) % mod;
  }

  static int count(char c) { return c == '*' ? 9 : c != '0'; }

  static int count(char c1, char c2) {
    if (c1 == '*') {
      return c2 == '*' ? 15 : 1 + (c2 <= '6');
    }
    if (c1 == '1') {
      return c2 == '*' ? 9 : 1;
    }
    if (c1 == '2') {
      return c2 == '*' ? 6 : c2 <= '6';
    }
    return 0;
  }

public:
  static int numDecodings(std::string s) {
    int a = 1, b = count(s.back());
    for (int i = s.size() - 2; i >= 0; --i) {
      a = std::exchange(
          b, sum(mul(count(s[i]), b), mul(count(s[i], s[i + 1]), a)));
    }
    return b;
  }
};

} // namespace opt
