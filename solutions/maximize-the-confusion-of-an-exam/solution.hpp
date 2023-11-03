#pragma once

#include <algorithm>
#include <string>

// Time:
// Space:

class Solution {
public:
  static int maxConsecutiveAnswers(std::string answer_key, size_t k) {
    size_t zeros = 0, ones = 0;
    size_t start = 0, ans = 0;
    for (size_t i = 0; i < answer_key.size(); ++i) {
      answer_key[i] == 'T' ? ++ones : ++zeros;
      while (std::min(ones, zeros) > k) {
        answer_key[start++] == 'T' ? --ones : --zeros;
      }
      ans = std::max(ans, i - start + 1);
    }
    return ans;
  }
};
