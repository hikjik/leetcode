#pragma once

#include <string>
#include <vector>

class Solution {
public:
  static std::string convert(std::string s, int num_rows) {
    std::vector<std::vector<char>> rows(num_rows);
    int i = 0, d = num_rows == 1 ? 0 : -1;
    for (auto c : s) {
      rows[i].push_back(c);
      if (i == 0 || i == num_rows - 1) {
        d *= -1;
      }
      i += d;
    }

    std::string ans;
    for (const auto &row : rows) {
      for (auto c : row) {
        ans += c;
      }
    }
    return ans;
  }
};
