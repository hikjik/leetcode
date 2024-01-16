#pragma once

#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int dietPlanPerformance(const std::vector<int> &calories, int k,
                                 int lower, int upper) {
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < std::ssize(calories); ++i) {
      sum += calories[i];
      if (i >= k - 1) {
        ans += (sum > upper) - (sum < lower);
        sum -= calories[i - k + 1];
      }
    }
    return ans;
  }
};
