#pragma once

#include <iomanip>
#include <sstream>
#include <string>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static std::string toHexspeak(std::string num) {
    std::ostringstream ostream;
    ostream << std::hex << std::uppercase << std::stoll(num);

    auto ans = ostream.str();
    for (auto &c : ans) {
      if (c >= '2' && c <= '9') {
        return "ERROR";
      }
      if (c == '1') {
        c = 'I';
      } else if (c == '0') {
        c = 'O';
      }
    }
    return ans;
  }
};
