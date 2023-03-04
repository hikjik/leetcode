#pragma once

#include <string>

class Solution {
public:
  static std::string multiply(std::string num1, std::string num2) {
    std::string num(num1.size() + num2.size(), '0');
    for (int i = num1.size() - 1; i >= 0; --i) {
      for (int j = num2.size() - 1; j >= 0; --j) {
        const auto p =
            (num1[i] - '0') * (num2[j] - '0') + (num[i + j + 1] - '0');
        num[i + j] += p / 10;
        num[i + j + 1] = '0' + p % 10;
      }
    }
    const auto pos = num.find_first_not_of('0');
    return pos == std::string::npos ? "0" : num.substr(pos, num.size() - pos);
  }
};
