#pragma once

#include <regex>
#include <string>

// Time: O(N)
// Space: O(1)

namespace re {

class Solution {
public:
  static bool isNumber(std::string s) {
    static const std::regex regex(R"([-+]?(\d+\.?\d*|\.\d+)([eE][-+]?\d+)?)");
    return std::regex_match(s, regex);
  }
};

} // namespace re

namespace iterative {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static bool isNumber(std::string s) {
    bool has_num = false, has_dot = false, has_e = false;
    for (int i = 0; i < std::ssize(s); ++i) {
      if (s[i] == 'e' || s[i] == 'E') {
        if (has_e || !has_num) {
          return false;
        }
        has_e = true, has_num = false;
      } else if (s[i] == '-' || s[i] == '+') {
        if (i && s[i - 1] != 'e' && s[i - 1] != 'E') {
          return false;
        }
      } else if (s[i] == '.') {
        if (has_dot || has_e) {
          return false;
        }
        has_dot = true;
      } else if (std::isdigit(s[i])) {
        has_num = true;
      } else {
        return false;
      }
    }
    return has_num;
  }
};

} // namespace iterative
