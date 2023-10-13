#pragma once

#include <sstream>
#include <string>

class Solution {
public:
  static int countSegments(std::string s) {
    std::stringstream sstream(s);
    int count = 0;
    for (std::string a; sstream >> a;) {
      ++count;
    }
    return count;
  }
};
