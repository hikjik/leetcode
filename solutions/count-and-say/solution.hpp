#pragma once

#include <string>

/*
  38. Count and Say
  https://leetcode.com/problems/count-and-say/
  Difficulty: Medium
  Tags: String
  Time: O(L^N), where L = 1.303577269034...
  Space: O(L^N)
  Notes: [Look and Say](https://w.wiki/7$3C)
*/

class Solution {
public:
  static std::string countAndSay(int n) {
    std::string s = "1";
    while (--n) {
      std::string t;
      for (size_t i = 0; i < s.size(); ++i) {
        int count = 1;
        for (; i + 1 < s.size() && s[i] == s[i + 1]; ++i) {
          ++count;
        }
        t += std::to_string(count) + s[i];
      }
      s.swap(t);
    }
    return s;
  }
};
