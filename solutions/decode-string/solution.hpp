#pragma once

#include <stack>
#include <string>

/*
  394. Decode String
  https://leetcode.com/problems/decode-string/
  Difficulty: Medium
  Tags: String, Stack, Recursion
  Time:
  Space:
*/

class Solution {
public:
  static std::string decodeString(std::string str) {
    std::stack<std::pair<std::string, int>> stack;
    int repeats = 0;
    std::string current;
    for (auto c : str) {
      if (std::isdigit(c)) {
        repeats = repeats * 10;
        repeats += c - '0';
      } else if (c == '[') {
        stack.emplace(current, repeats);
        repeats = 0;
        current = "";
      } else if (c == ']') {
        auto [previous, repeats] = stack.top();
        stack.pop();

        current.swap(previous);
        while (repeats--) {
          current += previous;
        }
      } else {
        current += c;
      }
    }
    return current;
  }
};
