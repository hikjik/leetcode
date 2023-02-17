#pragma once

#include <algorithm>
#include <string>

class Solution {
public:
  static std::string addBinary(std::string a, std::string b) {
    std::string result;
    result.reserve(std::max(a.size(), b.size()) + 1);

    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0 || carry) {
      int sum =
          carry + (i >= 0 ? a[i--] - '0' : 0) + (j >= 0 ? b[j--] - '0' : 0);
      carry = sum / 2;
      result += '0' + sum % 2;
    }

    std::reverse(result.begin(), result.end());
    return result;
  }
};
