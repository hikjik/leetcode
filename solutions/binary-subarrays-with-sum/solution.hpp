#pragma once

#include <unordered_map>
#include <vector>

// Time: O(N)
// Space: O(1)

namespace ps {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int numSubarraysWithSum(const std::vector<int> &nums, int goal) {
    int ans = 0;
    std::unordered_map<int, int> map{{0, 1}};
    for (int sum = 0; auto num : nums) {
      sum += num;
      if (auto it = map.find(sum - goal); it != map.end()) {
        ans += it->second;
      }
      ++map[sum];
    }
    return ans;
  }
};

} // namespace ps

namespace sw {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static int numSubarraysWithSum(const std::vector<int> &nums, int goal) {
    int ans = 0;
    int sum = 0, zeros = 0;
    for (int l = 0, r = 0; r < std::ssize(nums); ++r) {
      sum += nums[r];
      while (l < r && (sum > goal || nums[l] == 0)) {
        zeros = nums[l] ? 0 : zeros + 1;
        sum -= nums[l++];
      }
      if (sum == goal) {
        ans += 1 + zeros;
      }
    }
    return ans;
  }
};

} // namespace sw
