#pragma once

#include <unordered_map>
#include <vector>

class Solution {
public:
  static std::vector<int> findLonely(const std::vector<int> &numbers) {
    std::unordered_map<int, int> freq;
    for (auto number : numbers) {
      freq[number]++;
    }

    std::vector<int> lonely_numbers;
    lonely_numbers.reserve(numbers.size());
    for (auto number : numbers) {
      if (freq[number] == 1 && !freq[number + 1] && !freq[number - 1]) {
        lonely_numbers.push_back(number);
      }
    }
    return lonely_numbers;
  }
};
