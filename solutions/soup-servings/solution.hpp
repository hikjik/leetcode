#pragma once

#include <unordered_map>

// Time:
// Space:

class Solution {
public:
  static const size_t kMaxSteps = 171;
  static const size_t kAmount = 25;

  static double soupServings(int n) {
    const size_t steps = (n + kAmount - 1) / kAmount;
    if (steps > kMaxSteps) {
      return 1.0;
    }
    return compute(steps, steps, {});
  }

private:
  static double compute(int A, int B, std::unordered_map<int, double> &&memo) {
    if (A <= 0 && B <= 0) {
      return 0.5;
    }
    if (A <= 0) {
      return 1.0;
    }
    if (B <= 0) {
      return 0.0;
    }

    const auto index = A * 5000 + B;
    if (auto it = memo.find(index); it != memo.end()) {
      return it->second;
    }

    return memo[index] = 0.25 * (compute(A - 4, B, std::move(memo)) +
                                 compute(A - 3, B - 1, std::move(memo)) +
                                 compute(A - 2, B - 2, std::move(memo)) +
                                 compute(A - 1, B - 3, std::move(memo)));
  }
};
