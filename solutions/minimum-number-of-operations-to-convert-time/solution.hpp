#pragma once

#include <string>

// Time:
// Space:

class Solution {
public:
  static int convertTime(std::string current, std::string correct) {
    int diff = std::abs(toMinutes(current) - toMinutes(correct));
    int ops = 0;
    for (auto d : {60, 15, 5, 1}) {
      ops += diff / d;
      diff %= d;
    }
    return ops;
  }

private:
  static int toMinutes(std::string time) {
    return std::stoi(time.substr(0, 2)) * 60 + std::stoi(time.substr(3));
  }
};
