#pragma once

#include <ranges>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static std::vector<int> plusOne(std::vector<int> digits) {
    for (int i = digits.size() - 1; i >= 0; --i) {
      if (digits[i]++ < 9) {
        return digits;
      }
      digits[i] = 0;
    }
    digits.insert(digits.begin(), 1);
    return digits;
  }
};
