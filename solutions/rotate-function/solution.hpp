#pragma once

#include <numeric>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int maxRotateFunction(const std::vector<int> &nums) {
    const int n = nums.size();
    const int sum = std::accumulate(nums.begin(), nums.end(), 0);

    int f = 0;
    for (int i = 0; i < n; ++i) {
      f += nums[i] * i;
    }

    int ans = f;
    for (int i = 1; i < n; ++i) {
      f += sum - n * nums[n - i];
      ans = std::max(ans, f);
    }
    return ans;
  }
};
