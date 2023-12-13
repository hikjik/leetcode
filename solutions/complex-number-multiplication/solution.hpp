#pragma once

#include <complex>
#include <string>

// Time: O(1)
// Space: O(1)

class Solution {
public:
  static std::string complexNumberMultiply(std::string num1, std::string num2) {
    return complexToString(stringToComplex(num1) * stringToComplex(num2));
  }

private:
  static std::complex<int> stringToComplex(const std::string &num) {
    const auto pos = num.find_first_of('+');
    return std::complex<int>(std::stoi(num.substr(0, pos)),
                             std::stoi(num.substr(pos + 1)));
  }

  static std::string complexToString(std::complex<int> num) {
    return std::to_string(num.real()) + "+" + std::to_string(num.imag()) + "i";
  }
};
