#pragma once

#include <string>

class Solution {
public:
  static std::string minRemoveToMakeValid(std::string s) {
    int left = 0, right = std::count(s.begin(), s.end(), ')');

    std::string valid;
    for (size_t i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        if (right) {
          right--;
          left++;
          valid.push_back(s[i]);
        }
      } else if (s[i] == ')') {
        if (left) {
          left--;
          valid.push_back(s[i]);
        } else {
          right--;
        }
      } else {
        valid.push_back(s[i]);
      }
    }
    return valid;
  }
};
