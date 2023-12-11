#pragma once

#include <numeric>
#include <vector>

// Time: O(N+M)
// Space: O(1)

class Solution {
public:
  static int getXORSum(const std::vector<int> &arr1,
                       const std::vector<int> &arr2) {
    return std::accumulate(arr1.begin(), arr1.end(), 0, std::bit_xor{}) &
           std::accumulate(arr2.begin(), arr2.end(), 0, std::bit_xor{});
  }
};
