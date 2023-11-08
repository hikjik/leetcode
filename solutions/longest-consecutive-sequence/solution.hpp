#pragma once

#include <algorithm>
#include <unordered_set>
#include <vector>

// Time: O(N)
// Space: O(N)

namespace sorting {

// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
  static int longestConsecutive(std::vector<int> nums) {
    std::sort(nums.begin(), nums.end());

    int ans = 0;
    for (int i = 0, cnt = 0; i < std::ssize(nums); ++i) {
      if (!i || nums[i] == nums[i - 1] + 1) {
        ++cnt;
      } else if (nums[i] != nums[i - 1]) {
        cnt = 1;
      }
      ans = std::max(ans, cnt);
    }
    return ans;
  }
};

} // namespace sorting

namespace hash_table {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int longestConsecutive(const std::vector<int> &nums) {
    std::unordered_set<int> set(nums.begin(), nums.end());
    int ans = 0;
    for (auto num : set) {
      if (!set.contains(num - 1)) {
        int len = 1;
        while (set.contains(num + len)) {
          ++len;
        }
        ans = std::max(ans, len);
      }
    }
    return ans;
  }
};

} // namespace hash_table
