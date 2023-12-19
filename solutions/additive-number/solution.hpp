#pragma once

#include <string>

// Time: O(N^2)
// Space: O(N)

class Solution {
public:
  static bool isAdditiveNumber(std::string num) {
    const int n = num.size();
    for (int i = 0; i < n / 2; ++i) {
      if (i && num[0] == '0') {
        return false;
      }
      for (int j = i + 1; j + 1 < n; ++j) {
        if (j > i + 1 && num[i + 1] == '0') {
          break;
        }
        if (dfs(num.substr(0, i + 1), num.substr(i + 1, j - i),
                num.substr(j + 1))) {
          return true;
        }
      }
    }
    return false;
  }

private:
  static bool dfs(const std::string &num1, const std::string &num2,
                  const std::string &num) {
    if (num.empty()) {
      return true;
    }
    const auto num3 = addStrings(num1, num2);
    return num.starts_with(num3) && dfs(num2, num3, num.substr(num3.size()));
  }

  static std::string addStrings(const std::string &num1,
                                const std::string &num2) {
    std::string sum;
    int i = num1.size() - 1, j = num2.size() - 1;
    for (int carry = 0; i >= 0 || j >= 0 || carry; carry /= 10) {
      if (i >= 0) {
        carry += num1[i--] - '0';
      }
      if (j >= 0) {
        carry += num2[j--] - '0';
      }
      sum += '0' + carry % 10;
    }
    std::reverse(sum.begin(), sum.end());
    return sum;
  }
};
