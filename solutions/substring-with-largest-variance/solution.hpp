#pragma once

#include <algorithm>
#include <string>

/*
  2272. Substring With Largest Variance
  https://leetcode.com/problems/substring-with-largest-variance/
  Difficulty: Hard
  Tags: Array, Dynamic Programming
  Time:
  Space:
*/

class Solution {
public:
  static int largestVariance(std::string s) {
    int max_variance = 0;
    for (char a = 'a'; a <= 'z'; ++a) {
      for (char b = 'a'; b <= 'z'; ++b) {
        if (a != b) {
          max_variance = std::max(max_variance, largestVariance(s, a, b));
        }
      }
    }
    return max_variance;
  }

private:
  static int largestVariance(const std::string &s, char major, char minor) {
    int ans = 0;
    int cnt_major = 0, cnt_minor = 0;
    bool prev_minor = false;
    for (auto c : s) {
      if (c != major && c != minor) {
        continue;
      }
      c == major ? ++cnt_major : ++cnt_minor;
      if (cnt_minor) {
        ans = std::max(ans, cnt_major - cnt_minor);
      }
      if (!cnt_minor && prev_minor) {
        ans = std::max(ans, cnt_major - 1);
      }
      if (cnt_minor > cnt_major) {
        cnt_minor = cnt_major = 0;
        prev_minor = true;
      }
    }
    return ans;
  }
};
