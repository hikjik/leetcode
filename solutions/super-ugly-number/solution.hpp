#pragma once

#include <climits>
#include <vector>

// K = primes.size()
// Time: O(NK)
// Space: O(N+K)

class Solution {
public:
  static int nthSuperUglyNumber(int n, const std::vector<int> &primes) {
    std::vector<int> ids(primes.size());
    std::vector<long long> nums{1};
    while (--n) {
      auto num = LLONG_MAX;
      for (int i = 0; i < std::ssize(primes); ++i) {
        num = std::min(num, primes[i] * nums[ids[i]]);
      }
      nums.push_back(num);
      for (int i = 0; i < std::ssize(primes); ++i) {
        if (nums[ids[i]] * primes[i] == num) {
          ++ids[i];
        }
      }
    }
    return nums.back();
  }
};
