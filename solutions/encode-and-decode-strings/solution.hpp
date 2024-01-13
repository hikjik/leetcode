#pragma once

#include <cstring>
#include <string>
#include <vector>

// Time: O(N)
// Space: O(N)

class Codec {
public:
  static std::string encode(const std::vector<std::string> &strs) {
    std::string s;
    for (const auto &str : strs) {
      s += static_cast<unsigned char>(str.size());
      s += str;
    }
    return s;
  }

  static std::vector<std::string> decode(std::string s) {
    std::vector<std::string> strs;
    for (int i = 0; i < std::ssize(s);) {
      const auto size = static_cast<int>(static_cast<unsigned char>(s[i]));
      strs.push_back(s.substr(i + 1, size));
      i += size + 1;
    }
    return strs;
  }
};
