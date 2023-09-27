#pragma once

#include <cctype>
#include <string>

class Solution {
public:
  static std::string decodeAtIndex(std::string s, int k) {
    long long length = 0;
    for (auto c : s) {
      if (std::isalpha(c)) {
        ++length;
      } else {
        length *= c - '0';
      }
    }

    for (int i = s.size() - 1; i >= 0; --i) {
      k %= length;

      if (!k && std::isalpha(s[i])) {
        return s.substr(i, 1);
      }

      if (std::isalpha(s[i])) {
        --length;
      } else {
        length /= s[i] - '0';
      }
    }

    throw;
  }
};
