#pragma once

#include <string>
#include <vector>

class Solution {
public:
  static int minOperations(const std::vector<std::string> &logs) {
    int ops = 0;
    for (const auto &log : logs) {
      if (log[0] == '.' && log[1] == '.') {
        ops = ops ? ops - 1 : 0;
      } else if (log[0] != '.') {
        ++ops;
      }
    }
    return ops;
  }
};
