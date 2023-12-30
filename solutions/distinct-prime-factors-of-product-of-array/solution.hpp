#pragma once

#include <unordered_set>
#include <vector>

// M = max(nums)
// Time: O(NM^(0.5))
// Space: O(M)

class Solution {
public:
  static int distinctPrimeFactors(const std::vector<int> &nums) {
    std::unordered_set<int> primes;
    for (auto num : nums) {
      for (int d = 2; d * d <= num; ++d) {
        if (num % d == 0) {
          primes.insert(d);
          do {
            num /= d;
          } while (num % d == 0);
        }
      }
      if (num > 1) {
        primes.insert(num);
      }
    }
    return primes.size();
  }
};
