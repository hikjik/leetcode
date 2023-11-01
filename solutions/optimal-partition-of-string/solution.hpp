#pragma once

#include <bitset>
#include <string>

/*
  2405. Optimal Partition of String
  https://leetcode.com/problems/optimal-partition-of-string/
  Difficulty: Medium
  Tags: Hash Table, String, Greedy
  Time:
  Space:
*/

class Solution {
public:
  static int partitionString(std::string s) {
    std::bitset<26> letters;
    int cnt = 1;
    for (auto c : s) {
      const auto index = c - 'a';
      if (letters[index]) {
        cnt++;
        letters.reset();
      }
      letters.set(index);
    }
    return cnt;
  }
};
