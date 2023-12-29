#pragma once

#include <vector>

// Time: (KN2^N)
// Space: (2^N)

namespace memo {

// Time: (KN2^N)
// Space: (K2^N)
class Solution {
public:
  static constexpr int kMod = 1e9 + 7;
  static constexpr int kMaxHat = 40;

  static int numberWays(const std::vector<std::vector<int>> &hats) {
    std::vector<std::vector<int>> hatToPeople(kMaxHat + 1);
    for (int p = 0; p < std::ssize(hats); ++p) {
      for (auto h : hats[p]) {
        hatToPeople[h].push_back(p);
      }
    }

    std::vector memo(1 << hats.size(), std::vector<int>(kMaxHat + 1, -1));
    return numberWays(1, 0, hatToPeople, &memo);
  }

private:
  static int numberWays(int h, int mask,
                        const std::vector<std::vector<int>> &hatToPeople,
                        std::vector<std::vector<int>> *memo) {
    if (mask + 1 == std::ssize(*memo)) {
      return 1;
    }
    if (h > kMaxHat) {
      return 0;
    }
    auto &ways = (*memo)[mask][h];
    if (ways == -1) {
      ways = numberWays(h + 1, mask, hatToPeople, memo);
      for (auto p : hatToPeople[h]) {
        if (!(mask & 1 << p)) {
          ways += numberWays(h + 1, mask | 1 << p, hatToPeople, memo);
          ways %= kMod;
        }
      }
    }
    return ways;
  }
};

} // namespace memo

namespace dp {

// Time: (KN2^N)
// Space: (K2^N)
class Solution {
public:
  static constexpr int kMod = 1e9 + 7;
  static constexpr int kMaxHat = 40;

  static int numberWays(const std::vector<std::vector<int>> &hats) {
    std::vector<std::vector<int>> hatToPeople(kMaxHat + 1);
    for (int p = 0; p < std::ssize(hats); ++p) {
      for (auto h : hats[p]) {
        hatToPeople[h].push_back(p);
      }
    }

    std::vector dp(kMaxHat + 1, std::vector<int>(1 << hats.size()));
    dp[0][0] = 1;
    for (int h = 1; h <= kMaxHat; ++h) {
      for (int mask = dp[h].size() - 1; mask >= 0; --mask) {
        dp[h][mask] = dp[h - 1][mask];
        for (auto p : hatToPeople[h]) {
          if (mask & 1 << p) {
            dp[h][mask] = (dp[h][mask] + dp[h - 1][mask ^ 1 << p]) % kMod;
          }
        }
      }
    }
    return dp.back().back();
  }
};

} // namespace dp

namespace optimized {

// Time: (KN2^N)
// Space: (2^N)
class Solution {
public:
  static constexpr int kMod = 1e9 + 7;
  static constexpr int kMaxHat = 40;

  static int numberWays(const std::vector<std::vector<int>> &hats) {
    std::vector<std::vector<int>> hatToPeople(kMaxHat + 1);
    for (int p = 0; p < std::ssize(hats); ++p) {
      for (auto h : hats[p]) {
        hatToPeople[h].push_back(p);
      }
    }

    std::vector<int> dp(1 << hats.size());
    dp[0] = 1;
    for (int h = 1; h <= kMaxHat; ++h) {
      for (int mask = dp.size() - 1; mask >= 0; --mask) {
        for (auto p : hatToPeople[h]) {
          if (mask & 1 << p) {
            dp[mask] = (dp[mask] + dp[mask ^ 1 << p]) % kMod;
          }
        }
      }
    }
    return dp.back();
  }
};

} // namespace optimized
