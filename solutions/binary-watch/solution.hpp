#pragma once

#include <string>
#include <vector>

class Solution {
public:
  static std::vector<std::string> readBinaryWatch(int turnedOn) {
    std::vector<std::string> times;
    for (int h = 0; h < 12; ++h) {
      for (int m = 0; m < 60; ++m) {
        if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
          times.push_back(std::to_string(h) + (m < 10 ? ":0" : ":") +
                          std::to_string(m));
        }
      }
    }
    return times;
  }
};
