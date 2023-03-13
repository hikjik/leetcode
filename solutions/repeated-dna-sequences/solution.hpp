#pragma once

#include <bitset>
#include <string>
#include <vector>

class Solution {
public:
  static std::vector<std::string> findRepeatedDnaSequences(std::string s) {
    if (s.size() < 10) {
      return {};
    }

    std::vector<std::string> repeated_sequences;
    std::bitset<1 << 20> repeated;
    std::bitset<1 << 20> seen;

    int hash = 0;
    for (size_t i = 0; i < 9; ++i) {
      hash = (hash << 2) | convert(s[i]);
    }

    for (size_t i = 9; i < s.size(); ++i) {
      hash = (hash << 2) | convert(s[i]);
      hash &= 0xFFFFF;

      if (repeated[hash]) {
        continue;
      }

      if (seen[hash]) {
        repeated_sequences.push_back(s.substr(i - 9, 10));
        repeated.set(hash);
      }
      seen.set(hash);
    }

    return repeated_sequences;
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
