#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static std::vector<int> plusOne(std::vector<int> &digits) {
    std::vector<int> result;
    result.reserve(digits.size() + 1);

    int carry = 1;
    for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
      int sum = carry + *it;
      carry = sum / 10;
      result.push_back(sum % 10);
    }
    if (carry) {
      result.push_back(carry);
    }

    std::reverse(result.begin(), result.end());
    return result;
  }
};
