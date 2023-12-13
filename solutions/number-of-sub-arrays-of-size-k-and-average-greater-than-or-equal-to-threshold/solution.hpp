#pragma once

#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int numOfSubarrays(const std::vector<int> &arr, int k, int threshold) {
    int ans = 0;
    for (int sum = 0, i = 0; i < std::ssize(arr); ++i) {
      sum += arr[i];
      if (i >= k - 1) {
        ans += sum >= k * threshold;
        sum -= arr[i - k + 1];
      }
    }
    return ans;
  }
};
