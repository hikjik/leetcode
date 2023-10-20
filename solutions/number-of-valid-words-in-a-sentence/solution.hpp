#pragma once

#include <iterator>
#include <sstream>
#include <string>

class Solution {
public:
  static int countValidWords(std::string sentence) {
    std::istringstream stream(sentence);
    return std::count_if(std::istream_iterator<std::string>(stream),
                         std::istream_iterator<std::string>(),
                         [](const auto &token) { return isValid(token); });
  }

private:
  static bool isValid(const std::string &token) {
    const int n = token.size();
    for (int index = 0, hyphens = 0; index < n; ++index) {
      const auto c = token[index];
      if (std::isdigit(c)) {
        return false;
      }
      if (c == '-') {
        if (hyphens++ || index == 0 || index == n - 1 ||
            !std::isalpha(token[index - 1]) ||
            !std::isalpha(token[index + 1])) {
          return false;
        }
      }
      if (c == '!' || c == '.' || c == ',') {
        if (index != n - 1) {
          return false;
        }
      }
    }
    return true;
  }
};
