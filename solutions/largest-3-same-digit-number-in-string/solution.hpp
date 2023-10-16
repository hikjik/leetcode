#pragma once

#include <algorithm>
#include <string>

class Solution {
public:
  static std::string largestGoodInteger(std::string num) {
    std::string ans;
    for (size_t i = 0; i + 2 < num.size(); ++i) {
      if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
        ans = std::max(ans, num.substr(i, 3));
      }
    }
    return ans;
  }
};
