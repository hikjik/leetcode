#pragma once

#include <numeric>
#include <vector>

// Time: O(N)
// Space: O(1)

namespace prefix_sum {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static std::vector<int>
  getSumAbsoluteDifferences(const std::vector<int> &nums) {
    const int n = nums.size();
    std::vector<int> sums(n);
    std::partial_sum(nums.begin(), nums.end(), sums.begin());
    std::vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
      ans[i] = nums[i] * (2 * i - n + 2) - 2 * sums[i] + sums[n - 1];
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
  static std::vector<int>
  getSumAbsoluteDifferences(const std::vector<int> &nums) {
    const int n = nums.size();
    const int total = std::accumulate(nums.begin(), nums.end(), 0);

    std::vector<int> ans(n);
    for (int sum = 0, i = 0; i < n; sum += nums[i++]) {
      ans[i] = nums[i] * (2 * i - n) - 2 * sum + total;
    }
    return ans;
  }
};

} // namespace optimized
