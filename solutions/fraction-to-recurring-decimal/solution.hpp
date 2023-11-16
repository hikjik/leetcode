#pragma once

#include <climits>
#include <cmath>
#include <string>
#include <unordered_map>

// Time: O(N), where N is the length of answer string <= 10^4
// Space: O(1)

class Solution {
public:
  static std::string fractionToDecimal(long long numerator,
                                       long long denominator) {
    if (numerator == 0) {
      return "0";
    }

    const std::string sign = numerator < 0 != denominator < 0 ? "-" : "";
    numerator = std::abs(numerator), denominator = std::abs(denominator);
    const std::string integral = sign + std::to_string(numerator / denominator);

    auto remainder = std::abs(numerator % denominator);
    if (!remainder) {
      return integral;
    }

    std::string fractional;
    std::unordered_map<int, int> seen;
    while (remainder && !seen.contains(remainder)) {
      seen[remainder] = fractional.size();
      remainder *= 10;
      fractional += std::to_string(remainder / denominator);
      remainder %= denominator;
    }

    if (!remainder) {
      return integral + "." + fractional;
    }
    const auto pre_period = fractional.substr(0, seen[remainder]);
    const auto period = fractional.substr(seen[remainder]);
    return integral + "." + pre_period + "(" + period + ")";
  }
};
