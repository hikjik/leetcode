#pragma once

#include <string>
#include <vector>

/*
  438. Find All Anagrams in a String
  https://leetcode.com/problems/find-all-anagrams-in-a-string/
  Difficulty: Medium
  Tags: Hash Table, String, Sliding Window
  Time:
  Space:
*/

class Solution {
public:
  static const int ALPHABET_SIZE = 26;

  static std::vector<int> findAnagrams(std::string s, std::string p) {
    if (s.size() < p.size()) {
      return {};
    }

    std::vector<int> letters(ALPHABET_SIZE, 0);
    for (size_t i = 0; i < p.size(); ++i) {
      letters[p[i] - 'a']++;
    }

    std::vector<int> window(ALPHABET_SIZE, 0);
    for (size_t i = 0; i < p.size() - 1; ++i) {
      window[s[i] - 'a']++;
    }

    std::vector<int> anagrams;
    for (size_t i = p.size() - 1; i < s.size(); ++i) {
      window[s[i] - 'a']++;

      if (letters == window) {
        anagrams.push_back(i - p.size() + 1);
      }

      window[s[i - p.size() + 1] - 'a']--;
    }
    return anagrams;
  }
};
