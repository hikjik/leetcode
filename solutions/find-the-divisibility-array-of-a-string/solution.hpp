#pragma once

#include <string>
#include <vector>

class Solution {
public:
  static std::vector<int> divisibilityArray(std::string word, int m) {
    std::vector<int> divisibility_array(word.size(), 0);

    long long sum = 0;
    for (size_t i = 0; i < word.size(); ++i) {
      sum %= m;
      sum = sum * 10 + word[i] - '0';
      if (sum % m == 0) {
        divisibility_array[i] = 1;
      }
    }

    return divisibility_array;
  }
};
