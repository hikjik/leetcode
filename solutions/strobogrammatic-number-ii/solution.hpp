#pragma once

#include <string>
#include <vector>

// Time: O(N5^N)
// Space: O(N5^N)

class Solution {
public:
  static std::vector<std::string> findStrobogrammatic(int n, int m = 0) {
    if (n == 0) {
      return {""};
    }
    if (n == 1) {
      return {"0", "1", "8"};
    }
    std::vector<std::string> ans;
    for (const auto &num : findStrobogrammatic(n - 2, 1)) {
      ans.push_back("1" + num + "1");
      ans.push_back("8" + num + "8");
      ans.push_back("6" + num + "9");
      ans.push_back("9" + num + "6");
      if (m) {
        ans.push_back("0" + num + "0");
      }
    }
    return ans;
  }
};
