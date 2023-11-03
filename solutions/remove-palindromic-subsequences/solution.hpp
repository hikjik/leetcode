#pragma once

#include <algorithm>
#include <string>

// Time:
// Space:

class Solution {
public:
  static int removePalindromeSub(std::string s) {
    return 2 - std::equal(s.cbegin(), s.cbegin() + s.size() / 2, s.crbegin());
  }
};
