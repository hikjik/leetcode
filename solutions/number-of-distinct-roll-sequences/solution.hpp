#pragma once

#include <array>
#include <numeric>
#include <vector>

// Time: O(NK^3), K = 6
// Space: O(K^2)

namespace memo {

// Time: O(NK^3)
// Space: O(NK^2)
class Solution {
public:
  static int distinctSequences(int n) {
    std::vector memo(n + 1, std::vector(7, std::vector<int>(7)));
    return distinctSequences(n, 0, 0, &memo);
  }

private:
  static constexpr int kMod = 1e9 + 7;

  static int
  distinctSequences(int n, int p, int pp,
                    std::vector<std::vector<std::vector<int>>> *memo) {
    if (n == 0) {
      return 1;
    }
    auto &ans = (*memo)[n][p][pp];
    if (!ans) {
      for (int d = 1; d <= 6; ++d) {
        if (d != p && d != pp && (!p || std::gcd(d, p) == 1)) {
          ans = (ans + distinctSequences(n - 1, d, p, memo)) % kMod;
        }
      }
    }
    return ans;
  }
};

} // namespace memo

namespace dp {

// Time: O(NK^3)
// Space: O(NK^2)
class Solution {
private:
  static constexpr int kMod = 1e9 + 7;

public:
  static int distinctSequences(int n) {
    if (n == 1) {
      return 6;
    }

    std::vector dp(n + 1, std::vector(7, std::vector<int>(7)));
    for (int a = 1; a <= 6; ++a) {
      for (int b = 1; b <= 6; ++b) {
        dp[2][a][b] = a != b && std::gcd(a, b) == 1;
      }
    }

    for (int i = 3; i <= n; ++i) {
      for (int a = 1; a <= 6; ++a) {
        for (int b = 1; b <= 6; ++b) {
          if (dp[2][a][b]) {
            for (int c = 1; c <= 6; ++c) {
              if (a != c && dp[2][b][c]) {
                dp[i][a][b] = (dp[i][a][b] + dp[i - 1][b][c]) % kMod;
              }
            }
          }
        }
      }
    }

    int ans = 0;
    for (int a = 1; a <= 6; ++a) {
      for (int b = 1; b <= 6; ++b) {
        ans = (ans + dp[n][a][b]) % kMod;
      }
    }
    return ans;
  }
};

} // namespace dp

namespace optimized {

// Time: O(NK^3)
// Space: O(K^2)
class Solution {
private:
  static constexpr int kMod = 1e9 + 7;

public:
  static int distinctSequences(int n) {
    if (n == 1) {
      return 6;
    }

    int gcd[7][7]{}, dp[7][7]{};
    for (int a = 1; a <= 6; ++a) {
      for (int b = 1; b <= 6; ++b) {
        dp[a][b] = gcd[a][b] = a != b && std::gcd(a, b) == 1;
      }
    }

    for (int i = 3; i <= n; ++i) {
      int ndp[7][7]{};
      for (int a = 1; a <= 6; ++a) {
        for (int b = 1; b <= 6; ++b) {
          if (gcd[a][b]) {
            for (int c = 1; c <= 6; ++c) {
              if (a != c && gcd[b][c]) {
                ndp[a][b] = (ndp[a][b] + dp[b][c]) % kMod;
              }
            }
          }
        }
      }
      std::swap(dp, ndp);
    }

    int ans = 0;
    for (int a = 1; a <= 6; ++a) {
      for (int b = 1; b <= 6; ++b) {
        ans = (ans + dp[a][b]) % kMod;
      }
    }
    return ans;
  }
};

} // namespace optimized
