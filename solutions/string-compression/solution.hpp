#pragma once

#include <string>
#include <vector>

/*
  443. String Compression
  https://leetcode.com/problems/string-compression/
  Difficulty: Medium
  Tags: Two Pointers, String
  Time:
  Space:
*/

class Solution {
public:
  static int compress(std::vector<char> &chars) {
    int n = chars.size();

    int left = 0, right = 0;
    while (right < n) {
      chars[left] = chars[right];
      int cnt = 0;
      while (right < n && chars[left] == chars[right]) {
        right++;
        cnt++;
      }
      ++left;
      if (cnt > 1) {
        for (auto c : std::to_string(cnt)) {
          chars[left++] = c;
        }
      }
    }
    return left;
  }
};
