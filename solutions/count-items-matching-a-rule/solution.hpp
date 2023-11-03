#pragma once

#include <string>
#include <unordered_map>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int countMatches(const std::vector<std::vector<std::string>> &items,
                          std::string ruleKey, std::string ruleValue) {
    static const std::unordered_map<std::string, int> kRuleKeyMap{
        {"type", 0},
        {"color", 1},
        {"name", 2},
    };

    const int idx = kRuleKeyMap.at(ruleKey);
    return std::count_if(items.begin(), items.end(), [&](const auto &item) {
      return item[idx] == ruleValue;
    });
  }
};
