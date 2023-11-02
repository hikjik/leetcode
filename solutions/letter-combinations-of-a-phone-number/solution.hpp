#pragma once

#include <array>
#include <string>
#include <vector>

// Time: O(N4^N)
// Space: O(N)

namespace backtracking {

// Time: O(N4^N)
// Space: O(N)
class Solution {
public:
  static std::vector<std::string> letterCombinations(std::string digits) {
    if (digits.empty()) {
      return {};
    }

    std::vector<std::string> combinations;
    std::string combination;
    letterCombinations(0, digits, &combinations, &combination);
    return combinations;
  }

private:
  static void letterCombinations(size_t i, const std::string &digits,
                                 std::vector<std::string> *combinations,
                                 std::string *combination) {
    static const std::array<std::string, 10> digit2letters{
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    if (i == digits.size()) {
      combinations->push_back(*combination);
      return;
    }

    for (auto letter : digit2letters[digits[i] - '0']) {
      combination->push_back(letter);
      letterCombinations(i + 1, digits, combinations, combination);
      combination->pop_back();
    }
  }
};

} // namespace backtracking

namespace iterative {

// Time: O(N4^N)
// Space: O(4^N)
class Solution {
public:
  static std::vector<std::string> letterCombinations(std::string digits) {
    static const std::array<std::string, 10> digit2letters{
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    if (digits.empty()) {
      return {};
    }

    std::vector<std::string> combinations{""};
    for (auto digit : digits) {
      std::vector<std::string> temp;
      for (const auto &combination : combinations) {
        for (auto c : digit2letters[digit - '0']) {
          temp.push_back(combination + c);
        }
      }
      combinations.swap(temp);
    }
    return combinations;
  }
};

} // namespace iterative
