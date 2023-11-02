#pragma once

#include <string>

// Time:
// Space:

class Solution {
public:
  static int minMaxDifference(int num) { return getMax(num) - getMin(num); }

private:
  static int getMax(int num) {
    auto str = std::to_string(num);
    if (auto pos = str.find_first_not_of('9'); pos != std::string::npos) {
      replace(str[pos], '9', &str);
    }
    return std::stoi(str);
  }

  static int getMin(int num) {
    auto str = std::to_string(num);
    replace(str[0], '0', &str);
    return std::stoi(str);
  }

  static void replace(char old_value, char new_value, std::string *str) {
    std::replace(str->begin(), str->end(), old_value, new_value);
  }
};
