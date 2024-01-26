#pragma once

#include <array>
#include <vector>

// Time: O(Q)
// Space: O(1)

class ATM {
public:
  // O(1)
  void deposit(const std::vector<int> &banknotesCount) {
    for (int i = 0; i < kN; ++i) {
      count[i] += banknotesCount[i];
    }
  }

  // O(1)
  std::vector<int> withdraw(int amount) {
    std::vector<int> ans(kN);
    for (int i = kN - 1; i >= 0; --i) {
      ans[i] = std::min(count[i], amount * 1LL / banknotes[i]);
      amount -= ans[i] * banknotes[i];
    }
    if (amount) {
      return {-1};
    }

    for (int i = kN - 1; i >= 0; --i) {
      count[i] -= ans[i];
    }

    return ans;
  }

private:
  static constexpr int kN = 5;

  std::array<int, kN> banknotes{20, 50, 100, 200, 500};
  std::array<long long, kN> count{};
};
