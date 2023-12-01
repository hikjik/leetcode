#pragma once

#include <ranges>
#include <string>
#include <unordered_map>
#include <vector>

// N is the number of words, K is the length of word
// A is the alphabet size
// Time: O(NK)
// Space: O(A)

using namespace std::placeholders;

class Solution {
public:
  static std::vector<std::string>
  findAndReplacePattern(const std::vector<std::string> &words,
                        std::string pattern) {
    std::vector<std::string> ans;
    std::ranges::copy_if(words, std::back_inserter(ans),
                         std::bind(isIsomorphic, _1, pattern));
    return ans;
  }

private:
  // 205. Isomorphic Strings
  // https://leetcode.com/problems/isomorphic-strings/description/
  static bool isIsomorphic(const std::string &s1, const std::string &s2) {
    std::unordered_map<char, int> map1, map2;
    for (int i = 0; i < std::ssize(s1); ++i) {
      if (map1[s1[i]] != map2[s2[i]]) {
        return false;
      }
      map1[s1[i]] = map2[s2[i]] = i + 1;
    }
    return true;
  }
};
