#pragma once

#include <vector>

class Solution {
public:
  static std::vector<int> decode(const std::vector<int> &encoded, int first) {
    std::vector<int> arr{first};
    for (auto a : encoded) {
      arr.push_back(a ^ arr.back());
    }
    return arr;
  }
};
