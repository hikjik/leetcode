#pragma once

#include <vector>

// Time: O(NloglogN)
// Space: O(N)

class Solution {
private:
  static constexpr int kMaxN = 1e6;

  static std::array<bool, kMaxN> sieveEratosthenes() {
    std::array<bool, kMaxN> isPrime;
    isPrime.fill(true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < kMaxN; ++i) {
      if (isPrime[i]) {
        for (int j = i * i; j < kMaxN; j += i) {
          isPrime[j] = false;
        }
      }
    }
    return isPrime;
  }

public:
  static std::vector<std::vector<int>> findPrimePairs(int n) {
    static const auto isPrime = sieveEratosthenes();

    std::vector<std::vector<int>> ans;
    for (int i = 2; i <= n / 2; ++i) {
      if (isPrime[i] && isPrime[n - i]) {
        ans.push_back({i, n - i});
      }
    }
    return ans;
  }
};
