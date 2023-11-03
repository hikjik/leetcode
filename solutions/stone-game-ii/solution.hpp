#pragma once

#include <algorithm>
#include <numeric>
#include <vector>

// Time:
// Space:

class Solution {
public:
  int stoneGameII(const std::vector<int> &piles) {
    const int n = piles.size();
    memo_.resize(n, std::vector<int>(n, -1));

    std::vector<int> suffix_sum(n);
    std::partial_sum(piles.rbegin(), piles.rend(), suffix_sum.rbegin());

    return stoneGameII(0, 1, suffix_sum);
  }

private:
  std::vector<std::vector<int>> memo_;

  int stoneGameII(size_t i, size_t m, const std::vector<int> &suffix_sum) {
    if (i + 2 * m >= suffix_sum.size()) {
      return suffix_sum[i];
    }

    auto &score = memo_[i][m];
    if (score != -1) {
      return score;
    }

    int opponent_score = suffix_sum[i];
    for (size_t x = 1; x <= 2 * m; ++x) {
      opponent_score = std::min(opponent_score,
                                stoneGameII(i + x, std::max(m, x), suffix_sum));
    }

    return score = suffix_sum[i] - opponent_score;
  }
};
