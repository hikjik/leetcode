#pragma once

#include <string>
#include <vector>

class Solution {
public:
  static int numDecodings(std::string str) {
    std::vector<int> dp(str.size(), -1);
    return numDecodings(0, str, &dp);
  }

private:
  static int numDecodings(size_t pos, const std::string &str,
                          std::vector<int> *dp) {
    if (pos == str.size()) {
      return 1;
    }

    auto &total = (*dp)[pos];
    if (total == -1) {
      total = 0;

      if (str[pos] != '0') {
        total += numDecodings(pos + 1, str, dp);
      }

      if (pos < str.size() - 1) {
        int k = std::atoi(str.substr(pos, 2).c_str());
        if (10 <= k && k <= 26) {
          total += numDecodings(pos + 2, str, dp);
        }
      }
    }

    return total;
  }
};
