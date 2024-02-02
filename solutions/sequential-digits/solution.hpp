#pragma once

#include <string>
#include <vector>

// Time: O(1)
// Space: O(1)

class Solution {
public:
  static std::vector<int> sequentialDigits(int low, int high) {
    const std::string digits = "123456789";
    const auto lowLength = std::to_string(low).size();
    const auto highLength = std::to_string(high).size();

    std::vector<int> ans;
    for (auto length = lowLength; length <= highLength; ++length) {
      for (size_t i = 0; i + length <= digits.size(); ++i) {
        const auto num = std::stoi(digits.substr(i, length));
        if (low <= num && num <= high) {
          ans.push_back(num);
        }
      }
    }
    return ans;
  }
};
