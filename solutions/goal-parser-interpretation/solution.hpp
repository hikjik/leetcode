#pragma once

#include <string>

/*
  1678. Goal Parser Interpretation
  https://leetcode.com/problems/goal-parser-interpretation/
  Difficulty: Easy
  Tags: String
  Time:
  Space:
*/

class Solution {
public:
  static std::string interpret(std::string command) {
    std::string parsed;
    parsed.reserve(command.size());

    for (size_t i = 0; i < command.size(); ++i) {
      switch (command[i]) {
      case 'G':
        parsed += 'G';
        break;
      case '(':
        if (command[i + 1] == ')') {
          parsed += 'o';
        } else {
          parsed += "al";
        }
        break;
      default:
        break;
      }
    }
    return parsed;
  }
};