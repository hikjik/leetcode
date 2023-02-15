#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static std::vector<int> plusOne(std::vector<int> &digits) {
    std::vector<int> result;
    result.reserve(digits.size() + 1);

    int r = 1;
    for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
      int k = r + *it;
      r = k / 10;
      result.push_back(k % 10);
    }
    if (r) {
      result.push_back(r);
    }

    std::reverse(result.begin(), result.end());
    return result;
  }
};
