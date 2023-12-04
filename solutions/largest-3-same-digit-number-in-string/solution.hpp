#pragma once

#include <algorithm>
#include <string>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static std::string largestGoodInteger(std::string num) {
    std::string ans;
    for (int i = 0; i + 2 < std::ssize(num); ++i) {
      if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
        ans = std::max(ans, num.substr(i, 3));
      }
    }
    return ans;
  }
};
