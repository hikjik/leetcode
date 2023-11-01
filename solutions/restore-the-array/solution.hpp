#pragma once

#include <string>
#include <vector>

/*
  1416. Restore The Array
  https://leetcode.com/problems/restore-the-array/
  Difficulty: Hard
  Tags: String, Dynamic Programming
  Time:
  Space:
*/

class Solution {
private:
  static const int kMod = 1e9 + 7;

public:
  static int numberOfArrays(std::string s, int k) {
    std::vector<int> dp(s.size(), -1);
    return numberOfArrays(0, s, k, &dp);
  }

private:
  static int numberOfArrays(size_t i, const std::string &s, int k,
                            std::vector<int> *dp) {
    if (i == s.size()) {
      return 1;
    }
    if (s[i] == '0') {
      return 0;
    }

    auto &cnt = (*dp)[i];
    if (cnt != -1) {
      return cnt;
    }
    cnt = 0;

    long long num = 0;
    for (size_t j = i; j < s.size(); ++j) {
      num = num * 10 + (s[j] - '0');
      if (num > k) {
        break;
      }
      cnt = (cnt + numberOfArrays(j + 1, s, k, dp)) % kMod;
    }
    return cnt;
  }
};
