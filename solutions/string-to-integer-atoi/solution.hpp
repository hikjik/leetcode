#pragma once

#include <climits>
#include <sstream>
#include <string>

// Time: O(N)
// Space: O(1)

namespace stl {

class Solution {
public:
  static int myAtoi(std::string s) {
    std::stringstream stream(s);
    int number;
    stream >> number;
    return number;
  }
};

} // namespace stl

namespace iterative {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static int myAtoi(std::string s) {
    std::string_view sv(s);

    const auto pos = sv.find_first_not_of(' ');
    if (pos == std::string::npos) {
      return 0;
    }
    sv = sv.substr(pos);

    const auto sign = sv[0] == '-' ? -1 : 1;
    if (sv[0] == '-' || sv[0] == '+') {
      sv = sv.substr(1);
    }

    long long num = 0;
    for (auto c : sv) {
      if (!std::isdigit(c)) {
        break;
      }
      num = num * 10 + (c - '0');
      if (sign * num < INT_MIN) {
        return INT_MIN;
      }
      if (sign * num > INT_MAX) {
        return INT_MAX;
      }
    }
    return sign * num;
  }
};

} // namespace iterative
