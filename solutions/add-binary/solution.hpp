#pragma once

#include <algorithm>
#include <string>

// Time: O(max(N, M))
// Space: O(1)

class Solution {
public:
  static std::string addBinary(std::string a, std::string b) {
    std::string ans;
    ans.reserve(std::max(a.size(), b.size()) + 1);

    int i = a.size() - 1, j = b.size() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0 || carry) {
      carry += (i >= 0 ? a[i--] - '0' : 0) + (j >= 0 ? b[j--] - '0' : 0);
      ans += '0' + carry % 2;
      carry /= 2;
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
  }
};
