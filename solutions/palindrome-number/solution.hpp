#pragma once

#include <algorithm>
#include <string>

// Time: O(logN)
// Space: O(logN)

class Solution {
public:
  static bool isPalindrome(int n) {
    const auto str = std::to_string(n);
    return std::equal(str.cbegin(), str.cbegin() + str.size() / 2,
                      str.crbegin());
  }
};
