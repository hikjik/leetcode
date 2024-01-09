#pragma once

#include <array>
#include <string>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static bool isStrobogrammatic(std::string num) {
    static const std::array<int, 10> rotated{0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
    for (int l = 0, r = num.size() - 1; l <= r; ++l, --r) {
      if (num[l] - '0' != rotated[num[r] - '0']) {
        return false;
      }
    }
    return true;
  }
};
