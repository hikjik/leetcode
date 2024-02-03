#pragma once

#include <climits>
#include <unordered_map>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static long long maximumSubarraySum(const std::vector<int> &nums, int k) {
    std::unordered_map<int, long long> ps;
    long long ans = LONG_LONG_MIN;
    for (long long sum = 0; auto num : nums) {
      if (ps.contains(num - k)) {
        ans = std::max(ans, sum + num - ps[num - k]);
      }
      if (ps.contains(num + k)) {
        ans = std::max(ans, sum + num - ps[num + k]);
      }

      ps[num] = std::min(sum, ps.contains(num) ? ps[num] : sum);
      sum += num;
    }
    return ans == LONG_LONG_MIN ? 0 : ans;
  }
};
