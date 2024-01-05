#pragma once

#include <climits>
#include <vector>

// Time: O(KlogN)
// Space: O(1)

namespace memo {

// Time: O(KNlogN)
// Space: O(KN)
class Solution {
public:
  static int superEggDrop(int k, int n) {
    std::vector memo(k + 1, std::vector<int>(n + 1, -1));
    return superEggDrop(k, n, &memo);
  }

private:
  static int superEggDrop(int k, int n, std::vector<std::vector<int>> *memo) {
    if (k == 1 || n == 0) {
      return n;
    }
    auto &ans = (*memo)[k][n];
    if (ans == -1) {
      ans = n;
      int l = 1, r = n;
      while (l <= r) {
        const auto m = l + (r - l) / 2;
        const auto a = superEggDrop(k, n - m, memo);
        const auto b = superEggDrop(k - 1, m - 1, memo);

        ans = std::min(ans, 1 + std::max(a, b));

        a < b ? r = m - 1 : l = m + 1;
      }
    }
    return ans;
  }
};

} // namespace memo

namespace dp {

// Time: O(KNlogN)
// Space: O(KN)
class Solution {
public:
  static int superEggDrop(int k, int n) {
    std::vector dp(k + 1, std::vector<int>(n + 1, n));
    for (int i = 0; i <= n; ++i) {
      dp[1][i] = i;
    }
    for (int i = 0; i <= k; ++i) {
      dp[i][0] = 0;
    }
    for (int i = 1; i <= k; ++i) {
      for (int j = 1; j <= n; ++j) {
        int l = 1, r = j;
        int ans = n;
        while (l <= r) {
          const auto m = l + (r - l) / 2;
          const auto a = dp[i][j - m];
          const auto b = dp[i - 1][m - 1];

          ans = std::min(ans, 1 + std::max(a, b));

          a < b ? r = m - 1 : l = m + 1;
        }
        dp[i][j] = ans;
      }
    }
    return dp[k][n];
  }
};

} // namespace dp

namespace dp2 {

// Time: O(KN)
// Space: O(KN)
class Solution {
public:
  static int superEggDrop(int k, int n) {
    // dp[m][k] is the most number of floors that we can check
    // with m moves and k eggs
    std::vector dp(n, std::vector<int>(k + 1, 0));
    for (int m = 1; m < n; ++m) {
      for (int i = 1; i <= k; ++i) {
        dp[m][i] = 1 + dp[m - 1][i] + dp[m - 1][i - 1];
      }
      if (dp[m][k] >= n) {
        return m;
      }
    }
    return n;
  }
};

} // namespace dp2

namespace dp2_opt {

// Time: O(KlogN)
// Space: O(K)
class Solution {
public:
  static int superEggDrop(int k, int n) {
    std::vector<int> dp(k + 1, 0);
    for (int m = 1; m < n; ++m) {
      for (int i = k; i >= 1; --i) {
        dp[i] += 1 + dp[i - 1];
      }
      if (dp[k] >= n) {
        return m;
      }
    }
    return n;
  }
};

} // namespace dp2_opt

namespace dp2_math {

// Time: O(KlogN)
// Space: O(1)
class Solution {
public:
  // dp(m, k) = C(m, 1) + C(m, 2) + ... + C(m, k)
  // C(m, i) = C(m, i - 1) * (m - i + 1) / i
  static int superEggDrop(int k, int n) {
    auto dp = [n](int m, int k) {
      int ans = 0;
      for (int c = 1, i = 1; i <= k && ans < n; ++i) {
        c = c * (m - i + 1) / i;
        ans += c;
      }
      return ans;
    };

    int l = 1, r = n;
    while (l < r) {
      const auto m = l + (r - l) / 2;
      dp(m, k) < n ? l = m + 1 : r = m;
    }
    return l;
  }
};

} // namespace dp2_math
