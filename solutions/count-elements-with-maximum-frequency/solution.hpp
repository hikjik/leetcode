#pragma once

#include <unordered_map>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int maxFrequencyElements(const std::vector<int> &nums) {
    std::unordered_map<int, int> cnt;
    int ans = 0;
    for (int maxFreq = 0; auto num : nums) {
      if (++cnt[num] == maxFreq) {
        ans += maxFreq;
      } else if (cnt[num] > maxFreq) {
        maxFreq = cnt[num];
        ans = maxFreq;
      }
    }
    return ans;
  }
};
