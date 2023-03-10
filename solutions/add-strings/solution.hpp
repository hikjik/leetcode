#pragma once

#include <string>

class Solution {
public:
  static std::string addStrings(std::string num1, std::string num2) {
    std::string sum;
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0 || carry) {
      int d = (i >= 0 ? num1[i--] - '0' : 0) + (j >= 0 ? num2[j--] - '0' : 0) +
              carry;
      sum += '0' + d % 10;
      carry = d / 10;
    }
    std::reverse(sum.begin(), sum.end());
    return sum;
  }
};
