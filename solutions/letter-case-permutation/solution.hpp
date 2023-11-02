#pragma once

#include <string>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<std::string> letterCasePermutation(std::string original) {
    std::vector<std::string> permutations;
    std::string str;
    letterCasePermutation(original, &str, &permutations);
    return permutations;
  }

private:
  static void letterCasePermutation(const std::string &original,
                                    std::string *str,
                                    std::vector<std::string> *permutations) {
    size_t i = str->size();
    if (i == original.size()) {
      permutations->push_back(*str);
      return;
    }

    str->push_back(original[i]);
    letterCasePermutation(original, str, permutations);
    str->pop_back();

    if (!std::isdigit(original[i])) {
      str->push_back(changeCase(original[i]));
      letterCasePermutation(original, str, permutations);
      str->pop_back();
    }
  }

  static char changeCase(char c) {
    if (std::islower(c)) {
      return std::toupper(c);
    }
    return std::tolower(c);
  }
};
