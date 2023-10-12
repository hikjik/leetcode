#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static int findTheDistanceValue(const std::vector<int> &arr1,
                                  std::vector<int> arr2, int d) {
    std::sort(arr2.begin(), arr2.end());
    int total = 0;
    for (auto a : arr1) {
      auto lower = std::lower_bound(arr2.begin(), arr2.end(), a - d);
      auto upper = std::lower_bound(arr2.begin(), arr2.end(), a + d + 1);
      if (!std::distance(lower, upper)) {
        total += 1;
      }
    }
    return total;
  }
};
