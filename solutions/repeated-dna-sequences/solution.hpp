#pragma once

#include <bitset>
#include <string>
#include <vector>

// N is the length of the string s, K = 10
// Time: O(NK)
// Space: O(4^K/W) W is the internal representation bitset, 32 or 64 bits

class Solution {
public:
  static std::vector<std::string> findRepeatedDnaSequences(std::string s) {
    std::vector<std::string> ans;
    std::bitset<1 << 20> seen, repeated;
    for (int i = 0, hash = 0; i < std::ssize(s); ++i) {
      hash = hash << 2 | convert(s[i]);
      hash &= 0xfffff;

      if (i < 9 || repeated.test(hash)) {
        continue;
      }

      if (seen.test(hash)) {
        ans.push_back(s.substr(i - 9, 10));
        repeated.set(hash);
      }
      seen.set(hash);
    }
    return ans;
  }

private:
  static int convert(char c) {
    switch (c) {
    case 'A':
      return 0;
    case 'C':
      return 1;
    case 'G':
      return 2;
    case 'T':
      return 3;
    default:
      throw;
    }
  }
};
