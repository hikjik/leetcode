#pragma once

#include <map>
#include <string>

class Solution {
public:
  static std::string smallestSubsequence(const std::string &str) {
    std::map<char, size_t> right_most_position;
    for (size_t i = 0; i < str.size(); ++i) {
      right_most_position[str[i]] = i;
    }

    std::map<char, bool> used;

    std::string stack;
    stack.reserve(str.size());

    for (size_t i = 0; i < str.size(); ++i) {
      const auto letter = str[i];
      if (used[letter]) {
        continue;
      }

      while (!stack.empty() && stack.back() > letter &&
             right_most_position[stack.back()] > i) {
        used[stack.back()] = false;
        stack.pop_back();
      }

      stack.push_back(letter);
      used[letter] = true;
    }

    return stack;
  }
};
