#pragma once

#include <string>
#include <vector>

/*
  22. Generate Parentheses
  https://leetcode.com/problems/generate-parentheses/
  Difficulty: Medium
  Tags: String, Dynamic Programming, Backtracking
  Time:
  Space:
*/

class Solution {
private:
  static void generateParenthesis(int n, int opened,
                                  std::vector<std::string> *combinations,
                                  std::string *combination) {
    const int length = combination->size();
    if (length == 2 * n) {
      combinations->push_back(*combination);
      return;
    }

    if (opened < n) {
      combination->push_back('(');
      generateParenthesis(n, opened + 1, combinations, combination);
      combination->pop_back();
    }
    if (2 * opened > length) {
      combination->push_back(')');
      generateParenthesis(n, opened, combinations, combination);
      combination->pop_back();
    }
  }

public:
  static std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> combinations;
    std::string combination;
    generateParenthesis(n, 0, &combinations, &combination);
    return combinations;
  }
};
