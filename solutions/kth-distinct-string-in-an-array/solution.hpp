#pragma once

#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  static std::string kthDistinct(const std::vector<std::string> &arr, int k) {
    std::unordered_map<std::string, int> map;
    for (const auto &str : arr) {
      ++map[str];
    }

    for (const auto &str : arr) {
      if (map[str] == 1 && !--k) {
        return str;
      }
    }
    return "";
  }
};
