#pragma once

#include <string>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int
  finalValueAfterOperations(const std::vector<std::string> &operations) {
    int x = 0;
    for (const auto &op : operations) {
      x += op[1] == '+' ? 1 : -1;
    }
    return x;
  }
};
