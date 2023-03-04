#pragma once

#include <string>
#include <vector>

class Solution {
public:
  static std::string longestCommonPrefix(const std::vector<std::string> &strs) {
    size_t j = 0;
    while (isEqual(j, strs)) {
      ++j;
    }
    return strs.front().substr(0, j);
  }

private:
  static bool isEqual(size_t j, const std::vector<std::string> &strs) {
    for (const auto &str : strs) {
      if (str.size() <= j || str[j] != strs.front()[j]) {
        return false;
      }
    }
    return true;
  }
};
