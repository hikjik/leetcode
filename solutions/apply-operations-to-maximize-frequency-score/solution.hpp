#pragma once

#include <numeric>
#include <ranges>
#include <vector>

// Time: O(N)
// Space: O(N)

namespace bs {

// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
  static int maxFrequencyScore(std::vector<int> nums, long long k) {
    const int n = nums.size();
    std::ranges::sort(nums);

    std::vector<long long> ps(n + 1);
    for (int i = 1; i <= n; ++i) {
      ps[i] = ps[i - 1] + nums[i - 1];
    }

    int l = 1, r = n + 1;
    while (l < r) {
      const auto m = l + (r - l + 1) / 2;
      bool ok = false;
      for (int i = 0; i < n - m + 1; ++i) {
        if (ps[i + m] - ps[i + (m + 1) / 2] - ps[i + m / 2] + ps[i] <= k) {
          ok = true;
          break;
        }
      }
      ok ? l = m : r = m - 1;
    }
    return l;
  }
};

} // namespace bs

namespace sw {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int maxFrequencyScore(std::vector<int> nums, long long k) {
    std::ranges::sort(nums);
    int ans = 0;
    long long sum = 0;
    for (int l = 0, r = 0; r < std::ssize(nums); ++r) {
      sum += nums[r] - nums[(l + r) / 2];
      for (; sum > k; ++l) {
        sum -= nums[(l + r + 1) / 2] - nums[l];
      }
      ans = std::max(ans, r - l + 1);
    }
    return ans;
  }
};

} // namespace sw
