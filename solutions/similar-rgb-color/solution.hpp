#pragma once

#include <cmath>
#include <iomanip>
#include <sstream>
#include <string>

// Time: O(1)
// Space: O(1)

class Solution {
public:
  static std::string similarRGB(std::string color) {
    std::string ans = "#";
    for (int i = 1; i < std::ssize(color); i += 2) {
      ans += similar(color.substr(i, 2));
    }
    return ans;
  }

private:
  static std::string similar(std::string hex) {
    const int num = std::stoi(hex, nullptr, 16);
    const int x = std::round(num / 17.0);

    std::ostringstream sstream;
    sstream << std::hex << x;
    return sstream.str() + sstream.str();
  }
};
