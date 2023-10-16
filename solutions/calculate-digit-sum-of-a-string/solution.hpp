#pragma once

#include <string>

class Solution {
public:
  static std::string digitSum(std::string s, size_t k) {
    while (s.size() > k) {
      std::string t;
      for (size_t i = 0; i < s.size(); i += k) {
        int digits_sum = 0;
        for (size_t j = 0; j < k && i + j < s.size(); ++j) {
          digits_sum += s[i + j] - '0';
        }
        t += std::to_string(digits_sum);
      }
      s.swap(t);
    }
    return s;
  }
};
