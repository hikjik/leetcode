#pragma once

#include <unordered_map>
#include <unordered_set>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int countCompleteSubarrays(const std::vector<int> &nums) {
    const int totalDistinct =
        std::unordered_set<int>(nums.begin(), nums.end()).size();
    int ans = 0;
    std::unordered_map<int, int> counter;
    for (int i = 0, distinct = 0; auto num : nums) {
      distinct += !counter[num]++;
      while (distinct == totalDistinct) {
        distinct -= !--counter[nums[i++]];
      }
      ans += i;
    }
    return ans;
  }
};
