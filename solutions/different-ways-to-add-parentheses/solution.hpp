#pragma once

#include <string>
#include <unordered_map>
#include <vector>

// N <= 9
// Time: O(Cat(N))
// Space: O(N^2Cat(N))
// [Catalan number](https://w.wiki/845b)

class Solution {
public:
  static std::vector<int> diffWaysToCompute(std::string expression) {
    std::unordered_map<std::string, std::vector<int>> memo;
    return diffWaysToCompute(expression, &memo);
  }

  static std::vector<int>
  diffWaysToCompute(std::string s,
                    std::unordered_map<std::string, std::vector<int>> *memo) {
    if (s.empty()) {
      return {};
    }
    if (auto it = memo->find(s); it != memo->end()) {
      return it->second;
    }

    std::vector<int> values;
    for (int i = 0; i <= std::ssize(s); ++i) {
      if (std::ispunct(s[i])) {
        for (auto a : diffWaysToCompute(s.substr(0, i), memo)) {
          for (auto b : diffWaysToCompute(s.substr(i + 1), memo)) {
            if (s[i] == '*') {
              values.push_back(a * b);
            } else if (s[i] == '+') {
              values.push_back(a + b);
            } else if (s[i] == '-') {
              values.push_back(a - b);
            } else {
              throw;
            }
          }
        }
      }
    }
    if (values.empty()) {
      values.push_back(std::stoi(s));
    }
    return (*memo)[s] = values;
  }
};
