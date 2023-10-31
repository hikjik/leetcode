#pragma once

#include <functional>
#include <numeric>
#include <vector>

class Solution {
public:
  static std::vector<int> findArray(const std::vector<int> &pref) {
    std::vector<int> arr(pref.size());
    std::adjacent_difference(pref.begin(), pref.end(), arr.begin(),
                             std::bit_xor{});
    return arr;
  }
};
