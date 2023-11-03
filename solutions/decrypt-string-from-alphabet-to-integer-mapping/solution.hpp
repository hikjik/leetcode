#pragma once

#include <string>

// Time:
// Space:

class Solution {
public:
  static std::string freqAlphabets(std::string str) {
    std::string decrypted;

    int m = str.size() - 1;
    while (m >= 0) {
      int pos;
      if (str[m] == SEPARATOR) {
        pos = std::atoi(str.substr(m - 2, 2).c_str());
        m -= 3;
      } else {
        pos = std::atoi(str.substr(m, 1).c_str());
        --m;
      }
      decrypted += ALPHABET[pos - 1];
    }

    std::reverse(decrypted.begin(), decrypted.end());
    return decrypted;
  }

private:
  static const char SEPARATOR = '#';
  static inline const std::string ALPHABET = "abcdefghijklmnopqrstuvwxyz";
};
