#pragma once

#include <string>
#include <unordered_set>

// Time:
// Space:

class Solution {
public:
  static std::string longestNiceSubstring(std::string s) {
    std::unordered_set<char> set(s.begin(), s.end());
    for (int i = 0; i < std::ssize(s); ++i) {
      if (!set.contains(changeCase(s[i]))) {
        const auto s1 = longestNiceSubstring(s.substr(0, i)),
                   s2 = longestNiceSubstring(s.substr(i + 1));
        return s1.size() < s2.size() ? s2 : s1;
      }
    }
    return s;
  }

private:
  static char changeCase(char c) {
    return std::isupper(c) ? std::tolower(c) : std::toupper(c);
  }
};
