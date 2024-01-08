#pragma once

#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

// Time: O(NK)
// Space: O(NK)

class Solution {
private:
  static std::string shift(const std::string &s) {
    std::string t(s.size() - 1, 'a');
    for (size_t i = 0; i + 1 < s.size(); ++i) {
      t[i] += (s[i + 1] - s[i] + 26) % 26;
    }
    return t;
  }

public:
  static std::vector<std::vector<std::string>>
  groupStrings(const std::vector<std::string> &strs) {
    std::unordered_map<std::string, std::vector<std::string>> groups;
    for (const auto &s : strs) {
      groups[shift(s)].push_back(s);
    }

    std::vector<std::vector<std::string>> ans;
    for (auto &[_, group] : groups) {
      ans.push_back(std::move(group));
    }
    return ans;
  }
};
