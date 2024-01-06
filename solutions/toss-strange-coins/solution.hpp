#pragma once

#include <vector>

// Time: O(NT)
// Space: O(T)

namespace memo {

// Time: O(NT)
// Space: O(NT)
class Solution {
public:
  static double probabilityOfHeads(const std::vector<double> &prob,
                                   int target) {
    std::vector memo(prob.size(), std::vector<double>(target + 1, -1.0));
    return probabilityOfHeads(0, target, prob, &memo);
  }

private:
  static double probabilityOfHeads(int i, int target,
                                   const std::vector<double> &prob,
                                   std::vector<std::vector<double>> *memo) {
    if (i == std::ssize(prob)) {
      return target == 0;
    }
    auto &ans = (*memo)[i][target];
    if (ans == -1.0) {
      ans = (1 - prob[i]) * probabilityOfHeads(i + 1, target, prob, memo);
      if (target) {
        ans += prob[i] * probabilityOfHeads(i + 1, target - 1, prob, memo);
      }
    }
    return ans;
  }
};

} // namespace memo

namespace dp {

// Time: O(NT)
// Space: O(NT)
class Solution {
public:
  static double probabilityOfHeads(const std::vector<double> &prob,
                                   int target) {
    const int n = prob.size();
    std::vector dp(n + 1, std::vector<double>(target + 1));
    dp[n][0] = 1.0;
    for (int i = n - 1; i >= 0; --i) {
      for (int t = 0; t <= target; ++t) {
        dp[i][t] = (1 - prob[i]) * dp[i + 1][t];
        if (t) {
          dp[i][t] += prob[i] * dp[i + 1][t - 1];
        }
      }
    }
    return dp[0][target];
  }
};

} // namespace dp

namespace opt {

// Time: O(NT)
// Space: O(T)
class Solution {
public:
  static double probabilityOfHeads(const std::vector<double> &prob,
                                   int target) {
    std::vector<double> dp(target + 1);
    dp[0] = 1.0;
    for (int i = prob.size() - 1; i >= 0; --i) {
      for (int t = target; t >= 0; --t) {
        dp[t] = (1 - prob[i]) * dp[t] + (t ? prob[i] * dp[t - 1] : 0);
      }
    }
    return dp.back();
  }
};

} // namespace opt
