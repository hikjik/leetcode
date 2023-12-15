#pragma once

#include <vector>

// Time: O(N)
// Space: O(1)

namespace prefix_sum {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int waysToMakeFair(const std::vector<int> &nums) {
    const int n = nums.size();
    std::vector<int> odd(n + 1);
    std::vector<int> even(n + 1);
    for (int i = 1; i <= n; ++i) {
      odd[i] += odd[i - 1];
      even[i] += even[i - 1];
      if (i & 1) {
        odd[i] += nums[i - 1];
      } else {
        even[i] += nums[i - 1];
      }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      const auto oddSum = odd[i] + even[n] - even[i + 1];
      const auto evenSum = even[i] + odd[n] - odd[i + 1];
      ans += oddSum == evenSum;
    }
    return ans;
  }
};

} // namespace prefix_sum

namespace optimized {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static int waysToMakeFair(const std::vector<int> &nums) {
    std::vector<int> left(2), right(2);
    for (int i = 0; i < std::ssize(nums); ++i) {
      right[i & 1] += nums[i];
    }

    int ans = 0;
    for (int i = 0; i < std::ssize(nums); ++i) {
      right[i & 1] -= nums[i];
      ans += left[0] + right[1] == left[1] + right[0];
      left[i & 1] += nums[i];
    }
    return ans;
  }
};

} // namespace optimized
