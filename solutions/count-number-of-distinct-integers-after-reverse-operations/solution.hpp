#pragma once

#include <unordered_set>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int countDistinctIntegers(const std::vector<int> &nums) {
    std::unordered_set<int> set(nums.begin(), nums.end());
    for (auto a : nums) {
      set.insert(reverse(a));
    }
    return set.size();
  }

private:
  static int reverse(int n) {
    int rev = 0;
    for (; n; n /= 10) {
      rev = rev * 10 + n % 10;
    }
    return rev;
  }
};
