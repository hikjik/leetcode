#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<double> convertTemperature(double celsius) {
    const auto kelvin = celsius + 273.15;
    const auto fahrenheit = celsius * 1.80 + 32.00;
    return {kelvin, fahrenheit};
  }
};
