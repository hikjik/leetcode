#pragma once

#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  static int countSeniors(const std::vector<std::string> &details) {
    return std::count_if(details.begin(), details.end(), [](const auto &s) {
      return (s[11] - '0') * 10 + s[12] - '0' > 60;
    });
  }
};
