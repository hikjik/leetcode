#pragma once

#include <string>
#include <unordered_map>
#include <vector>

class Solution {
private:
  static const inline std::unordered_map<char, std::string> digit2letters{
      {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
      {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

  static void letterCombinations(size_t i, const std::string &digits,
                                 std::vector<std::string> *combinations,
                                 std::string *combination) {
    if (i == digits.size()) {
      combinations->push_back(*combination);
      return;
    }

    for (auto letter : digit2letters.at(digits[i])) {
      combination->push_back(letter);
      letterCombinations(i + 1, digits, combinations, combination);
      combination->pop_back();
    }
  }

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
};
