#pragma once

#include <sstream>
#include <string>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int compareVersion(std::string version1, std::string version2) {
    std::istringstream is1(version1), is2(version2);
    int num1 = 0, num2 = 0;
    while (static_cast<bool>(is1 >> num1) | static_cast<bool>(is2 >> num2)) {
      if (num1 != num2) {
        return num1 < num2 ? -1 : 1;
      }
      num1 = num2 = 0;

      char c;
      is1 >> c, is2 >> c;
    }
    return 0;
  }
};
