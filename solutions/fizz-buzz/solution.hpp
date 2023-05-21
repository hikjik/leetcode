#pragma once

#include <string>
#include <vector>

class Solution {
public:
  static std::vector<std::string> fizzBuzz(int n) {
    std::vector<std::string> words;
    words.reserve(n);

    for (int i = 1; i <= n; ++i) {
      std::string word;
      if (i % 3 == 0) {
        word += "Fizz";
      }
      if (i % 5 == 0) {
        word += "Buzz";
      }
      words.push_back(word.empty() ? std::to_string(i) : word);
    }

    return words;
  }
};