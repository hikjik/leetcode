#pragma once

#include <algorithm>
#include <string>
#include <string_view>
#include <vector>

// Time: O(N2^N)
// Space: O(N)

class Solution {
public:
  static std::vector<std::vector<std::string>> partition(std::string s) {
    std::vector<std::string> partition;
    std::vector<std::vector<std::string>> partitions;
    dfs(std::string_view(s), &partition, &partitions);
    return partitions;
  }

private:
  static void dfs(std::string_view s, std::vector<std::string> *partition,
                  std::vector<std::vector<std::string>> *partitions) {
    if (s.empty()) {
      partitions->push_back(*partition);
    }
    for (int i = 1; i <= std::ssize(s); ++i) {
      if (isPalindrome(s.substr(0, i))) {
        partition->emplace_back(s.substr(0, i));
        dfs(s.substr(i), partition, partitions);
        partition->pop_back();
      }
    }
  }

  static bool isPalindrome(std::string_view s) {
    return std::equal(s.cbegin(), s.cbegin() + s.size() / 2, s.crbegin());
  }
};
