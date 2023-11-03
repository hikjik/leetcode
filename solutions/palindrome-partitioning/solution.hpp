#pragma once

#include <string>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<std::vector<std::string>> partition(std::string s) {
    std::vector<std::vector<std::string>> partitions;
    std::vector<std::string> partition;
    dfs(0, s, &partitions, &partition);
    return partitions;
  }

private:
  static void dfs(size_t start, const std::string &s,
                  std::vector<std::vector<std::string>> *partitions,
                  std::vector<std::string> *partition) {
    if (start == s.size()) {
      partitions->push_back(*partition);
    }

    for (auto end = start; end < s.size(); ++end) {
      if (isPalindrome(s, start, end)) {
        partition->push_back(s.substr(start, end - start + 1));
        dfs(end + 1, s, partitions, partition);
        partition->pop_back();
      }
    }
  }

  static bool isPalindrome(const std::string &s, size_t start, size_t end) {
    while (start < end) {
      if (s[start++] != s[end--]) {
        return false;
      }
    }
    return true;
  }
};
